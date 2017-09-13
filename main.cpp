#include <iostream>
#include "SimpleRSA.h"

simpleRSA rsa(17, 19, 15);

int main () {
  std::cout << "Hello, World" << std::endl;
  std::cout << "5028^165 mod 631 = " << rsa.modExp(5028, 165, 631) << std::endl;
  
}
