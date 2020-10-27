monopoly: intro.o main.o user.o player.o game.o file.o account.o
	g++ intro.o main.o user.o player.o game.o file.o account.o -o monopoly

intro.o: intro.cpp
	g++ -c intro.cpp

main.o: main.cpp
	g++ -c main.cpp

user.o: user.cpp
	g++ -c user.cpp

player.o: player.cpp 
	g++ -c player.cpp

game.o: game.cpp
	g++ -c game.cpp

file.o: file.cpp
	g++ -c file.cpp

account.o : account.cpp
	g++ -c account.cpp

clean:
	rm -f *.o monopoly

reset:
	rm -f *.o monopoly *.txt

all:
	g++ intro.cpp main.cpp user.cpp player.cpp game.cpp file.cpp account.cpp -o monopoly
