#include "maze.h"
#include <iostream>

int main() {
    Maze labirent("Harita.txt");
    if (labirent.labirentiCoz()) {
        std::cout << "cozum bulunamadư" << std::endl;
    } else {
        std::cout << "cozum bulundu .." << std::endl;
    }
    return 0;
}
