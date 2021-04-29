/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2004/04/21                           */
/*                                                  */
/* Dieses Header-File stellt eine mit einem Feld    */
/* implementierte Queue bereit.                     */
/****************************************************/

#ifndef QUEUE_H
   #define QUEUE_H

   #include "boolean.h"    /* fuer Datentyp Boolean */
   #include "q_datentyp.h"       /* fuer Q_datentyp */

   #define Q_SIZE 50     /* Maximallaenge der Queue */

            /* Queue besteht aus Feld von Elementen
               sowie "Zeiger auf" Anfang und Ende   */
   typedef struct {
      Q_datentyp elemente[ Q_SIZE ] ;
      int head ;
      int tail ;
   } Queue ;

      /* Deklarationen der Queue-Operationen */

   void q_create( Queue *q ) ;
   void q_enqueue( Q_datentyp e, Queue *q ) ;
   void q_dequeue( Queue *q, Q_datentyp *e ) ;
   Boolean q_empty( Queue q ) ;
   void q_write( Queue q ) ;
#endif
