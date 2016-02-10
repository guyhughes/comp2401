#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define AZ 26

void encryptCaesar(char*, unsigned char);
void decryptCaesar(char*, unsigned char);
void toUpper(char*);
char antirotX(char c, unsigned char key);
char rotX(char,unsigned char);

int main() {
  char plain[] = "Friends, Romans, countrymen, lend me your ears";
  char cipher[] = "Mvez, mzuz, mztz (Z trdv, Z jrn, Z tfehlvivu)";

  printf("%s\n", plain);
  toUpper(plain);
  printf("%s\n", plain);
  encryptCaesar(plain, 5);
  printf("%s\n", plain);
  decryptCaesar(plain, 5);
  printf("%s\n", plain);

  /* int k=5; */
  /* for (char i='A'; i < 'A'+AZ; ++i){ */
    /* printf("%d%c +%d → %d%c \n",i,i,k,rotX(i,k),rotX(i,k)); */
    /* [> printf("%d%c -%d → %d%c \n",i,i,k,antirotX(i,k),antirotX(i,k)); <] */
  /* } */
  /* return 0; */
}

void toUpper(char *text) {
  int i = 0;
  while (text[i] != '\0') {
    if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] -= 32;
    }
    i++;
  }
}

void encryptCaesar(char *plaintext, unsigned char key) {
  int i = 0;
  toUpper(plaintext);
  while (plaintext[i] != '\0'){
    /* assert(plaintext[i] >= 'A' && plaintext[i] <= 'Z'); */
    plaintext[i] = rotX(plaintext[i],key);
    ++i;
  }


  /* Implement the rest of the function */

}

void decryptCaesar(char *ciphertext, unsigned char key) {
  int i = 0;
  toUpper(ciphertext);
  while (ciphertext[i] != '\0'){
    ciphertext[i] = antirotX(ciphertext[i],key);
    ++i;
  }

  /* Implement the rest of the function */

}
char rotX(char c, unsigned char key){
  char x = c+key;
  if(!('A' <= c && c <= 'Z'))
    return c;

  if ( 'Z' < x  ){
    return abs('Z'-x)+'A'-1;
  }
  return x;
}
char antirotX(char c, unsigned char key){
  char x = c-key;
  if(!('A' <= c && c <= 'Z'))
    return c;

  if (x < 'A'){
    return 'Z'-abs('A'-x)+1;
  }
  return x;
}
