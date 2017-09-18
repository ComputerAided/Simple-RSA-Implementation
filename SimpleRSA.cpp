#include "SimpleRSA.h"

#include <iostream>

simpleRSA::simpleRSA(unsigned long p1, unsigned long q1, unsigned long e1) : p(p1), q(q1), e(e1), n(p*q), t((p-1)*(q-1)) {
  d = modInverse(e, t);
}

unsigned long simpleRSA::encode (char c) {
  unsigned long E = modExp(c, e, n); // encode data by taking c^e mod n
  return E;
}

char simpleRSA::decode (unsigned long c) {
  unsigned long C = modExp(c, d, n); //decode data with c^d mod n
  return C;
}

// Funtion that accomplishes modular exponentiation
unsigned long simpleRSA::modExp (unsigned long base, unsigned long pow, unsigned long mod) {
  unsigned long remainder;
  unsigned long x = 1;

  while (pow != 0) {
    remainder = pow % 2;
    pow = pow/2;

    if (remainder == 1)
    x = (x * base) % mod;
    base = (base * base) % mod;
  }

  return x;
}

// function to find modular inverse of x mod n
unsigned long simpleRSA::modInverse(int a, int m)
{
    unsigned long m0 = m, t, q;
    unsigned long x0 = 0, x1 = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
       x1 += m0;

    return x1;
}
