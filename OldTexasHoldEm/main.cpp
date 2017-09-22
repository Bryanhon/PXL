#include <iostream>
#include "texasholdem.h"

using namespace std;

int willYouRaise( struct Game * game, struct Player * player, unsigned int totalBet )
{
	return( 0 );
}

int main( void )
{
	Game game;
	makeNewDeck( &game );

	Player p1;
	strcpy( p1.name, "Alice" );
	p1.ID = 0;
	Player p2;
	strcpy( p2.name, "Bob" );
	p1.ID = 1;
	Player p3;
	strcpy( p3.name, "Carla" );
	p1.ID = 2;
	Player p4;
	strcpy( p4.name, "Danny" );
	p1.ID = 1;
	Player p5;
	strcpy( p5.name, "Eric" );
	p1.ID = 2;
	Player p6;
	strcpy( p6.name, "Fuhrer" );
	p1.ID = 0;


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

