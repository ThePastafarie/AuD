      # Analog zu liste_mit_zeigern

queue_mit_feld: q_datentyp.o queue.o queue_main.o Makefile
	gcc -std=c11 -Wall q_datentyp.o queue.o queue_main.o -o queue_mit_feld


q_datentyp.o: q_datentyp.h q_datentyp.c Makefile
	gcc -std=c11 -Wall -c q_datentyp.c

queue.o: boolean.h q_datentyp.h queue.h queue.c Makefile
	gcc -std=c11 -Wall -c queue.c

queue_main.o: boolean.h q_datentyp.h queue.h queue_main.c Makefile
	gcc -std=c11 -Wall -c queue_main.c


clean:
	rm queue_mit_feld *.o
