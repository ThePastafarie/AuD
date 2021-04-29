/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 19.4.00                         */
/* Aktualisiert: Bruno Lang, 2003/04/02,            */
/*    2004/04/16, 2005/04/21, 2020/03/30            */
/*                                                  */
/* Dieses Programm bestimmt die besten Zuege im     */
/* NIM-Spiel gegen einen Gegner.                    */
/* Es wird angenommen, dass der Gegner ("Weiss")    */
/* zuerst zieht, dann der Computer ("Schwarz").     */
/*                                                  */
/* Regeln fuer NIM:                                 */
/*   - zu Beginn liegen h Hoelzchen auf einem       */
/*     Haufen (z.B. h = 21)                         */
/*   - Weiss und Schwarz nehmen abwechselnd jeweils */
/*     1 bis 3 Hoelzchen vom Haufen                 */
/*   - verloren hat, wer das letzte Hoelzchen       */
/*     nehmen muss                                  */ 
/*                                                  */
/* Algorithmisches Prinzip: Greedy                  */
/****************************************************/

#include <stdio.h>
#include "boolean.h"       /* fuer Datentyp Boolean */

enum { MAX_ZUG = 3 } ;   /* so viele Hoelzchen
                            duerfen genommen werden */

/* ------------------------------------------------ */

/* Liefert den besten Zug fuer Schwarz, wenn noch h
   Hoelzchen vorhanden sind                         */

int zug_von_schwarz( int h )
{
   int k = ( ( h - 1 ) / ( MAX_ZUG + 1 ) ) ;
   int z = h - ( ( MAX_ZUG + 1 ) * k + 1 ) ; 
          /* Differenz zur naechsten Gewinnposition */
   if ( ( z >= 1 ) && ( z <= MAX_ZUG ) )
      return z ;
   else
      return 1 ;              /* "Verlegenheitszug" */
}

/* ------------------------------------------------ */

/* Hauptprogramm */

int main( void )
{
   int h ; /* Anzahl der noch vorhandenen Hoelzchen */
   int zug ;          /* gerade durchgefuehrter Zug */
   Boolean zug_ok ;         /* ist der aktuelle Zug
                               von Weiss OK ?       */

   printf( "Anzahl der Hoelzchen zu Beginn : " ) ;
   scanf( "%d", &h ) ;

   while ( h > 0 ) {

         /* Zug von Weiss einlesen ... */

      do {
         printf( "Zug von Weiss ? " ) ;
         scanf( "%d", &zug ) ;
         zug_ok = ( zug >= 1 ) && ( zug <= MAX_ZUG )
                               && ( zug <= h ) ;
         if ( ! zug_ok )
            printf( "*** Nicht zulaessiger Zug !"
                    "\n" ) ;
      } while ( ! zug_ok ) ;

         /* ... und ausfuehren */

      h = h - zug ;
      if ( h == 0 )
         printf( "Weiss verliert.\n" ) ;
      else {

            /* besten Zug fuer Schwarz bestimmen .. */

         zug = zug_von_schwarz( h ) ;

            /* ... und ausfuehren */

         h = h - zug ;
         printf( "Zug von Schwarz : %d Rest %d\n",
                 zug, h ) ;
         if ( h == 0 )
            printf( "Schwarz verliert.\n" ) ;
      } 
   }

   return 0 ;
}
