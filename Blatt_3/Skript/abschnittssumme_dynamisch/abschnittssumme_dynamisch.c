/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 27.04.2000                      */
/* Aktualisiert: Bruno Lang, 2003/05/06, 2004/04/26 */
/*                                                  */
/* Dieses Programm bestimmt in einem Feld           */
/* x[ 0 .. n - 1 ] ein Teilarray x[ i .. j ] mit    */
/* maximaler Teilsumme.                             */
/*                                                  */
/* Algorithmisches Prinzip: Dynamic Programming     */
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
   int k = 0 ;
   Abschnitt max_bis_k = { 0, 0, x[ 0 ] } ;
            /* max-Teilfolge, die bei Index k endet */
   *max_abschnitt = max_bis_k ;
  
   for ( k = 1 ; k < n ; k++ ) { 

              /* max-Teilfolge mit Endindex k
                 aktualisieren                */
      max_bis_k.j = k ;
      if ( max_bis_k.summe < 0 ) {
         max_bis_k.i = k ;
         max_bis_k.summe = x[ k ] ;
      }
      else
         max_bis_k.summe = max_bis_k.summe + x[ k ] ;

                     /* max-Teilfolge aktualisieren */
      if ( max_bis_k.summe > max_abschnitt->summe ) 
         *max_abschnitt = max_bis_k ;
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
