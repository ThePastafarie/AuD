/****************************************************/
/* Programm zur Vorlesung Algorithmen und Datenstr. */
/* Andreas Frommer, 27.4.00                         */
/* Aktualisiert: Bruno Lang, 2003/04/29, 2004/04/22 */
/*                                                  */
/* Dieses Programm bestimmt den Huffman-Code fuer   */
/* eine Menge von Woertern mit gegebenen Haeufig-   */
/* keiten. Genauer: es bestimmt einen Binaerbaum    */
/* mit minimaler gewichteter externer Pfadlaenge.   */
/*                                                  */
/* Algorithmisches Prinzip: Greedy                  */
/* Die Baeume werden in einer Queue verwaltet.      */
/*                                                  */
/* Indizierung ab 1, Komponenten 0 von Feldern      */
/* werden nicht benutzt                             */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "boolean.h"       /* fuer Datentyp Boolean */
#include "binaerbaum.h"          /* fuer Binaerbaum */
#include "q_datentyp.h"          /* fuer Q_datentyp */
#include "queue.h"                    /* fuer Queue */

#define MAX_N 50        /* Maximalzahl von Woertern */
#define WORT_LEN 20          /* maximale Wortlaenge */

int code[ MAX_N ] ;           /* Code zu einem Wort */

/* ------------------------------------------------ */

/* Gibt die dem Binaerbaum b entsprechenden Codes
   aus. w sind die zu codierenden Woerter und pos
   gibt an, wie viele Stellen des Codes bereits
   ausgefuellt sind (entspricht Rekursionstiefe).
   Der erste Aufruf erfolgt mit pos = -1.
   >>> Zugriff auf das globale Feld code, in
       das der aktuelle Code geschrieben wird <<<   */

void codes_ausgeben( Binaerbaum b, char *w[],
                     int pos )
{
   int i;

   if ( b != NULL ) {
      if ( ( b->bb_lsohn == NULL ) &&
           ( b->bb_rsohn == NULL ) ) {
            /* Blattknoten erreicht; Code ausgeben */
         printf( "Code " ) ;
         for ( i = 0 ; i <= pos ; i++ )
            printf( "%d", code[ i ] ) ;
         printf( " fuer das Wort %s\n",
                 w[ b->bb_daten ] ) ;
      }
      else {
         code[ pos + 1 ] = 0 ;
         codes_ausgeben( b->bb_lsohn, w, pos + 1 ) ;
         code[ pos + 1 ] = 1 ;
         codes_ausgeben( b->bb_rsohn, w, pos + 1 ) ;
      }
   }
}

/* ------------------------------------------------ */

/* Erzeugt einen Binaerbaum mit bzgl. m minimaler
   gewichteter externer Pfadlaenge. n ist die
   Anzahl der Woerter, m[ 1 .. n ] sind ihre
   Gewichte (die Woerter selbst werden fuer den
   Codierungsbaum nicht benoetigt), pb ist Zeiger
   auf den resultierenden Binaerbaum (Binaerbaum
   ist Zeiger auf BB_knoten).                     */ 

