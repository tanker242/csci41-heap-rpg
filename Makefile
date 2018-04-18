opt =  -Og -g
std = -std=c++17

a.out: Entity.o main.o
	g++ -Weffc++ $(opt) $(std) Entity.o main.o

Entity.o: Entity.h Entity.cc
	g++ -Weffc++ -c $(opt) $(std) Entity.cc

main.o: Entity.h main.cc
	g++ -Weffc++ -c $(opt) $(std)  main.cc

clean:
	rm -f a.out core *.o
		
