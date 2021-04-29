/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 19.4.00                         */
/* Aktualisiert: Bruno Lang, 2003/05/15,            */
/*    2004/04/19, 2005/04/21                        */
/*                                                  */
/* Dieses Programm bestimmt eine Fuellung maximalen */
/* Gewinns fuer das kontinuierliche Knapsack-       */
/* Problem.                                         */ 
/*                                                  */
/* Algorithmisches Prinzip: Greedy                  */
/*                                                  */
/* Indizierung ab 1, Komponenten 0 von Feldern      */
/* werden nicht benutzt                             */
/****************************************************/

#include <stdio.h>

enum { N_MAX = 50 } ;
                 /* maximale Zahl von Gegenstaenden */

typedef double Fuellung[ N_MAX + 1 ] ;
            /* wieviel von Gegenstand i mitnehmen ? */
typedef double Werte[ N_MAX + 1 ] ;
         /* fuer Gewinne, Volumina der Gegenstaende */

   /* "globale" Variablen */

int n ;                  /* Anzahl der Gegenstaende */
Werte g,        /* g[ i ]: Gewinn fuer Gegenstand i */
      v ;       /* v[ i ]: Volumen von Gegenstand i */
double f ;       /* Fassungsvermoegen des Rucksacks */

/* ------------------------------------------------ */

/* Bestimmt eine Gewinn-maximale Fuellung eines
   Rucksacks des Fassungsvermoegens f mit Anteilen
   der Gegenstaende 1 .. n. g[ 1 .. n ] sind die
   erzielten Gewinne, v[ 1 .. n ] die Volumina
   der Gegenstaende. Zurueckgeliefert werden die
   Koeffizienten x_opt[ 1 .. n ] einer optimalen
   Fuellung sowie Gesamtgewinn und -volumen in
   g_opt bzw. v_opt.
   >>> Zugriff auf die globalen Variablen
       n, g, v, f                              <<< */

void einpacken( Fuellung x_opt,
                double *g_opt, double *v_opt )
{   
   int i[ N_MAX + 1 ] ;
                     /* Reihenfolge der Betrachtung */
   Werte sigma ;             /* spezifische Gewinne */
   double kapazitaet ;  /* freier Platz im Rucksack */
   double sigma_max ;     /* groesster verbliebener
                             sigma-Wert             */
   int i_max ;                /* zugehoeriger Index */
   int k, i_k, j ;
 
      /* berechne spezifische Gewinne */

   for ( j = 1 ; j <= n ; j++ ) {
      sigma[ j ] = g[ j ] / v[ j ] ;
      i[ j ] = j ;
   }

      /* starte mit leerem Rucksack */

   kapazitaet = f ;
   *g_opt = 0.0 ;
   *v_opt = 0.0 ;

   for ( k = 1 ; k <= n ; k++ ) {

         /* bestimme Gegenstand mit maximalem
            spezifischem Gewinn               */

      i_max = k ;
      for ( j = k + 1 ; j <= n ; j++ )
         if ( sigma[ j ] > sigma[ i_max ] )
            i_max = j ;

         /* tausche Gegenstand i[ i_max ] an die
            Position k                           */

      i_k = i[ i_max ] ;
      i[ i_max ] = i[ k ] ;
      i[ k ] = i_k ;
      sigma_max = sigma[ i_max ] ;
      sigma[ i_max ] = sigma[ k ] ;
      sigma[ k ] = sigma_max ;

         /* Anteil von Gegenstand i[ k ] einpacken */

      if ( v[ i_k ] <= kapazitaet )
         x_opt[ i_k ] = 1.0 ;
      else
         x_opt[ i_k ] = kapazitaet / v[ i_k ] ;
      *g_opt += x_opt[ i_k ] * g[ i_k ] ;
      *v_opt += x_opt[ i_k ] * v[ i_k ] ;
      kapazitaet -= x_opt[ i_k ] * v[ i_k ] ;
   }
}

/* ------------------------------------------------ */

/* Hauptprogramm
   >>> Zugriff auf die globalen Variablen
       n, g, v, f                         <<< */

int main( void )
{    
   Fuellung x_opt ;
            /* Koeffizienten der optimalen Fuellung */
   double g_opt,          /* Gewinn dieser Fuellung */
          v_opt ;        /* Volumen dieser Fuellung */

   int i ;
 
      /* Problemgroessen einlesen */

   printf( "Anzahl der Gegenstaende : " ) ;
   scanf( "%d", &n ) ;
   for ( i = 1 ; i <= n ; i++ ) {
      printf( "Volumen, Gewinn fuer "
              "Gegenstand %2d : ", i ) ;
      scanf( "%lf %lf", &v[ i ], &g[ i ] ) ;
   }
   printf( "Fassungsvermoegen des Rucksacks : " ) ;
   scanf( "%lf", &f ) ;

      /* Loesung bestimmen ... */

   einpacken( x_opt, &g_opt, &v_opt ) ;

      /* ... und ausgeben */

   printf( "Es wird mitgenommen :\n" ) ;
   for ( i = 1 ; i <= n ; i++ ) 
      printf(  "  Anteil %f von Gegenstand %d\n",
               x_opt[ i ], i ) ;
   printf( "Gesamtgewinn  : %f\n", g_opt ) ;
   printf( "Gesamtvolumen : %f\n", v_opt ) ;

   return 0 ;
}
