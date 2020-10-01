monopoly: intro.o main.o user.o account.o player.o game.o
	g++ intro.o main.o user.o account.o player.o game.o -o monopoly

intro.o: intro.cpp
	g++ -c intro.cpp

main.o: main.cpp
	g++ -c main.cpp

user.o: user.cpp
	g++ -c user.cpp

account.o: account.cpp
	g++ -c account.cpp

player.o: player.cpp 
	g++ -c player.cpp

game.o: game.cpp
	g++ -c game.cpp

clean:
	rm -f *.o monopoly

reset:
	rm -f *.o monopoly *.txt

all:
	g++ intro.cpp main.cpp user.cpp account.cpp player.cpp game.cpp -o monopoly
