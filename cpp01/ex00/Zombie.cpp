#include "Zombie.hpp"

Zombie::Zombie(const std::string& local_name) {
    this->name = local_name;
}

Zombie::~Zombie() {
    std::cout << this->name + " : Died BraiiiiiiinnnzzzZ" << std::endl;
}

void Zombie::announce() {
    std::cout << this->name + " : BraiiiiiiinnnzzzZ..." << std::endl;
}
