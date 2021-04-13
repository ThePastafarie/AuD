/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2004/04/21                           */
/*                                                  */
/* Dieses Header-File stellt den Datentyp fuer      */
/* Queue-Eintraege sowie Ein- und Ausgabefunktionen */
/* fuer diesen Datentyp bereit.                     */
/****************************************************/

#ifndef Q_DATENTYP_H
   #define Q_DATENTYP_H

   typedef int Q_datentyp ;
               /* Typ der Queue-Eintraege, ANPASSEN */

      /* Ein- und Ausgabeoperationen */

   void q_datentyp_eingeben( Q_datentyp *e ) ;
   void q_datentyp_ausgeben( Q_datentyp e ) ;
#endif
