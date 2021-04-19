/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2004/04/21                           */
/*                                                  */
/* Dieses Header-File stellt den Datentyp fuer      */
/* Listeneintraege sowie Ein- und Ausgabefunktionen */
/* fuer diesen Datentyp bereit.                     */
/****************************************************/

#ifndef L_DATENTYP_H
   #define L_DATENTYP_H

   typedef int L_datentyp ;
               /* Typ der Listeneintraege, ANPASSEN */

      /* Ein- und Ausgabeoperationen */

   void l_datentyp_eingeben( L_datentyp *e ) ;
   void l_datentyp_ausgeben( L_datentyp e ) ;
#endif
