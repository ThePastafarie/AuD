/****************************************************/
/* Vorlesung Algorithmen und Datenstrukturen        */
/* Bruno Lang, 2004/04/21                           */
/*                                                  */
/* Dieses Header-File stellt die Typdefinitionen    */
/* fuer den im Huffman-Algorithmus verwendeten      */
/* Binaerbaum bereit.                               */
/****************************************************/

#ifndef BINAERBAUM_H
   #define BINAERBAUM_H

            /* im Binaerbaum zu speichernden Daten,
               hier: int (Nr. des Wortes)           */
   typedef int BB_datentyp ;

   typedef struct bb_knoten {
      BB_datentyp bb_daten ;
                       /* im Knoten abgelegte Daten */
      struct bb_knoten *bb_lsohn ;
      struct bb_knoten *bb_rsohn ;
              /* Zeiger auf linken und rechten Sohn */
   } BB_knoten ;
 
              /* Binaerbaum = Zeiger auf die Wurzel
                 des Baums; leerer Baum: b == NULL  */
   typedef BB_knoten * Binaerbaum ;
#endif
