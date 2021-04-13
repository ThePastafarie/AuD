/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2004/04/21                           */
/*                                                  */
/* Implementierung der Ein- und Ausgabefunktionen   */
/* fuer den Datentyp Q_datentyp.                    */
/****************************************************/

#include <stdio.h>            /* fuer printf, scanf */
#include "q_datentyp.h"          /* fuer Q_datentyp */

/* ------------------------------------------------ */

/* Eingabe eines Elements vom Typ Q_datentyp. */

void q_datentyp_eingeben( Q_datentyp *e )
{
   printf( "Eintrag eingeben :\n" ) ;
   scanf( "%d", e ) ;                   /* ANPASSEN */
}

/* ------------------------------------------------ */

/* Ausgabe eines Elements vom Typ Q_datentyp. */

void q_datentyp_ausgeben( Q_datentyp e )
{
   printf( " %d", e ) ;                 /* ANPASSEN */
}

