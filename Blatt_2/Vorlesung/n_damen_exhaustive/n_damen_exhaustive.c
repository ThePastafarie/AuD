/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 14.4.00                         */
/* Aktualisiert: Bruno Lang, 2003/03/31, 2004/04/20 */
/*                                                  */
/* Dieses Programm bestimmt alle Moeglichkeiten, n  */
/* (Schach-)Damen so auf einem (n X n)-Brett        */
/* aufzustellen, dass sich keine zwei Damen         */
/* gegenseitig bedrohen.                            */
/*                                                  */
/* Algorithmisches Prinzip: Exhaustive search       */
/*                                                  */
/* Indizierung ab 1, Komponenten 0 von Feldern      */
/* werden nicht benutzt                             */
/****************************************************/

#include <stdio.h>
#include "boolean.h"       /* fuer Datentyp Boolean */

enum { N_MAX = 20 } ;      /* maximale Brettgroesse */

typedef int Belegung[ N_MAX + 1 ] ;
     /* Zeilennr. der Damen; Komponente 0 ungenutzt */

int nr_loesung = 0 ;  /* zaehlt gefundene Loesungen */

/* ------------------------------------------------ */

/* Gibt die nr_loesung-te Loesung des n-Damen-
   Problems aus. Die Loesung steht in z[ 1 .. n ].
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

/* Erzeugt die im "Zaehlermodell" auf z folgende
   Brettbelegung.                                */

void naechste_belegung( Belegung z, int n )
{
   Boolean uebertrag ;                              
   int stelle = n ;

   do {
      z[ stelle ] = ( z[ stelle ] % n ) + 1 ;
      uebertrag = ( z[ stelle ] == 1 ) ;
      stelle-- ;
   } while ( uebertrag  && ( stelle != 0 ) ) ;
}

/* ------------------------------------------------ */

/* Liefert TRUE, falls die Belegung z des (n X n)-
   Bretts frei von Bedrohungen ist, und FALSE
   sonst.                                          */

Boolean bedrohungsfrei( Belegung z, int n )
{
   int i, j ;
   Boolean bedrohung ; /* bedrohen sich zwei Damen? */

   bedrohung = FALSE ;
   for ( i = 1 ; i <= n ; i++ )
      for ( j = i + 1 ; j <= n ; j++ )
         bedrohung = bedrohung
              || ( z[ j ] == z[ i ] )
                        /* gleiche Zeile wie Dame i */
              || ( j + z[ j ] == i + z[ i ] )
                             /* gleiche /-Diagonale */
              || ( j - z[ j ] == i - z[ i ] ) ;
                             /* gleiche \-Diagonale */

   return ( ! bedrohung ) ;
}

/* ------------------------------------------------ */

/* Stehen alle Damen in Zeile 1 ? */

Boolean anfangsstellung( Belegung z, int n )
{
   int i ;
   Boolean alle_in_1 = TRUE ;

   for ( i = 1 ; i <= n ; i++ )
      alle_in_1 = alle_in_1 && ( z[ i ] == 1 ) ;

   return alle_in_1 ;
}

/* ------------------------------------------------ */

/* Hauptprogramm */

int main( void )
{
   int n ;       /* Groesse des betrachteten Bretts */
   Belegung z ;
       /* (Zeilen-)Position der Damen auf dem Brett */
   int i ;

   printf( "Groesse des Bretts : " ) ;
   scanf( "%d", &n ) ;

      /* Initialisierung: alle Damen in Zeile 1 */

   for ( i = 1 ; i <= n ; i++ )
      z[ i ] = 1 ;

      /* alle moeglichen Belegungen durchprobieren */

   do {
      if ( bedrohungsfrei( z, n ) )
         loesung( z, n ) ;
      naechste_belegung( z, n ) ;
   } while ( ! anfangsstellung( z, n ) ) ;

   return 0 ;
}
