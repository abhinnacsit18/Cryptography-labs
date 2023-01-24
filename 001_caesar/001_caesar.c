//caesar cipher
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
//function prototypes
void encrypt_caesar();
void decrypt_caesar();
//main
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
            encrypt_caesar();
         break;
         case 2:
            decrypt_caesar();
         break;
         case 3:
         exit(-1);
      }
   }
}
//function definitions
void encrypt_caesar()
{
   fflush(stdin);//because of scanf-gets problem due to \n
   int i, key;  
   char plain_text[100], cipher_text[100], c;
   printf("\nEnter the plaintext message (alphabets only): ");
   gets(plain_text);
   printf("\nEnter the key: ");
   scanf("%d", &key);   
   for(i = 0; plain_text[i]!='\0'; ++i)
   {
      c = plain_text[i];
      if((c >= 'a' && c <= 'z'))
      {
         //making sure that the text is rotated if it overflows from z
         cipher_text[i] = (c - 'a' + key) % 26 + 'a';
      }
      else if((c >= 'A' && c <= 'Z'))
      {
         //making sure that the text is rotated if it overflows from Z
         cipher_text[i] = (c - 'A' + key) % 26 + 'A';
      }
      //not implemented for numeric data
   }
   cipher_text[i] = '\0';
   printf("\nEncrypted plaintext message is: %s", cipher_text);
}
void decrypt_caesar()
{
   fflush(stdin);
   int i, key, x;  
   char plain_text[100], cipher_text[100], c;
   printf("\nEnter ciphertext to decrypt (alphabets only): ");
   gets(cipher_text);
   printf("\nEnter Key : ");
   scanf("%d", &key);
   for(i = 0; cipher_text[i] != '\0'; ++i)
   {
      c = cipher_text[i];
      if((c >= 'a' && c <= 'z'))
      {
         //managing unnderflow by mod operation
         c = (c - 'a' - key) % 26;
         if(c < 0)
         {
            c = c + 26;
         }
         c = c + 'a';    
      }
      else if((c >= 'A' && c <= 'Z'))
      {
         c = (c - 'A' - key) % 26;
         if(c < 0)
         {
            c = c + 26;
         }
         c = c + 'A'; 
      }
      plain_text[i] = c;
   }
   plain_text[i] = '\0';
   printf("Decrypted plaintext from ciphertext is: %s", plain_text);
}