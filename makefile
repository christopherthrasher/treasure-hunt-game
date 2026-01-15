treasurehunt: main.o board.o trap.o treasure.o player.o user.o ai.o helpers.o
	g++ -o treasurehunt main.o board.o trap.o treasure.o player.o user.o ai.o helpers.o

main.o: main.cpp
	g++ -c main.cpp

board.o: board.h board.cpp
	g++ -c board.cpp

trap.o: trap.h trap.cpp
	g++ -c trap.cpp

treasure.o: treasure.h treasure.cpp
	g++ -c treasure.cpp

player.o: player.h player.cpp
	g++ -c player.cpp

user.o: user.h user.cpp
	g++ -c user.cpp

ai.o: ai.h ai.cpp
	g++ -c ai.cpp

helpers.o: helpers.h helpers.cpp
	g++ -c helpers.cpp

clean:
	rm *.o treasurehunt
