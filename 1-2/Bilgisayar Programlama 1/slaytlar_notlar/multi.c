/* Fig. 7.24: fig07_24.c
   Card shuffling dealing program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle( int [][ 13 ] );
void deal( const int [][ 13 ], const char *[], const char *[] );

int main()
{
   const char *suit[ 4 ] =  
      { "Hearts", "Diamonds", "Clubs", "Spades" };
   const char *face[ 13 ] = 
      { "Ace", "Deuce", "Three", "Four",
        "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" };
   int deck[ 4 ][ 13 ] = { 0 };

   srand( time( 0 ) );

   shuffle( deck );
   deal( deck, face, suit );

   return 0;
}

void shuffle( int wDeck[][ 13 ] )
{
   for (int card = 0; card < 52; card++ )
      wDeck[card/13][card%13] = card +1;
}

void deal( const int wDeck[][ 13 ], const char *wFace[],
           const char *wSuit[] )
{
   int cardvalue, row, column;

   for ( row = 0; row <= 3; row++ )
      for ( column = 0; column <= 12; column++ ){
         cardvalue = wDeck[ row ][ column ];
         printf( "%5s of %-8s\n", wFace[ (cardvalue-1)%13 ], wSuit[ (cardvalue-1)/13 ]);

      }              
}


