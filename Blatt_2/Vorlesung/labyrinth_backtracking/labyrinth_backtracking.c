/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 14.4.00                         */
/* Aktualisiert: Bruno Lang, 2003/03/27,            */
/*    2004/04/16, 2005/04/20, 2020/03/27            */
/*                                                  */
/* Dieses Programm findet alle moeglichen Wege vom  */
/* Startpunkt zum Zielpunkt eines als (m X n)-      */
/* Matrix gegebenen Labyrinths. Dabei steht ein     */
/* Matrixeintrag 'f' fuer ein freies, 'b' fuer ein  */
/* blockiertes Feld des Labyrinths.                 */
/*                                                  */
/* Algorithmisches Prinzip: Backtracking            */
/****************************************************/

#include <stdio.h>

enum { N_MAX = 100,M_MAX = 100 } ;/* maximale Labyrinth-Groesse */

typedef char Labyrinth[ M_MAX ][ N_MAX ] ;
       /* f/b-codiertes ( M_MAX x N_MAX )-Labyrinth */

typedef struct {
   int k ;
   int l ;
} Feld ;  /* Koordinaten eines Felds des Labyrinths */

typedef Feld Weg[ M_MAX * N_MAX ] ;
   /* zurueckgelegter Weg (Laenge <= M_MAX * N_MAX) */

int nr_loesung = 0 ;  /* zaehlt gefundene Loesungen */

/* ------------------------------------------------ */

/* Gibt einen gefundenen Weg aus.
   >>> Zugriff auf globalen Zaehler nr_loesung <<< */

void loesung( Labyrinth lab, int n, int m,Weg w, int laenge )
{
   int p, q ;

   nr_loesung++ ;
   printf( "Loesung Nummer %d\n", nr_loesung ) ;

      /* Ausgabe der Felder des Wegs */

   printf( "Felder :\n" ) ;
   for ( p = 0 ; p < laenge ; p++ )
      printf( "(%d,%d) ", w[ p ].k, w[ p ].l ) ;
   printf( "\n" ) ;

      /* "graphische" Ausgabe des Labyrinths */

   for ( p = 0 ; p < m ; p++ ) {
      for ( q = 0 ; q < n ; q++ )
         printf( "%c", lab[ p ][ q ] ) ;
      printf( "\n" ) ;
   }
   printf( "\n" ) ;
}

/* ------------------------------------------------ */

/* Prueft zuerst, ob das naechste Feld ( k_q, l_q )
   des Wegs w zulaessig ist (d.h. noch im Labyrinth
   liegt und frei ist), und versucht dann, den Weg
   von dort aus in alle Richtungen fortzusetzen.    */

void fortsetzen( Labyrinth lab, int m, int n,Feld ziel,Weg w, int laenge, int k_q, int l_q )
{
   if ( ( k_q >= 0 ) && ( k_q < m ) &&( l_q >= 0 ) && ( l_q < n ) ) {
      /* sonst fuehrt der Weg aus dem
                       Labyrinth heraus; abbrechen  */
      if ( lab[ k_q ][ l_q ] == 'f' ) {
               /* sonst ist fas Feld blockiert oder 
                  schon im Weg enthalten; abbrechen */
         w[ laenge ].k = k_q ;
         w[ laenge ].l = l_q ;
         laenge++ ;
         lab[ k_q ][ l_q ] = '*' ;
                    /* Feld als "besucht" markieren */
         if ( ( k_q == ziel.k ) && ( l_q == ziel.l ) ) 
                               /* Zielfeld erreicht */
            loesung( lab, n, m, w, laenge );
         else {  
                               /* nach rechts gehen */
            fortsetzen( lab, m, n, ziel,
                        w, laenge, k_q, l_q + 1 ) ;
                                 /* nach oben gehen */
            fortsetzen( lab, m, n, ziel,
                        w, laenge, k_q - 1, l_q ) ;
                                /* nach links gehen */
            fortsetzen( lab, m, n, ziel,
                        w, laenge, k_q, l_q - 1 ) ;
                                /* nach unten gehen */
            fortsetzen( lab, m, n, ziel,
                        w, laenge, k_q + 1, l_q ) ;
         }
         lab[ k_q ][ l_q ] = 'f' ;
                             /* Markierung loeschen */
      } 
   }
} 

/* ------------------------------------------------ */

/* Hauptprogramm */

int main( void )
{
   Labyrinth lab ;   /* zu durchlaufendes Labyrinth */
   int m, n ;             /* Groesse des Labyrinths */
   Feld start, ziel ;        /* Start- und Zielfeld */
   Weg w ;                        /* begangener Weg */
   int p ;

      /* initialisieren */

   printf( "Labyrinthdimensionen m und n eingeben : " ) ;
   scanf( "%i%i\n", &m, &n );
                              /* Labyrinth einlesen */
   printf( "Labyrinth zeilenweise eingeben :\n" ) ;
   for ( p = 0 ; p < m ; p++ )
      scanf( "%s\n", lab[ p ] ) ;
                   /* Start- und Zielfeld einlesen */
   printf( "Startfeld : " ) ;
   scanf( "%i%i", &start.k, &start.l ) ;
   printf( "Zielfeld : " ) ;
   scanf( "%i%i", &ziel.k, &ziel.l ) ;
   printf( "\n\n" ) ;

      /* Wege suchen; beim Startfeld beginnen */

   fortsetzen( lab, m, n, ziel,
               w, 0, start.k, start.l ) ;

   return 0 ;
}
