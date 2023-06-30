#include "TCRT5000.h"

int a[8];
int d[8];
int lt = 300;
int ht = 900;

void sensor () {
  for (int x = 0; x < 8; x++) {
    digitalWrite (10, int (x % 2));
    digitalWrite (11, int ((x / 2)) % 2);
    digitalWrite (12, int (x / 4));
    a [x] = analogRead(A0);
  }

  for (int i = 0; i < 8; i++) {
    int t = (ht + lt) / 2;
    if (a[i] > t) {
      d[i] = 1 ;
    }
    else {
      d[i] = 0;
    }
    Serial.print (d[i]);
    Serial.print ("|");
    Serial.print (a[i]);
    Serial.print ("\t");
  }
  Serial.println();
}
