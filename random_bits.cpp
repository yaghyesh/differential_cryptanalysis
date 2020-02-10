#include <bits/stdc++.h>
using namespace std;
#define number_of_text 100000

int main(){
  long long int r;
  char s[64];
  FILE *fr;
  fr = fopen("random_bits.txt","w+");
  for(int i=0; i<number_of_text; i++){
    for(int j=0; j<64; j++){
      r = rand()%2; 
      s[j] = r + 48;
    }
    for(int j=0; j<64; j++)
      fprintf(fr, "%c",s[j]);
    fprintf(fr, "\n");
  }
  return 0;
}