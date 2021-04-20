/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 25.04.2000                      */
/* Aktualisiert: Bruno Lang, 2003/04/28, 2004/04/21 */
/*                                                  */
/* Hier werden die Funktionen einer (einfach        */
/* verketteten) Liste getestet.                     */
/*                                                  */
/* Der Typ der Listeneintraege ist zunaechst int,   */
/* er ist in Anwendungen der Liste jeweils          */
/* ANZUPASSEN.                                      */
/*                                                  */
/* Implementierung der Liste mit Zeigern.           */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"       /* fuer Datentyp Boolean */
#include "l_datentyp.h"          /* fuer L_datentyp */
#include "liste.h"        /* fuer Listenoperationen */

/* ------------------------------------------------ */

/* Hauptprogramm zum Testen der Listenoperationen */

int main( void )
{
   Liste l;
   L_datentyp e ;
             /* einzufuegende bzw. geloeschte Daten */
   char c ;
        /* Auswahl einer moeglichen Listenoperation */
   Boolean weiter = TRUE ;    /* Programm beenden ? */

   l_create( &l ) ;

   while ( weiter ) {

         /* Menue ausgeben ... */

//      printf( "c [create]  Liste erzeugen\n" ) ;
      printf( "i [insert]  Element einfuegen\n" ) ;
      printf( "d [delete]  Element entfernen\n" ) ;
      printf( "o [out]     out_of_list ?\n" ) ;
      printf( "r [reset]   pos-Zeiger\n" ) ;
      printf( "a [advance] pos-Zeiger\n" ) ;
      printf( "q [quit]    Programm verlassen\n" ) ;

         /* Auswahl treffen und Aktion ausfuehren */

      c = getchar() ;
      switch( c ) {
         case 'c' :
            l_create( &l ) ;
            break ;
         case 'i' :
            l_datentyp_eingeben( &e ) ;
            l_insert( e, &l ) ;
            break ;
         case 'd' :
            l_delete( &l, &e ) ;
            printf( "Entferntes Element: " ) ;
            l_datentyp_ausgeben( e ) ;
            printf( "\n" ) ;
            break ;
         case 'o' :
            printf( "l_out_of_list = %s\n",
            l_out_of_list( l ) ? "TRUE" : "FALSE" ) ;
            break ;
         case 'r' :
            l_reset( &l ) ;
            break ;
         case 'a' :
            l_advance( &l ) ;
            break ;
         case 'q' :
            weiter = FALSE ;
            break ;
      }
      l_write( l ) ;
      getchar() ;            /* <RETURN> uebergehen */
      printf( "\n" ) ;
   }

   return 0 ;
}
