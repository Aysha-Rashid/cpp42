#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap aysha( "aysha" );
    ScavTrap aysha2( aysha );

    aysha.attack( "the air" );
    aysha.takeDamage( 10 );
    aysha.beRepaired( 10 );
    aysha.guardGate();

    return EXIT_SUCCESS;
}