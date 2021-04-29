/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 13.4.00                         */
/* Aktualisiert: Bruno Lang, 2003/03/26,            */
/*    2004/04/16, 2005/04/20, 2020/03/26            */
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
/* Algorithmisches Prinzip: Exhaustive search       */
/****************************************************/

#include <stdio.h>
#include "boolean.h"       /* fuer Datentyp Boolean */

enum { MAX_ZUG = 3 } ;   /* so viele Hoelzchen
                            duerfen genommen werden */

/* ------------------------------------------------ */

/* Vorwaerts-Deklaration notwendig wegen
   indirekter Rekursion: gewinn_pos_weiss und
   gewinn_pos_schwarz rufen sich gegenseitig auf */

Boolean gewinn_pos_schwarz( int h, int *bester_zug ) ;

/* ------------------------------------------------ */

/* Ist ein Haufen mit h Hoelzchen eine Gewinnpos.
   fuer Schwarz, wenn Weiss am Zug ist ?          */

Boolean gewinn_pos_weiss( int h )
{
   int z ;                 /* gerade probierter Zug */
   Boolean gewinn_pos ;   /* liegt Gewinnpos. vor ? */
   int dummy ;

   if ( h == 0 )
      return( FALSE ) ;  /* Schwarz nahm das letzte */
   else {               /* jeder Zug von Weiss muss 
                           auf Gewinnpos. fuehren   */
      gewinn_pos = TRUE ;
      for ( z = 1 ; z <= MAX_ZUG && z <= h ; z++ )
         if ( ! gewinn_pos_schwarz( h - z, &dummy ) )
                /* hier interessiert nicht der
                   beste Zug, sondern nur ob eine
                   Gewinnposition vorliegt        */
            gewinn_pos = FALSE ;

      return ( gewinn_pos ) ;
   }
}

/* ------------------------------------------------ */

/* Ist ein Haufen mit h Hoelzchen eine Gewinnpos.
   fuer Schwarz, wenn Schwarz am Zug ist ? Wenn ja,
   welches ist der beste Zug fuer Schwarz (wird in
   *bester_zug zurueckgegeben) ?                    */

Boolean gewinn_pos_schwarz( int h, int *bester_zug )
{
   int z ;                 /* gerade probierter Zug */
   Boolean gewinn_pos ;   /* liegt Gewinnpos. vor ? */
 
   if ( h == 0 )
      return( TRUE ) ;     /* Weiss nahm das letzte */
   else {
      *bester_zug = 1 ; /* falls kein Gewinnzug ex. */
                     
      gewinn_pos = FALSE ;  /* ein Gewinnzug reicht */
      for ( z = 1 ; z <= MAX_ZUG && z <= h ; z++ )
         if ( gewinn_pos_weiss( h - z ) ) {
            *bester_zug = z ;
            gewinn_pos = TRUE ;
         }

      return ( gewinn_pos ) ;
   }
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

         /* ... und ausfuehren, */

      h = h - zug ;
      if ( h == 0 )
         printf( "Weiss verliert.\n" ) ;
      else {

            /* besten Zug fuer Schwarz bestimmen .. */

         gewinn_pos_schwarz( h, &zug ) ;
             /* das Funktionsergebnis, ob dies zum
                Gewinn fuehrt, wird hier ignoriert;
                hier braucht man nur den besten Zug */

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
