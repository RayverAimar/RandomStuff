#include <iostream>
#include <cstring>

using namespace std;

#define ASIZE 4

void preBmBc(char *x, int m, int bmBc[]) {
   int i;
   for (i = 0; i < ASIZE; ++i)
      bmBc[i] = m;
   for (i = 0; i < m - 1; ++i)
      bmBc[x[i]] = m - i - 1;
}

void HORSPOOL(char *x, int m, char *y, int n) {
   int j, bmBc[ASIZE];
   char c;
   preBmBc(x, m, bmBc);
   j = 0;
   while (j <= n - m) {
      c = y[j + m - 1];
      if (x[m - 1] == c && memcmp(x, y + j, m - 1) == 0)
         cout<<j;
      j += bmBc[c];
   }
}

int main(){
    char text[]= "GCATCGCAGAGAGTATACAGTACG";
    char pattern[]= "GCAGAGAG";
    HORSPOOL(pattern, 8, text, 24);
}