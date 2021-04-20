/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2004/04/21                           */
/*                                                  */
/* Implementierung der Listenoperationen.           */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"       /* fuer Datentyp Boolean */
#include "l_datentyp.h"          /* fuer L_datentyp */
#include "dcl.h"               /* fuer Konsistenz */

/* ------------------------------------------------ */

/* Erzeugt eine leere einfach verkettete Liste l. */

void dcl_create( Liste *l )
{
   l->anf = NULL ;
   l->pos = NULL ;   
   l->pos_vorg = NULL ;
}

/* ------------------------------------------------ */

/* Loescht das Listenelement an der aktuellen
   Zeigerposition pos und liefert seinen Inhalt in
   *e zurueck.                                     */

void dcl_delete( Liste *l, L_datentyp *e )
{
   DCL_knoten *weg = l->pos ;
                   /* zeigt auf wegfallenden Knoten */

   if ( dcl_out_of_list( *l ) )
      printf( "Fehler: Zeiger pos zeigt nicht auf ein Listenelement\n" ) ;
   else {
	*e = weg->l_daten ;

                   /* Element aus Liste ausklinken: */
      if ( l->pos_vorg == NULL )
         l->anf = weg->l_next ;
      else
         l->pos_vorg->l_next = weg->l_next ;

	     /* Positionszeiger auf Nachfolger setzen */
	l->pos = weg->l_next ;

	            /* Speicher des Knotens freigeben */
      free( weg ) ;
   }
}

/* ------------------------------------------------ */

/* Fuegt ein neues Element mit Eintrag e an der
   aktuellen Position der Liste l ein.          */

void dcl_insert( L_datentyp e, Liste *l )
{
	/* Speicherplatz fuer neuen Knoten beschaffen */
   DCL_knoten *neu = (DCL_knoten*)
                        malloc( sizeof( DCL_knoten ) ) ;

   if ( neu == NULL ) {
      printf( "Fehler: Kein Speicher mehr !\n" ) ;
      exit( EXIT_FAILURE ) ;
   }

        /* Daten in neues Listen-Element eintragen: */
   neu->l_daten = e ;
                       /* Rest der Liste anhaengen: */
   neu->l_next = l->pos ;
   neu->l_prev = l->pos_vorg ;

                 /* neuen Knoten in Liste einbinden */
   if ( l->pos != NULL ){
      l->pos->l_prev = neu ;
   }
   if( l->pos_vorg != NULL ){
      l->pos_vorg->l_next = neu ;
   }

   if ( l->pos == l->anf ){
      l->anf = neu ;
   }

	   /* neuer Knoten liegt vor Einfuegeposition */
   l->pos_vorg = neu ;
}

/* ------------------------------------------------ */

/* Zeigt der aktuelle Zeiger ueber das Listenende
   hinaus ?                                       */

Boolean dcl_out_of_list( Liste l )
{
   return ( l.pos == NULL ) ;
}

/* ------------------------------------------------ */

/* Setzt den pos-Zeiger der Liste auf den Anfang
   zurueck.                                      */

void dcl_reset( Liste *l )
{
   l->pos = l->anf ;
   l->pos_vorg = NULL ;
}

/* ------------------------------------------------ */

/* Bewegt den pos-Zeiger der Liste um einen Knoten
   vorwaerts.                                      */

void dcl_advance( Liste *l )
{
   if ( l->pos == NULL )
      printf( "Fehler: Bereits am Listenende\n" ) ;
   else {
      l->pos_vorg = l->pos ;
      l->pos = l->pos->l_next ;
   }
}

/* ------------------------------------------------ */

/* Bewegt den pos-Zeiger der Liste um einen Knoten
   vorwaerts.                                      */

void dcl_retract( Liste *l )
{
   if ( l->pos_vorg == NULL )
      printf( "Fehler: Bereits am Listenanfang\n" ) ;
   else {
      l->pos = l->pos_vorg ;
      l->pos_vorg = l->pos_vorg->l_prev ;
   }
}
