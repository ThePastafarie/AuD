/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2020/03/23                           */
/*                                                  */
/* Implementierung der Queue-Operationen.           */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"       /* fuer Datentyp Boolean */
#include "q_datentyp.h"          /* fuer Q_datentyp */
#include "queue.h"               /* fuer Konsistenz */

#define NIRWANA -1            /* zeigt auf "nichts" */

/* ------------------------------------------------ */

/* Erzeugt eine leere Queue. */

void q_create( Queue *q )
{
   q->head = NIRWANA ;
   q->tail = NIRWANA ;
}

/* ------------------------------------------------ */

/* Fuegt das Element e am Kopfende der Queue ein,
   sofern noch ein Platz frei ist.                */

void q_enqueue( Q_datentyp e, Queue *q )
{
   int next_pos = ( q->head + 1 ) % Q_SIZE ;
        /* wohin im Feld kommt das neue Element ?   */

   if ( next_pos == q->tail ) {
      printf( "### Fehler: Queue bereits voll !\n" ) ;
      exit( EXIT_FAILURE ) ;
   }
   else {  
      q->head = next_pos ;
                              /* Element speichern: */
      q->elemente[ q->head ] = e ;
      if ( q->tail == NIRWANA )   /* Queue war leer */
         q->tail = q->head ;
   }
}
        
/* ------------------------------------------------ */

/* Loescht das am Schwanzende der Queue stehende
   Element und liefert es in *e zurueck.         */

void q_dequeue( Queue *q, Q_datentyp *e )
{ 
   if ( q->tail == NIRWANA )
      printf( "### Fehler: Queue bereits leer !\n" ) ;
   else {
                          /* Element zurueckliefern */
      *e = q->elemente[ q->tail ] ;

      if ( q->head == q->tail ) {
         q->head = NIRWANA ;     /* Queue wird leer */
         q->tail = NIRWANA ;
      }
      else                 /* Queue wird nicht leer */
         q->tail = ( q->tail + 1 ) % Q_SIZE ; 
   }
}

/* ------------------------------------------------ */

/* Ist die Queue q leer ? */

Boolean q_empty( Queue q )
{
   return ( q.head == NIRWANA ) ;
}

/* ------------------------------------------------ */

/* Gibt die Eintraege der Queue q aus. */

void q_write( Queue q )
{
   int i ;

   printf( "Queue: Tail (" ) ;
   for ( i = q.tail ; i != q.head ;
         i = ( i + 1 ) % Q_SIZE )
      q_datentyp_ausgeben( q.elemente[ i ] ) ;
   if ( q.head != NIRWANA )
      q_datentyp_ausgeben( q.elemente[ q.head ] ) ;
   printf( " ) Head\n" ) ;
}

