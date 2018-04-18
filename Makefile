a.out: Entity.o main.o
	g++ -O1 -Weffc++ -c -g -std=c++17 Entity.o main.o

Entity.o: Entity.h Entity.cc
	g++ -O1 -Weffc++ -c -g -std=c++17 Entity.cc

main.o: Entity.h main.cc
	g++ -O1 -Weffc++ -c -g -std=c++17 main.cc

clean:
	rm -f a.out core *.o
		
