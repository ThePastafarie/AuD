/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, Holger Arndt, 02.05.2000        */
/* Aktualisiert: Bruno Lang, 2003/05/16,            */
/*    2004/04/22, 2005/05/09                        */
/*                                                  */
/* Dieses Programm bestimmt eine Reihenfolge fuer   */
/* die Auswertung des Produktes von n Matrizen      */
/* A[ i ] der Dimensionen m[ i - 1 ] X m[ i ], so   */
/* dass die Anzahl der reellen Multiplikationen     */
/* minimal wird.                                    */ 
/*                                                  */
/* Algorithmisches Prinzip: Dynamic Programming     */
/*                                                  */
/* Indizierung ab 1, Komponenten 0 von Feldern      */
/* werden nicht benutzt                             */
/****************************************************/

#include <stdio.h>
#include <string.h>

#define N_MAX 20        /* Maximalzahl von Matrizen */

typedef struct {
   int mults ;  /* Minimalzahl von Multiplikationen
                   zur Berechnung des Teilprodukts  */
   int pos ;       /* letzte durchzufuehrende Mult. */
} Produkt ;

typedef Produkt Tableau[ N_MAX+1 ][ N_MAX+1 ] ;
              /* Tableau fuer optimale Teilprodukte */

/* ------------------------------------------------ */

/* Gibt die optimale Multiplikationsreihenfolge
   fuer das Produkt A[ i ] * ... * A[ i+l-1 ]
   von l aufeinanderfolgenden Matrizen aus, wobei
   die Information ueber die optimalen Teilprodukte
   aus der Tabelle opt entnommen wird.              */

void reihenfolge_ausgeben( Tableau opt,
                           int i, int l )
{
   int p = opt[ i ][ l ].pos ;
          /* letzte Multiplikation fuer das Produkt
             ist die von A[ p ] mit A[ p+1 ]        */

   if ( l > 1 ) {
        /* Reihenfolge fuer A[ i ] * ... * A[ p ] */
      reihenfolge_ausgeben( opt, i, p - i + 1 ) ;
        /* und fuer A[ p+1 ] * ... * A[ i+l-1 ] */
      reihenfolge_ausgeben( opt, p + 1,
                            i + l - 1 - p ) ;
                   /* abschliessende Multiplikation */
      printf( "%d ", p ) ;
   }
}

/* ------------------------------------------------ */

/* Bestimmt eine optimale Reihenfolge zur
   Multiplikation von n Matrizen A[ i ] mit den
   angegebenen Dimensionen m[ i-1 ] X m[ i ].   */

void optimale_reihenfolge( int n, int m[],
                           Tableau opt )
{
   int i, l ;        /* Anfangsindex, Anzahl der
                        Faktoren eines Teilprodukts */
   int k,      /* Laenge des ersten Faktors bei der
                  aktuell betrachteten Aufteilung   */
       akt_mult,  /* zugeh. Anzahl Multiplikationen */
       min_mult,     /* bisherige Minimalzahl Mult. */
       min_pos ;    /* zugeh. letzte Multiplikation */

        /* Loesungen der Laenge 1 sind die Produkte
           mit nur einem Faktor                     */
   for ( i = 1 ; i <= n ; i++ ) {    
      opt[ i ][ 1 ].mults = 0 ;
      opt[ i ][ 1 ].pos = -1 ;
   }

   for ( l = 2 ; l <= n ; l++ )
      for ( i = 1 ; i <= n - l + 1 ; i++ )
      {
            /* Bestimme optimale Reihenfolge fuer
               Produkt von i bis i + l - 1.
                 Initialisierung mit dem Fall, dass
               der erste Faktor die Laenge 1 hat    */
         min_mult = opt[ i ][ 1 ].mults
                    + opt[ i+1 ][ l-1 ].mults
                    + m[ i-1 ] * m[ i ] * m[ i+l-1 ] ;
         min_pos = i ;

                    /* jetzt die anderen moeglichen
                       Darstellungen testen         */
         for ( k = 2 ; k < l ; k++ ) {
            akt_mult = opt[ i ][ k ].mults
               + opt[ i+k ][ l-k ].mults
               + m[ i-1 ] * m[ i+k-1 ] * m[ i+l-1 ] ;
                         /* das bisher Beste merken */
            if ( akt_mult < min_mult ) {
               min_mult = akt_mult ;
               min_pos = i + k - 1 ;
            }
         }
         opt[ i ][ l ].mults = min_mult ;
         opt[ i ][ l ].pos = min_pos ;
      } 
} 

/* ------------------------------------------------ */

/* Hauptprogramm */

int main( void )
{
   int n ;                   /* Anzahl der Matrizen */
   int m[ N_MAX + 1 ] ;        /* Matrixdimensionen */
   Tableau opt ;           /* optimale Teilprodukte */
   int i ;

                      /* Matrixdimensionen einlesen */
   printf( "Anzahl der Matrizen: " ) ;
   scanf( "%d", &n ) ;
   for ( i = 0 ; i <= n ; i++ ) {
      printf( "%d-te Matrixdimension: ", i ) ;
      scanf( "%d", &m[ i ] ) ;
   }

              /* optimale Reihenfolge bestimmen ... */
   optimale_reihenfolge( n, m, opt ) ;

                                /* ... und ausgeben */
   printf( "Optimale Matrixmultiplikation :\n" ) ;
   printf( "  Reihenfolge : ( " ) ;
   reihenfolge_ausgeben( opt, 1, n ) ;
   printf( ")\n" ) ;
   printf( "  %d Multiplikationen\n",
           opt[ 1 ][ n ].mults ) ;

   return 0 ;
}
