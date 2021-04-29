liste_mit_zeigern: q_datentyp.o queue.o huffman_greedy.o Makefile
	gcc -std=c11 -Wall q_datentyp.o queue.o huffman_greedy.o -o huffman_greedy


q_datentyp.o: q_datentyp.h q_datentyp.c Makefile
	gcc -std=c11 -Wall -c q_datentyp.c

queue.o: boolean.h q_datentyp.h queue.h queue.c Makefile
	gcc -std=c11 -Wall -c queue.c

huffman_greedy.o: boolean.h binaerbaum.h q_datentyp.h queue.h \
                  huffman_greedy.c Makefile
	gcc -std=c11 -Wall -c huffman_greedy.c


clean:
	rm huffman_greedy *.o
