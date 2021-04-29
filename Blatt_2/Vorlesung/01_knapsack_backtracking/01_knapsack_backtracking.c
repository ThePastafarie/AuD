/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 15.4.00                         */
/* Aktualisiert: Bruno Lang, 2003/04/01,            */
/*    2004/04/16, 2005/04/21                        */
/*                                                  */
/* Bestimmt eine Loesung des 0/1-Knapsack-Problems: */
/*   Gegeben sind n Gegenstaende mit den Volumina   */
/*   v[ 1 ] .. v[ n ] und ein Rucksack mit dem      */
/*   Fassungsvermoegen f. Wird Gegenstand i im      */
/*   Rucksack mitgenommen, so wird der Gewinn       */
/*   g[ i ] erzielt. Gesucht ist eine Fuellung des  */
/*   Rucksacks mit (Gesamtvolumen <= f und)         */
/*   maximalem Gewinn.                              */ 
/*                                                  */
/* Algorithmisches Prinzip: Backtracking            */
/*                                                  */
/* Indizierung ab 1, Komponenten 0 von Feldern      */
/* werden nicht benutzt                             */
/****************************************************/

#include <stdio.h>

enum { N_MAX = 50 } ;
               /* maximale Anzahl von Gegenstaenden */

typedef enum { NICHT_MITNEHMEN = 0,
               MITNEHMEN       = 1  } Status ; 

typedef Status Fuellung[ N_MAX + 1 ] ;
                        /* Gegenstand i mitnehmen ? */
typedef double Werte[ N_MAX + 1 ] ;
         /* fuer Gewinne, Volumina der Gegenstaende */

   /* "globale" Variablen */

int n ;                  /* Anzahl der Gegenstaende */
Werte g,        /* g[ i ]: Gewinn fuer Gegenstand i */
      v ;       /* v[ i ]: Volumen von Gegenstand i */
double f ;       /* Fassungsvermoegen des Rucksacks */

Fuellung opt_fuellung ; /* bisher beste
                           (vollstaendige) Fuellung */
double g_opt,      /* Gewinn dieser besten Fuellung */
       v_opt ;    /* Volumen dieser besten Fuellung */

/* ------------------------------------------------ */

/* Untersucht, ob eine Fuellung des Rucksacks mit
   und/oder ohne Gegenstand i zu einem optimalen
   Gewinn fuehren kann. x[ 1 .. i-1 ] ist der
   bereits festgelegte Teil der gerade betrachteten
   Fuellung (x[ i ] = 1(0) heisst, dass Gegenstand
   i (nicht) mitgenommen wird), g_x und v_x der zu
   dieser Teilfuellung gehoerige Gewinn bzw. das
   Volumen, g_rest der durch Mitnahme aller
   restlichen Gegenstaende i .. n erzielbare
   Gesamtgewinn.
   >>> Zugriff auf die globalen Variablen
       n, g, v, f, opt_fuellung, g_opt, v_opt   <<< */

void einpacken( int i,
                Fuellung x, double g_x, double v_x,
                double g_rest )
{
   int j;

   if ( i > n ) {          /* Fuellung vollstaendig */
      if ( g_x > g_opt ) {         /* neues Optimum */
         for ( j = 1 ; j <= n ; j++ )
            opt_fuellung[ j ] = x[ j ] ;
         g_opt = g_x ;
         v_opt = v_x ;
      }
   }
   else {                 /* betrachte Gegenstand i */
      g_rest -= g[ i ] ;
      if ( ( v_x + v[ i ] <= f ) &&
           ( g_x + g[ i ] + g_rest > g_opt ) ) {

            /* vervollstaendige Fuellung
               MIT Gegenstand i          */

         x[ i ] = MITNEHMEN ;
         einpacken( i + 1, x,
                    g_x + g[ i ], v_x + v[ i ],
                    g_rest ) ;
      }    
      if ( g_x + g_rest > g_opt ) {

            /* vervollstaendige Fuellung
               OHNE Gegenstand i         */

         x[ i ] = NICHT_MITNEHMEN ;
         einpacken( i + 1, x, g_x, v_x, g_rest ) ;
      }
   } 
}

/* ------------------------------------------------ */

/* Hauptprogramm
   >>> Zugriff auf die globalen Variablen
       n, g, v, f, opt_fuellung, g_opt, v_opt   <<< */

int main( void )
{
   Fuellung x ;         /* aktuelle (Teil-)Fuellung */
   double g_rest ;  /* Gewinn aller restl. Gegenst. */
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

      /* Initialisierung: leerer Rucksack */

   g_rest = 0.0 ;
   for ( i = 1 ; i <= n ; i++ ) {
      x[ i ] = NICHT_MITNEHMEN ;
      opt_fuellung[ i ] = NICHT_MITNEHMEN ;
      g_rest += g[ i ] ;
   }
   g_opt = 0.0 ;
   v_opt = 0.0 ;

      /* Loesung bestimmen ... */

   einpacken( 1, x, 0.0, 0.0, g_rest ) ;
             
      /* ... und ausgeben */

   for ( i = 1 ; i <= n ; i++ )
      if ( opt_fuellung[ i ] == MITNEHMEN )
         printf( "Gegenstand %d wird "
                 "mitgenommen\n", i ) ;
      else
         printf( "Gegenstand %d wird "
                 "nicht mitgenommen\n", i ) ;
   printf( "Erzielter Gesamtgewinn : %f\n", g_opt ) ;
   printf( "   bei einem Volumen von %f\n", v_opt ) ;

   return 0 ;
}
