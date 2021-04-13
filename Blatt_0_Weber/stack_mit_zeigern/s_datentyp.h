/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2004/04/21                           */
/*                                                  */
/* Dieses Header-File stellt den Datentyp fuer      */
/* Stack-Eintraege sowie Ein- und Ausgabefunktionen */
/* fuer diesen Datentyp bereit.                     */
/****************************************************/

#ifndef S_DATENTYP_H
   #define S_DATENTYP_H

   typedef int S_datentyp ;
               /* Typ der Stack-Eintraege, ANPASSEN */

      /* Ein- und Ausgabeoperationen */

   void s_datentyp_eingeben( S_datentyp *e ) ;
   void s_datentyp_ausgeben( S_datentyp e ) ;
#endif
