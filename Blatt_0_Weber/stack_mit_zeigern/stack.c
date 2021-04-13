/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2020/03/21                           */
/*                                                  */
/* Implementierung der Stack-Operationen.           */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"       /* fuer Datentyp Boolean */
#include "s_datentyp.h"          /* fuer S_datentyp */
#include "stack.h"               /* fuer Konsistenz */

/* ------------------------------------------------ */

/* Erzeugt einen leeren Stacks s. */

void s_create( Stack *s )
{
  *s = NULL ;
}

/* ------------------------------------------------ */

/* Legt den Eintrag e auf den Stack s. */

void s_push( S_datentyp e, Stack *s )
{
      /* Speicherplatz fuer neuen Knoten beschaffen */
   S_knoten *neu = (S_knoten*)
                        malloc( sizeof( S_knoten ) ) ;

   if ( neu == NULL ) {
      printf( "### Fehler: Kein Speicher mehr !\n" ) ;
      exit( EXIT_FAILURE ) ;
   }

   neu->s_daten = e ;
   neu->s_next = *s ;
   *s = neu ;
}

/* ------------------------------------------------ */

/* Liefert oberstes Element des Stacks in *e
   zurueck und entfernt es aus dem Stack.    */

void s_pop( Stack *s, S_datentyp *e )
{
   S_knoten *pegel ;   /* zeigt auf obersten Knoten */

   if ( s_empty( *s ) ) {
      printf( "### Fehler: Stack bereits leer !\n" ) ;
   }
   else {
      pegel = *s ;
      *e = pegel->s_daten ;
      *s = pegel->s_next ;    
      free( pegel ) ;
   }
}

/* ------------------------------------------------ */

/* Ist der Stack s leer ? */

Boolean s_empty( Stack s )
{
   return ( s == NULL ) ;
}

/* ------------------------------------------------ */

/* Gibt die Eintraege des Stacks s aus. */

void s_write( Stack s )
{
   S_knoten *p ;    /* zeigt auf einen Stack-Knoten */

   printf( "Stack: (" ) ;
   p = s ;
   while ( p != NULL ) {
      s_datentyp_ausgeben( p->s_daten ) ;
      p = p->s_next ;
   }
   printf( " )\n" ) ;
}
