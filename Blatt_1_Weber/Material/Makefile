CC := gcc
CCFLAGS := -Wall

CEXE := main
CSRC := $(CEXE).c dcl.c l_datentyp.c
COBJ := $(patsubst %.c,%.o,$(CSRC))

all: $(CEXE)

.SUFFIXES:
.SECONDARY:

%: %.o $(COBJ)
	$(CC) $(COBJ) -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f $(COBJ) $(CEXE)
