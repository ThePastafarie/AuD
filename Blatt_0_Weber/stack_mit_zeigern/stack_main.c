/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 25.04.2000                      */
/* Aktualisiert: Bruno Lang, 2003/04/25, 2004/04/21 */
/*                                                  */
/* Hier werden die Funktionen eines Stack getestet. */
/*                                                  */
/* Der Typ der Stack-Eintraege ist zunaechst int,   */
/* er ist in Anwendungen des Stacks jeweils         */
/* ANZUPASSEN.                                      */
/*                                                  */
/* Implementierung des Stacks mit Zeigern.          */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"       /* fuer Datentyp Boolean */
#include "s_datentyp.h"          /* fuer S_datentyp */
#include "stack.h"        /* fuer Stack-Operationen */

/* ------------------------------------------------ */

/* Hauptprogramm zum Testen der Stack-Operationen */

int main( void )
{
   Stack s ;
   S_datentyp e ;
             /* einzufuegende bzw. geloeschte Daten */
   char c ;
         /* Auswahl einer moeglichen Stackoperation */
   Boolean weiter = TRUE ;    /* Programm beenden ? */

   while ( weiter ) {

         /* Menue ausgeben ... */

      printf( "c [create]  Stack erzeugen\n" ) ;
      printf( "i [push]    Element einfuegen\n" ) ;
      printf( "d [pop]     Element entfernen\n" ) ;
      printf( "e [empty]   Stack leer ?\n" ) ;
      printf( "q [quit]    Programm verlassen\n" ) ;

         /* Auswahl treffen und Aktion ausfuehren */

      c = getchar() ;
      switch( c ) {
         case 'c' :
            s_create( &s ) ;
            break ;
         case 'i' :
            s_datentyp_eingeben( &e ) ;
            s_push( e, &s ) ;
            break ;
         case 'd' :
            s_pop( &s, &e ) ;
            printf( "Entferntes Element: " ) ;
            s_datentyp_ausgeben( e ) ;
            printf( "\n" ) ;
            break ;
         case 'e' :
            printf( "s_empty = %s\n",
               s_empty( s ) ? "TRUE" : "FALSE" ) ;
            break ;
         case 'q' :
            weiter = FALSE ;
            break ;
      }
      s_write( s ) ;
      getchar() ;            /* <RETURN> uebergehen */
      printf( "\n" ) ;
   }

   return 0 ;
}
