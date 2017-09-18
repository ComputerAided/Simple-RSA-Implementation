#include <SimpleRSA.h>

simpleRSA rsa(1619, 1523, 85);

void setup () {
  Serial.begin(115200);
  
  char c = 'w';
  unsigned long encoded = rsa.encode(c);
  char decoded = rsa.decode(encoded);
  
  String out = "starting character: " + c + " encoded character:" + encoded + " decoded character: " + decoded;
  Serial.println(out);
}

void loop () {
  while (1);
}
