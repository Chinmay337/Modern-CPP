#include "Class.h"
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cout << "C++ Standard: " << __cplusplus << std::endl;

  // Class and Object Method Call
  World Planet(5);
  Planet.greet();

  return 0;
}

