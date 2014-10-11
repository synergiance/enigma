CC=g++
ARGS=
CFLAGS=$(ARGS) -Wall
OFLAGS=-c $(CFLAGS)
OBJ=enigma.o rotor.o plugbank.o

all: enigma

enigma: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o enigma

enigma.o: enigma.cpp rotor.cpp plugbank.cpp
	$(CC) $(OFLAGS) enigma.cpp

%.o: %.cpp %.h
	$(CC) $(OFLAGS) -o $@ $<

bin:
	mkdir -p bin

.PHONY: clean cleanobj

clean: cleanobj
	rm -rf enigma

cleanobj:
	rm -rf *.o
