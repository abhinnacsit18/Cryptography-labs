#include <stdio.h>
#include<conio.h>
#include <ctype.h>
#include <string.h>
//function prototypes
void encrypt_vignere();
void decrypt_vignere();
// main
int main()
{
   int choice;
   while(1)
   {
      //menu
      printf("\nEnter choice:");
      printf("\n[1] Encrypt");
      printf("\n[2] Decrypt");
      printf("\n[3] Exit");
      printf("\n");
      scanf("%d", &choice);
      switch(choice)
      {
         case 1:
            encrypt_vignere();
         break;
         case 2:
            decrypt_vignere();
         break;
         case 3:
         exit(-1);
      }
   }
}
//functiton definintions
void encrypt_vignere()
{
    unsigned int i,j;
    char c, input[50], key[10];
    printf("\n\nEnter plaintext (without spaces): ");
    scanf("%s",input);
    printf("\nEnter key: ");
    scanf("%s",key);
    printf("\nThe ciphertext is: ");
    for(i = 0 ,j = 0; i < strlen(input); i++, j++) 
    {
        //making key repeat if key size < plaintext
        if(j >= strlen(key))
        { 
            j=0;
        }
        c = 65 + (((toupper(input[i]) - 65) + (toupper(key[j]) - 65)) % 26);
        printf("%c", c);
    }
}
void decrypt_vignere()
{
    unsigned int i,j;
    char c, input[50],key[10];
    int v;
    printf("\n\nEnter cipher text (without spaces): ");
    scanf("%s",input);
    printf("\n\nEnter the key: ");
    scanf("%s",key);
    printf("\nThe decrypted plaintext is: ");
    for(i = 0, j = 0; i < strlen(input); i++, j++)
    {
         //making key repeat if key size < ciphertext
        if(j >= strlen(key))
        { 
            j=0; 
        }
        v = (toupper(input[i]) - 64) - (toupper(key[j]) - 64);
        //managinng undereflow from A to rotate to Z
        if( v < 0)
        {
            v = v * (-1);
        }
        c = 65 + (v % 26);
        printf("%c", c);
    }
}