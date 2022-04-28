# MAkefile

CC = g++
CFLAGS = -O3 -Wall

.PHONY: all
all: blockchain

blockchain: time.o sha256.o block.o bitcoin.o main.o
	$(CC) $(CFLAGS) -o $@ time.o sha256.o block.o bitcoin.o main.o

time.o: ./source/time.cpp ./header/time.hpp
	$(CC) $(CFLAGS) -o $@ -c ./source/time.cpp

sha256.o: ./source/sha256.cpp ./header/sha256.hpp
	$(CC) $(CFLAGS) -o $@ -c ./source/sha256.cpp

block.o: ./source/block.cpp ./header/block.hpp ./header/sha256.hpp ./header/time.hpp
	$(CC) $(CFLAGS) -o $@ -c ./source/block.cpp

bitcoin.o: ./source/bitcoin.cpp ./header/bitcoin.hpp ./header/block.hpp
	$(CC) $(CFLAGS) -o $@ -c ./source/bitcoin.cpp

main.o: ./source/main.cpp ./header/bitcoin.hpp
	$(CC) $(CFLAGS) -o $@ -c ./source/main.cpp

.PHONY: clean
clean:
	rm -f blockchain *.o