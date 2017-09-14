#include <iostream>
#include "SimpleRSA.h"

simpleRSA rsa(1619, 1523, 85);

int main () {
  char c = 'w';
  unsigned long encoded = rsa.encode(c);
  char decoded = rsa.decode(encoded);

  std::cout << "starting character: " << c << " encoded character:" << encoded << \
  " decoded character: " << decoded << std::endl;
}
