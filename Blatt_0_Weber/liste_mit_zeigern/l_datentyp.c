/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2020/03/20                           */
/*                                                  */
/* Implementierung der Ein- und Ausgabefunktionen   */
/* fuer den Datentyp L_datentyp.                    */
/****************************************************/

#include <stdio.h>         /* fuer printf und scanf */
#include "l_datentyp.h"          /* fuer L_datentyp */

/* ------------------------------------------------ */

/* Eingabe eines Elements vom Typ L_datentyp. */

void l_datentyp_eingeben( L_datentyp *e )
{
   printf( "Eintrag eingeben :\n" ) ;
   scanf( "%d", e ) ;                   /* ANPASSEN */
}

/* ------------------------------------------------ */

/* Ausgabe eines Elements vom Typ L_datentyp. */

void l_datentyp_ausgeben( L_datentyp e )
{
   printf( " %d", e ) ;                 /* ANPASSEN */
}

