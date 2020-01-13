all: picasino

picasino: src/picasino.cpp
	g++ src/picasino.cpp -o bin/picasino