void codierungsbaum( int n, double m[],
                     Binaerbaum *pb )
{
   Queue q ;         /* Warteschlange fuer die noch
                        verbliebenen Teilbaeume     */
   Q_datentyp tmp ;   /* betrachteter Queue-Eintrag */
   Q_datentyp min1, min2 ;
                    /* die Teilbaeume mit kleinstem
                       bzw. zweitkleinstem Gewicht  */
   int i, j ;

      /* Woerter als einknotige Baeume
         in die Queue einfuegen        */

   q_create( &q ) ;
   for ( i = 1 ; i <= n ; i++ ) {
           /* neuen Knoten fuer Binaerbaum erzeugen */
      tmp.baum = (BB_knoten*)
                       malloc( sizeof( BB_knoten ) ) ;
      if ( tmp.baum == NULL ) {                               
         printf("Fehler: Kein Speicher mehr !\n" ) ;
         exit( EXIT_FAILURE ) ;
      }
      tmp.baum->bb_daten = i ;       /* Wort-Nummer */
      tmp.baum->bb_lsohn = NULL ;
      tmp.baum->bb_rsohn = NULL ;
      tmp.gewicht = m[ i ] ;   /* Gewicht des Baums */
      q_enqueue( tmp, &q ) ;
   }

      /* ( n - 1 )-mal die zwei leichtesten Baeume
         suchen und zusammenfassen                 */

   for ( i = 1 ; i < n ; i++ ) {
           /* leichtesten und zweitleichtesten Baum
              suchen; beginne mit den ersten beiden
              Queue-Eintraegen                      */
      q_dequeue( &q, &min1 ) ;
      q_dequeue( &q, &min2 ) ;
      if ( min1.gewicht > min2.gewicht ) {
                                     /* vertauschen */
         tmp = min1 ; 
         min1 = min2 ;
         min2 = tmp ;
      }
      for ( j = 2 ; j < n - i ; j++ ) {
             /* uebrige Baeume der Queue betrachten */
         q_dequeue( &q, &tmp ) ;
         if ( tmp.gewicht < min2.gewicht ) {
                     /* leichter als bislang zweit-
                        leichtester Baum; jenen
                        wieder in Queue aufnehmen   */
            q_enqueue( min2, &q ) ;
            if ( tmp.gewicht < min1.gewicht ) {
                              /* sogar leichter als
                                 bisher leichtester */
               min2 = min1 ;
               min1 = tmp ;
            }
            else
               min2 = tmp ;
         }
         else  /* zu gross: gleich wieder einfuegen */
            q_enqueue( tmp, &q ) ;
      }

         /* leichteste Teilbaeume unter einer
            neuen Wurzel zusammenhaengen      */
      tmp.baum = (BB_knoten*)
                       malloc( sizeof( BB_knoten ) ) ;
      if ( tmp.baum == NULL ) {  
         printf( "Fehler: Kein Speicher mehr !\n" ) ;
         exit( EXIT_FAILURE ) ;
      }  
      tmp.baum->bb_lsohn = min1.baum ;
      tmp.baum->bb_rsohn = min2.baum ;
      tmp.gewicht = min1.gewicht + min2.gewicht ;
      q_enqueue( tmp, &q ) ;
   } 

      /* der jetzt noch in der Queue stehende Baum
         ist der gesuchte Codierungsbaum           */

   q_dequeue( &q, &tmp ) ; 
   *pb = tmp.baum ;
}

/* ------------------------------------------------ */

/* Hauptprogramm */

int main( void )
{
   int n ;                    /* Anzahl der Woerter */
   char wort[ WORT_LEN ] ;   /* Puffer fuer Eingabe */
   char *w[ MAX_N + 1 ] ;    /* betrachtete Woerter */
   double m[ MAX_N + 1 ] ;   /* deren Haeufigkeiten */

   Binaerbaum b ;  /* der zu bestimmende Binaerbaum */

   int i ;

      /* Woerter und Haeufigkeiten einlesen */

   printf( "Anzahl der Woerter eingeben\n" ) ;
   scanf( "%d", &n ) ;      
   for ( i = 1 ; i <= n ; i++ ) {
      getchar() ;             /* newline ueberlesen */
      printf( "%d-tes Wort eingeben: ", i ) ;
      fgets( wort, WORT_LEN - 1, stdin ) ;
      w[ i ] = (char*) malloc( strlen( wort ) ) ;
      strncpy( w[ i ], wort, strlen( wort ) - 1 ) ;
      printf( "und dessen Haeufigkeit " ) ;
      scanf( "%lf", &m[ i ] ) ;
   }

      /* optimalen Codierungsbaum bestimmen
         und ausgeben                       */

   codierungsbaum( n, m, &b ) ;
   codes_ausgeben( b, w, -1 ) ;

   return 0 ;
}
