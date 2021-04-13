/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2004/04/21                           */
/*                                                  */
/* Dieses Header-File stellt einen mit Zeigern      */
/* implementierten Stack bereit.                    */
/****************************************************/

#ifndef STACK_H
   #define STACK_H

   #include "boolean.h"    /* fuer Datentyp Boolean */
   #include "s_datentyp.h"       /* fuer S_datentyp */

                   /* Element einer Liste von
                      Eintraegen vom Typ S_datentyp */
   typedef struct s_knoten {
      S_datentyp s_daten ;
      struct s_knoten *s_next ;
                    /* Zeiger auf naechstes Element */
   } S_knoten ;

           /* Stack ist Zeiger auf den Listenanfang */
   typedef S_knoten *Stack ;

      /* Deklarationen der Stack-Operationen */

   void s_create( Stack *s ) ;
   void s_push( S_datentyp e, Stack *s ) ;
   void s_pop( Stack *s, S_datentyp *e ) ;
   Boolean s_empty( Stack s ) ;
   void s_write( Stack s ) ;
#endif
