#
#Peter Weber  1936796
#
#Gruppe:
#Uebungsblatt: 0 Aufgabe: 1
#

#	Makefile 
#		Ausfuehren mit make
#		Aufraeumen mit make clean

# Variablen mit Dateinamen, Compileraufruf und Optionen fuer Compiler und Linker
HDR     = 											#header einfuegen -> hpp
SRC		= Aufgabe2.c								#code einfuegen   -> cpp
OBJ     = $(SRC:.c=.o)
BIN     = main										#name der ausfuehrbaren datei
CC      = gcc
CCFLAGS = -std=c11
LDFLAGS = -o $(BIN)

# Defaulttarget
all: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ)

# Uebersetzungsregel mit Hilfe von Patterns
%.o: %.cpp $(HDR)
	$(CC) $(CCFLAGS) -c $<

# Aufraeumen des Verzeichnisses
.PHONY: clean
clean:
	rm -rf *.o $(BIN)