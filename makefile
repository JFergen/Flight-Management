sum: Plane.o Planes.o Crew.o Crews.o Flight.o Flights.o
	gcc -o sum Plane.o Planes.o Crew.o Crews.o Flight.o Flights.o

Plane.o: Plane.cpp Plane.h
	gcc -c Plane.cpp

Planes.o: Plane.cpp Plane.h
	gcc -c Planes.cpp

Crew.o: Crew.cpp Crew.h
	gcc -c Crew.cpp

Crews.o: Crews.cpp Crews.h
	gcc -c Crews.cpp

Flight.o: Flight.cpp Flight.h
	gcc -c Flight.cpp

Flights.o: Flights.cpp Flight.h Crews.h Planes.h
	gcc -c Flights.cpp

clean:
	rm *.o sum

run:
	./sum

