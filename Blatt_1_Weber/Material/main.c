/****************************************************/
/* Rahmenprogramm				  . */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"       /* fuer Datentyp Boolean */
#include "l_datentyp.h"          /* fuer L_datentyp */
#include "dcl.h"        /* fuer Listenoperationen */

/* ------------------------------------------------ */

/* Hauptprogramm zum Testen der Listenoperationen */

int main( void )
{
   Liste l;
   dcl_create( &l );

   L_datentyp e;
   L_datentyp sum = 0;

   //Eingabe
   do{
      l_datentyp_eingeben(&e);
      if(e != 0){
         dcl_insert(e, &l);
      }
      sum += e;
   }while(e != 0);

   //Ausgabe
   printf("Summe der Zahlen: %d\n", sum);

   printf("Summe in umgekerter Reinenfolge: \n");
   do{
      dcl_retract(&l);
      e = l.pos->l_daten;
      l_datentyp_ausgeben(e);
   }while (l.pos_vorg != NULL);
   printf("\n");

   printf("Summe in ursprünglicher Reinenfolge: \n");
   e = l.pos->l_daten;
      l_datentyp_ausgeben(e);
   do{
      dcl_advance(&l);
      e = l.pos->l_daten;
      l_datentyp_ausgeben(e);
   }while(l.pos->l_next != NULL);
   printf("\n");
   
   
/***********************************************************/   

/* HIER ANPASSEN */

/***********************************************************/   

   return 0 ;
}