/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 15.4.00                         */
/* Aktualisiert: Bruno Lang, 2003/03/31,            */
/*    2004/04/16, 2005/04/21                        */
/*                                                  */
/* Dieses Programm bestimmt alle Moeglichkeiten,    */
/* n (Schach-)Damen so auf einem (n X n)-Brett      */
/* aufzustellen, dass sich keine zwei Damen         */
/* gegenseitig bedrohen.                            */
/*                                                  */
/* Algorithmisches Prinzip: Backtracking            */
/*                                                  */
/* Indizierung ab 1, Komponenten 0 von Feldern      */
/* werden nicht benutzt                             */
/****************************************************/

#include <stdio.h>
#include "boolean.h"       /* fuer Datentyp Boolean */

enum { N_MAX = 20 } ;      /* maximale Brettgroesse */

typedef int Belegung[ N_MAX + 1 ] ;
                /* Zeilennummern der Damen:
                   Komponente 0 wird nicht benutzt  */

int nr_loesung = 0 ;  /* zaehlt gefundene Loesungen */

/* ------------------------------------------------ */

/* Gibt die nr_loesung-te Loesung des n-Damen-
   Problems aus. Diese Loesung ist in z[ 1 .. n ]
   abgelegt.
   >>> Zugriff auf globalen Zaehler nr_loesung <<< */

void loesung( Belegung z, int n )
{
   int j ;

   nr_loesung++ ;
   printf( "Loesung Nummer %d:\n", nr_loesung ) ;
   for ( j = 1 ; j <= n ; j++ )
      printf( "  Dame %2d in Spalte %2d"
              " und Zeile %2d\n",
              j, j, z[ j ] ) ;
}

/* ------------------------------------------------ */

/* Liefert TRUE, falls Dame k von keiner der Damen
   1, ..., k - 1 bedroht wird, und FALSE sonst.    */

Boolean nicht_bedroht( int k, Belegung z )
{
   int i ;
   Boolean bedrohung = FALSE ;           
 
   for ( i = 1 ; i < k ; i++ )
       bedrohung = bedrohung
             || ( z[ i ] == z[ k ] )
                        /* gleiche Zeile wie Dame k */
             || ( i + z[ i ] == k + z[ k ] )
                             /* gleiche /-Diagonale */
             || ( i - z[ i ] == k - z[ k ] ) ;
                             /* gleiche \-Diagonale */

   return ( ! bedrohung ) ;
}
 
/* ------------------------------------------------ */

/* Bisher sind die Damen 1, ..., k - 1 in den
   Zeilen z[ 1 ], ..., z[ k - 1 ] platziert, und es
   trat noch keine Bedrohung auf. Beim aktuellen
   Aufruf der Prozedur werden alle Moeglichkeiten
   durchprobiert, die k-te Dame bedrohungsfrei zu
   platzieren.                                      */

void setze_dame( int k, Belegung z, int n )
{
  int j ;

  if ( k > n )
             /* alle n Damen sind bereits platziert */
     loesung( z, n ) ;
  else
     for ( j = 1 ; j <= n ; j++ ) {
        z[ k ] = j ;     /* setze Dame k in Zeile j */
        if ( nicht_bedroht( k, z ) )
                       /* versuche, die bisherige
                          Teilbelegung fortzusetzen */
           setze_dame( k + 1, z, n ) ;
     }
}

/* ------------------------------------------------ */

/* Hauptprogramm
   >>> Zugriff auf globalen Zaehler nr_loesung <<< */

int main( void )
{
   int n ;       /* Groesse des betrachteten Bretts */
   Belegung leer ;              /* Brett ohne Damen */

   printf( "Groesse des Bretts : " ) ;
   scanf( "%d", &n ) ;

      /* platziere erste Dame (und rekursiv die
         uebrigen)                              */

   setze_dame( 1, leer, n ) ;

   printf( "Es gibt %2d Loesungen\n", nr_loesung ) ;

   return 0 ;
}
