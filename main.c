//#include
#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>
#include <math.h>
#include <unistd.h>
#define PCF 120
#define IR 0
#define RELAY 2
int armed=0;
#define threshold 31
float root(float n) {
    n=1.0f/n;
    long i;
    float x, y;
    x=n*0.5f;
    y=n;
    i=*(long*)&y;
    i=0x5f3759df-(i>>1);
    y=*(float*)&i;
    y=y*(1.5f-(x*y*y));
    return y;
}
void trigger(){
	armed^=1;
	printf("ARM v%i\n",armed);
	delay(250);
}
int sound_detect(){
	int temp;
	int store=0;
	float out;
	for(int k=0;k<100;k++){
		temp=analogRead(PCF+0)-127;
		store+=temp*temp;
	}
	out=store;
	out/=100;
	out=root(out);
	return (out>threshold);
}
int main(){
	int alarm=0;
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	if(wiringPiISR(IR, INT_EDGE_FALLING, &trigger) == -1){
		printf("setup ISR failed !");
		return 1;
			digitalWrite(RELAY,LOW);
	}
	pcf8591Setup (PCF, 0x48);
	digitalWrite(RELAY,HIG);
	while(1){
		//armed^=ir_detect();
		if(armed&&!alarm) alarm=sound_detect();
		if(armed&&alarm){
			printf("INTRUDER ALERT! RED SPY IS IN BASE");
			digitalWrite(RELAY,LOW);
			delay(50)
			alarm=0;
			digitalWrite(RELAY,HIGH);
			delay(19950);
		}
		delay(1);
		//usleep(100);
	}
}
