#include <iostream>
#include <string.h>
//#define DEBUG_PRINT
#include "texasholdem.h"

using namespace std;

unsigned int previousBet;

int myFunction( struct Game * game, struct Player * player, unsigned int totalBet )
{
    PokerRank temp = getMyHandRank( player->hand );
    if( table[0] == nullptr )
    { //tafel is leeg, begin van ronde
        previousBet = totalBet;
        if( totalBet > game->blind * 3 )
        { //someone is bluffing from the start
            return( -1 );
        }
    }
    if( temp.category >= THREE_OF_A_KIND )
    {
        return( player->chips );
    }
    if( totalBet > previousBet * 2 )
    {
        return( -1 );
    }
    return( 0 );
}

unsigned int previousBetNoob;

int willYouRaise( struct Game * game, struct Player * player, unsigned int totalBet )
{
    /*if( player->ID == 0 )
    {
        printf( "%s %d", player->name, player->ID );
        printHand( player->hand );
        system( "pause" );
    }
    if( strcmp( player->name, "Alice" ) )
    {
        printHand( player->hand );
    }*/

    switch( player->ID )
    {
    case 0:
        return( myFunction( game, player, totalBet ) );
        break;
    case 1:
    {
        PokerRank temp = getMyHandRank( player->hand );
        if( temp.category >= THREE_OF_A_KIND )
        {
            return( player->chips );
        }
        return( 0 );
        break;
    }
    case 2:
        if( table[0] == nullptr )
        { //tafel is leeg, begin van ronde
            previousBetNoob = totalBet;
        }
        if( totalBet > previousBetNoob * 2 )
        {
            return( -1 );
        }
        previousBetNoob = totalBet;
        return( 0 );
        break;
    case 3:
        if( totalBet > ( player->chips / 10 ) )
        {
            return( -1 );
        }
        else
        {
            return( 0 );
        }
        break;
    case 4:
        if( player->hand->cards[0]->rank == 1 || player->hand->cards[1]->rank == 1 )
        { //indien 1 van de 2 handkaarten aas is
            return( player->chips / 10 );
        }
        else
        {
            return( -1 );
        }
    case 5:
        if( player->hand->cards[0]->suit == player->hand->cards[1]->suit )
        {
            if( table[0] == nullptr )
            { //pas gedeeld, nog geen kaart op tafel
                return( 10 );
            }
            if( table[3] == nullptr )
            { //4de kaart ligt er nog niet
                if( player->hand->cards[0]->suit == table[0]->suit || player->hand->cards[0]->suit == table[1]->suit || player->hand->cards[0]->suit == table[2]->suit )
                {
                    return( 100 );
                }
            }
            if( totalBet > player->bet + 5 )
            {
                return( -1 );
            }
            return( 0 );
        }
        else
        {
            return( -1 );
        }
    default:
        return( 0 );
        break;
    }
    return( 0 );
}

int main( void )
{
    Game game;
    makeNewDeck( &game );

    Player p1;
    strcpy( p1.name, "Alice" );
    p1.ID = 1;
    Player p2;
    strcpy( p2.name, "Bob" );
    p2.ID = 2;
    Player p3;
    strcpy( p3.name, "Carla" );
    p3.ID = 3;
    Player p4;
    strcpy( p4.name, "Danny" );
    p4.ID = 4;
    Player p5;
    strcpy( p5.name, "Eric" );
    p5.ID = 5;
    Player p6;
    strcpy( p6.name, "Fuhrer" );
    p6.ID = 0;


    addPlayerToGame( &game, &p1 );
    addPlayerToGame( &game, &p2 );
    addPlayerToGame( &game, &p3 );
    addPlayerToGame( &game, &p4 );
    addPlayerToGame( &game, &p5 );
    addPlayerToGame( &game, &p6 );

    playGame( &game, 1 );
    printf( "The winner is %s with %d chips !", game.players[0]->name, game.players[0]->chips );
    return 0;
}

