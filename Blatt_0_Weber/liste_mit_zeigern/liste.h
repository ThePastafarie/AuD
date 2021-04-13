/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2020/03/20                           */
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
   typedef struct l_knoten {
     L_datentyp l_daten ;
     struct l_knoten *l_next ;
                    /* Zeiger auf naechstes Element */
   } L_knoten ;

     /* Liste besteht aus Zeiger auf Anfang, auf
        aktuellen Knoten und (zur Vereinfachung
        einiger Operationen) auf dessen Vorgaenger */
   typedef struct {
      L_knoten *anf ;
      L_knoten *pos ;
      L_knoten *pos_vorg ;
   } Liste ;

      /* Deklarationen der Listenoperationen */
   
   void l_create( Liste *l ) ;
   void l_insert( L_datentyp e, Liste *l ) ;
   void l_delete( Liste *l, L_datentyp *e ) ;
   void l_reset( Liste *l ) ;
   void l_advance( Liste *l ) ;
   Boolean l_out_of_list( Liste l ) ;
   void l_write( Liste l ) ;
#endif
