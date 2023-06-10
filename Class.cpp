#include "Class.h"
#include <iostream>

World::World(int s) : x(s) { std::cout << "Hello World!\n"; }

void World::greet() {
  std::cout << "Class Object has -> " << x << std::endl;
  std::cout << "=====================\n";
}
