#include <stdio.h>
#include <string.h>
 
#define d 10
 
void rabinKarp(char pattern[], char text[], int q) {
  int m = strlen(pattern);
  int n = strlen(text);
  int i, j;
  int phash = 0;
  int thash = 0;
  int h = 1;
 
  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;
 
  for (i = 0; i < m; i++) {
    phash = (d * phash + pattern[i]) % q;
    thash = (d * thash + text[i]) % q;
  }
 
  for (i = 0; i <= n - m; i++) {
    if (phash == thash) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;
      }
      if (j == m)
        printf("Pattern is found at position:  %d \n", i + 1);
    }
    if (i < n - m) {
      thash = (d * (thash - text[i] * h) + text[i + m]) % q;
      if (thash < 0)
        thash = (thash + q);
    }
  }
}
 
void main() {
  char text[] = "ABCCDDAEFG";
  char pattern[] = "CDD";
  int q = 13;
  rabinKarp(pattern, text, q);
}
