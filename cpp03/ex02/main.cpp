#include "FragTrap.hpp"

int main( void )
{
    FragTrap aysha( "aysha" );
    FragTrap aysha2( aysha );

    aysha.attack( "the air" );
    aysha.takeDamage( 10 );
    aysha.beRepaired( 10 );
    aysha.highFivesGuys();

    return EXIT_SUCCESS;
}