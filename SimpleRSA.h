#ifndef SIMPLERSA_H
#define SIMPLERSA_H

class simpleRSA {
  public:
    simpleRSA(unsigned long p1, unsigned long q1, unsigned long e1);
    unsigned long encode(char c);
    char decode (unsigned long c);
  protected:
    unsigned long modInverse(int a, int m);
    unsigned long modExp (unsigned long base, unsigned long exp, unsigned long mod);
  private:
    const unsigned long p, q, e, n, t;
    unsigned long d;
  protected:

};

#endif
