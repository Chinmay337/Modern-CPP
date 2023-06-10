#include "Class.h"
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cout << "C++ Standard: " << __cplusplus << std::endl;

  // Create a new instance of the class
  World Planet(5);
  Planet.greet();

  return 0;
}

// g++ -std=c++17 main.cpp Class.cpp -o output && ./output
