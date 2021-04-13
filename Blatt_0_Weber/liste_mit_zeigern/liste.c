/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2004/04/21, aktualisiert 2020/03/20  */
/*                                                  */
/* Implementierung der Listenoperationen.           */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"       /* fuer Datentyp Boolean */
#include "l_datentyp.h"          /* fuer L_datentyp */
#include "liste.h"               /* fuer Konsistenz */

/* ------------------------------------------------ */

/* Erzeugt eine leere einfach verkettete Liste l. */

void l_create( Liste *l )
{
   l->anf = NULL ;
   l->pos = NULL ;
   l->pos_vorg = NULL ;
}

/* ------------------------------------------------ */

/* Fuegt ein neues Element mit Eintrag e an der
   aktuellen Position der Liste l ein.          */

void l_insert( L_datentyp e, Liste *l )
{
      /* Speicherplatz fuer neuen Knoten beschaffen
         und den von malloc gelieferte void-Pointer
         ("Zeiger auf irgendwas") in einen
         "Zeiger auf L_Knoten" umwandeln ("cast")   */
   L_knoten *neu = (L_knoten*)
                        malloc( sizeof( L_knoten ) ) ;

   if ( neu == NULL ) {
      printf( "### Fehler: Kein Speicher mehr !\n" ) ;
      exit( EXIT_FAILURE ) ;
   }

        /* Daten in neues Listen-Element eintragen: */
   neu->l_daten = e ;
                       /* Rest der Liste anhaengen: */
   neu->l_next = l->pos ;

                 /* neuen Knoten in Liste einbinden */
   if ( l->pos == l->anf )
      l->anf = neu ;             /* am Listenanfang */
   else
      l->pos_vorg->l_next = neu ;       /* anderswo */

         /* neuer Knoten liegt vor Einfuegeposition */
   l->pos_vorg = neu ;
}

/* ------------------------------------------------ */

/* Loescht das Listenelement an der aktuellen
   Zeigerposition pos und liefert seinen Inhalt in
   *e zurueck.                                     */

void l_delete( Liste *l, L_datentyp *e )
{
   L_knoten *weg = l->pos ;
                   /* zeigt auf wegfallenden Knoten */

   if ( l_out_of_list( *l ) )
      printf( "### Fehler: Zeiger pos zeigt nicht "
              "auf ein Listenelement\n" ) ;
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

/* Setzt den pos-Zeiger der Liste auf den Anfang
   zurueck.                                      */

void l_reset( Liste *l )
{
   l->pos = l->anf ;
   l->pos_vorg = NULL ;
}

/* ------------------------------------------------ */

/* Bewegt den pos-Zeiger der Liste um einen Knoten
   vorwaerts.                                      */

void l_advance( Liste *l )
{
   if ( l->pos == NULL )
      printf( "### Fehler: Bereits am Ende\n" ) ;
   else {
      l->pos_vorg = l->pos ;
      l->pos = l->pos->l_next ;
   }
}

/* ------------------------------------------------ */

/* Zeigt der aktuelle Zeiger ueber das Listenende
   hinaus ?                                       */

Boolean l_out_of_list( Liste l )
{
   return ( l.pos == NULL ) ;
}

/* ------------------------------------------------ */

/* Gibt die Eintraege der Liste l aus. */

void l_write( Liste l )
{
   L_knoten *p ;   /* zeigt auf einen Listen-Knoten */

   printf( "Liste: (" ) ;
   p = l.anf ;
   while ( p != NULL ) {
      l_datentyp_ausgeben( p->l_daten ) ;
      p = p->l_next ;
   }
   printf( " )\n" ) ;
}

