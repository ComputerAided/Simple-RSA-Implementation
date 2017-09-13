#include "SimpleRSA.h"

simpleRSA::simpleRSA(unsigned long p1, unsigned long q1, unsigned long e1) : p(p1), q(q1), n(p*q) {

}

unsigned long simpleRSA::encode (char c) {
  unsigned long E = modExp(c, e, n);
  return E;
}

char simpleRSA::decode (unsigned long c) {
  unsigned long C = modexp(c, d, n);
  return C;
}

unsigned long simpleRSA::modExp (unsigned long base, unsigned long pow, unsigned long mod) {
  unsigned long remainder;
  unsigned long x = 1;

  while (pow != 0) {
    remainder = pow % 2;
    pow = pow/2;

    if (remainder == 1)
    x = (x * base) % mod;
    base = (base * base) % mod; // New base equal b^2 % m
  }

  return x;
}
