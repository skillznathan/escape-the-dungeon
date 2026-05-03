#include "Player.h"
#include <iostream>

int main() {
    std::string name;

    std::cout << "Enter player name: ";
    std::getline(std::cin, name);

    Player player(name);

    std::cout << "Player created!\n";
    std::cout << "Name: " << player.getName() << "\n";
    std::cout << "Health: " << player.getHealth() << "\n";

    return 0;
}