/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 14.4.00                         */
/* Aktualisiert: Bruno Lang, 2003/03/31, 2004/04/15 */
/*                                                  */
/* Dieses Programm bestimmt in einem Feld           */
/* x[ 0 .. n - 1 ] ein Teilarray x[ i .. j ] mit    */
/* maximaler Teilsumme.                             */
/*                                                  */
/* Algorithmisches Prinzip: Exhaustive Search       */
/****************************************************/

#include <stdio.h>

enum { N_MAX = 1000 } ;    /* maximale Folgenlaenge */

typedef double Folge[ N_MAX ] ; /* Folge von Zahlen */

typedef struct {
   int i ;                         /* Anfangs-Index */
   int j ;                             /* End-Index */
   double summe ;         /* Summe zwischen i und j */
} Abschnitt ;

/* ------------------------------------------------ */

/* Bestimmt einen Abschnitt x[ i .. j ] in
   x[ 0 .. n - 1 ] mit maximaler Summe. Anfangs-
   und Endindex i bzw. j und Summenwert summe
   werden in max_abschnitt zurueckgegeben.       */

void max_teilsumme( Folge x, int n,
                    Abschnitt *max_abschnitt )
{
   double akt_summe ;     /* Summe des betrachteten
                             Abschnitts             */
   int i0, j0, k ;

   max_abschnitt->i = 0 ;
   max_abschnitt->j = 0 ;
   max_abschnitt->summe = x[ 0 ] ;
  
      /* untersuche alle moeglichen Abschnitte */

   for ( i0 = 0 ; i0 < n ; i0++ ) 
       for ( j0 = i0 ; j0 < n ; j0++ ) {
          akt_summe = x[ i0 ] ;  /* Summe berechnen */
          for ( k = i0 + 1 ; k <= j0 ; k++ ) 
             akt_summe = akt_summe + x[ k ] ;
          if ( akt_summe > max_abschnitt->summe ) {
             max_abschnitt->i = i0 ;
             max_abschnitt->j = j0 ;
             max_abschnitt->summe = akt_summe ;
          }
       }
}

/* ------------------------------------------------ */

/* Hauptprogramm */

int main( void )
{
   int n ;                      /* Laenge der Folge */
   Folge x ;                    /* Zahlen der Folge */
   Abschnitt max_abschnitt ;     /* Abschnitt
                                    maximaler Summe */
   int k ;

      /* Folge einlesen */

   printf( "Eingabe n (<=%d) : ", N_MAX ) ;
   scanf( "%d", &n ) ;
   for ( k = 0 ; k < n ; k++ ) {
      printf( "Eingabe Folgenglied Nr. %d : ", k ) ;
      scanf( "%lf", &x[ k ] ) ;
   }

      /* Loesung bestimmen */

   max_teilsumme( x, n, &max_abschnitt ) ;
  
      /* Loesung ausgeben */

   printf( "Maximaler Abschnitt: Indizes %d .. %d, "
           "Summe %f\n ", 
           max_abschnitt.i, max_abschnitt.j,
           max_abschnitt.summe ) ;

   return 0 ;
}
