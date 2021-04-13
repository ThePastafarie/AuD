/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 25.04.2000                      */
/* Aktualisiert: Bruno Lang, 2003/04/28, 2004/04/21 */
/*                                                  */
/* Hier werden die Funktionen einer Queue getestet. */
/*                                                  */
/* Der Typ der Queue-Eintraege ist zunaechst int,   */
/* er ist in Anwendungen der Queue jeweils          */
/* ANZUPASSEN.                                      */
/*                                                  */
/* Implementierung der Queue mit einem Feld.        */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"       /* fuer Datentyp Boolean */
#include "q_datentyp.h"          /* fuer Q_datentyp */
#include "queue.h"        /* fuer Queue-Operationen */

/* ------------------------------------------------ */

/* Hauptprogramm zum Testen der Queue-Operationen */

int main( void )
{
   Queue q ;
   Q_datentyp e ;
             /* einzufuegende bzw. geloeschte Daten */
   char c ;
         /* Auswahl einer moeglichen Queueoperation */
   Boolean weiter = TRUE ;    /* Programm beenden ? */

   while ( weiter ) {

         /* Menue ausgeben ... */

      printf( "c [create]  Queue erzeugen\n" ) ;
      printf( "i [enqueue] Element einfuegen\n" ) ;
      printf( "d [dequeue] Element entfernen\n" ) ;
      printf( "e [empty]   Queue leer ?\n" ) ;
      printf( "q [quit]    Programm verlassen\n" ) ;

         /* Auswahl treffen und Aktion ausfuehren */

      c = getchar() ;
      switch( c ) {
         case 'c' :
            q_create( &q ) ;
            break ;
         case 'i' :
            q_datentyp_eingeben( &e ) ;
            q_enqueue( e, &q ) ;
            break ;
         case 'd' :
            q_dequeue( &q, &e ) ;
            printf( "Entferntes Element: " ) ;
            q_datentyp_ausgeben( e ) ;
            printf( "\n" ) ;
            break ;
         case 'e' :
            printf( "q_empty = %s\n",
               q_empty( q ) ? "TRUE" : "FALSE" ) ;
            break ;
         case 'q' :
            weiter = FALSE ;
            break ;
      }
      q_write( q ) ;
      getchar() ;            /* <RETURN> uebergehen */
      printf( "\n" ) ;
   }

   return 0 ;
}
