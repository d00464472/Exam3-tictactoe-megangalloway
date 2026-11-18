all: tic-tac-toe

tic-tac-toe: main.o Game.o Board.o
	g++ main.o Game.o Board.o -o tic-tac-toe

main.o: main.cpp Game.h
	g++ -c main.cpp -o main.o

Game.o: Game.cpp Game.h Board.h
	g++ -c Game.cpp -o Game.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp -o Board.o

clean:
	rm -f *.o tic-tac-toe
