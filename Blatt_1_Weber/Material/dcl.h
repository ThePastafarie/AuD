/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2004/04/21                           */
/*                                                  */
/* Dieses Header-File stellt eine mit Zeigern       */
/* implementierte Liste bereit.                     */
/****************************************************/

#ifndef LISTE_H
   #define LISTE_H

   #include "boolean.h"    /* fuer Datentyp Boolean */
   #include "l_datentyp.h"       /* fuer L_datentyp */

              /* Element einer Liste von Eintraegen
	           vom Typ L_datentyp                 */
   typedef struct dcl_knoten {
     L_datentyp l_daten ;
     struct dcl_knoten *l_next ;
     struct dcl_knoten *l_prev ;
                    /* Zeiger auf naechstes Element */
   } DCL_knoten ;

     /* Liste besteht aus Zeiger auf Anfang, auf
        aktuellen Knoten und auf dessen Vorgaenger */
   typedef struct {
     DCL_knoten *anf ;
     DCL_knoten *pos ;
     DCL_knoten *pos_vorg ;
   } Liste ;

      /* Deklarationen der Listenoperationen */
   
   void dcl_create( Liste *l ) ;
   void dcl_insert( L_datentyp e, Liste *l ) ;
   void dcl_delete( Liste *l, L_datentyp *e ) ;
   void dcl_reset( Liste *l ) ;
   void dcl_advance( Liste *l ) ;
   void dcl_retract( Liste *l ) ;
   Boolean dcl_out_of_list( Liste l ) ; 
#endif
