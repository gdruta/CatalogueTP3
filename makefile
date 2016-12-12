OBJS=test1.o Trajet.o TrajetSimple.o Collection.o TrajetCompose.o Catalogue.o
CC=g++
DEBUG=-g
CFLAGS=-c -Wall # -DMAP
LFLAGS=-Wall

test:$(OBJS)
	g++ $(LFLAGS) $(OBJS) -o test
test1.o: test1.cpp 
	g++ $(CFLAGS) test1.cpp
Trajet.o: Trajet.cpp
	g++ $(CFLAGS) Trajet.cpp
TrajetSimple.o: TrajetSimple.cpp
	g++ $(CFLAGS) TrajetSimple.cpp
Collection.o: Collection.cpp
	g++ $(CFLAGS) Collection.cpp
TrajetCompose.o: TrajetCompose.cpp
	g++ $(CFLAGS) TrajetCompose.cpp
Catalogue.o: Catalogue.cpp
	g++ $(CFLAGS) Catalogue.cpp
.PHONY:clean
clean:
	rm -f *.o test