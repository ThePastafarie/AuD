      # Beginnen Sie mit den Erlaeuterungen zu "l_datentyp.o" (Zeilen 6ff)

liste_mit_zeigern: l_datentyp.o liste.o liste_main.o Makefile
	gcc -std=c11 -Wall l_datentyp.o liste.o liste_main.o -o liste_mit_zeigern

      # Die folgenden zwei Zeilen bewirken folgendes:

      # Zweite Zeile:
      # Um die Datei l_datentyp.c zu uebersetzen
      # (d.h. Maschinen-ausfuehrbare Befehle dafuer zu erhalten,
      # sog. "Object Code"), wird der Compiler aufgerufen.
      # -std=c11 bedeutet, dass die Syntax auf den C11-Standard
      #    ueberprueft werden soll,
      # -Wall bedeutet, dass fuer alle Unstimmigkeiten Warnungen
      #    angezeigt werden sollen, und
      # -c bedeutet, dass kein ausrufbares Programm erzeugt werden
      #    soll (das geht auch nicht, wenn man nur l_datentyp.c
      #    uebersetzt), sondern nur Code fuer die C-Funktionen in
      #    dieser Datei.
      # Dies erzeugt eine Datei l_datentyp.o mit dem Object Code.

      # Die erste Zeile besagt, dass das Uebersetzen immer dann
      # stattfinden soll, wenn das "Target" l_datentyp.o gebraucht
      # wird und
      # - entweder noch nicht vorhanden ist
      # - oder zwar vorhanden ist, aber aelter als eine der drei nach
      #   dem Doppelpunkt angegebenen Dateien (d.h. eine davon wurde
      #   seit dem letzten Uebersetzen geaendert).

      # WICHTIG: Fuer ein Target koennen auch mehrere Anweisungen
      #          (jede in einer eigenen Zeile) verwendet werden
      # GANZ WICHTIG: Alle diese Zeilen muessen mit einem <TAB>
      #               beginnen!
      #               Wenn Sie statt dessen Leerzeichen verwenden
      #               (das kann leicht bei Copy/Paste passieren),
      #               dann erhalten Sie kryptische Fehlermeldungen.

l_datentyp.o: l_datentyp.h l_datentyp.c Makefile
	gcc -std=c11 -Wall -c l_datentyp.c

liste.o: boolean.h l_datentyp.h liste.h liste.c Makefile
	gcc -std=c11 -Wall -c liste.c

liste_main.o: boolean.h l_datentyp.h liste.h liste_main.c Makefile
	gcc -std=c11 -Wall -c liste_main.c

      # Jetzt zu den beiden ganz oben stehenden Zeilen:
      # Die zweite Zeile nimmt die drei Object Codes zu den
      #   entsprechenden C-Dateien und "linkt" sie (zusammen mit
      #   Code aus der Standard-Bibliothek, z.B. fuer die Funktionen
      #   printf und scanf) zu einem ausfuehrbaren Programm.
      #   Die Option "-o liste_mit_zeigern" gibt an, dass dieses
      #   Programm in einer Datei liste_mit_zeigern abgelegt wird.
      # Die erste Zeile gibt wieder an, was dafuer gebraucht wird.

      # In diesem Beispiel versucht der Aufruf
      #   make liste_mit_zeigern
      # (oder auch kuerzer "make", weil liste_mit_zeigern das erste
      # Target im Makefile ist), das Target liste_mit_zeigern zu
      # erzeugen.
      # Dies haengt von l_datentyp.o, liste.o, liste_main.o und Makefile
      # ab, die nun ihrerseits ueberprueft (und ggf. neu erzeugt) werden.


      # Da das folgende Target von nichts abhaengt, wird bei dem Aufruf
      #   make clean
      # immer die nachfolgende Zeile ausgefuehrt, d.h. das ausfuehrbare
      # Programm und alle Object-Dateien werden geloescht.

clean:
	rm liste_mit_zeigern *.o
