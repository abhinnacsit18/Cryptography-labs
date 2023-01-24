//hill cipher
#include<stdio.h>
#include<conio.h>
#include<math.h>
//global matrices
float mes[3][1], encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], c[3][3];
//function prototypes
void encrypt_hill();
void decrypt_hill();
void message_and_key();
void inverse_key_matrix();
//main
int main()
{
   int choice;
   while(1)
   {
      //menu
      message_and_key();
      printf("\nEnter choice:");
      printf("\n[1] Encrypt");
      printf("\n[2] Decrypt");
      printf("\n[3] Exit");
      printf("\n");
      scanf("%d", &choice);
      switch(choice)
      {
         case 1:
            encrypt_hill();
         break;
         case 2:
            decrypt_hill();
         break;
         case 3:
         exit(-1);
      }
   }
}
//function definitions
//encrypts the message
void encrypt_hill()
{
int i, j, k;
   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 1; j++)
      {
         for(k = 0; k < 3; k++)
         {
            //matrix multiplication to encrpt the message
            encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
         }
      }
   }        
   printf("\nThe encrypted message is: ");
   for(i = 0; i < 3; i++)
   {
      printf("%c", (char)(fmod(encrypt[i][0], 26) + 97)); 
   }
   printf("\n");
}
//decrypts thte message
void decrypt_hill()
{
   int i, j, k;
   inverse_key_matrix();
   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 1; j++)
      {
         for(k = 0; k < 3; k++)
         {
            decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
         }
      }
   }
   printf("\nThe decrypted message is: ");
   for(i = 0; i < 3; i++)
   {
      printf("%c", (char)(fmod(decrypt[i][0], 26) + 97));
   }
   printf("\n");
}
//taking the message to be encrypted or decrypted from user
//taking 3x3 key matrix from user
//message can onnly be 3 letter long for now
//inversibility of matrix is not checked by program
void message_and_key()
{
   int i, j;
   char msg[3];
   printf("Enter a inversible 3x3 matrix as key:\n");
   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 3; j++)
      {
         scanf("%f", &a[i][j]);
         c[i][j] = a[i][j];
      }
   } 
   printf("\nEnter a 3 letter message: ");
   //only 3 letter taken for easier matching with matrix
   scanf("%s", msg);
   for(i = 0; i < 3; i++)
   {
      mes[i][0] = msg[i] - 97;
   }
}
void inverse_key_matrix()
{
   int i, j, k;
   float p, q;
   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 3; j++)
      {
         if(i == j)
         {
            b[i][j]=1;
         }
         else
         {
            b[i][j]=0;
         }
      }
   }
   for(k = 0; k < 3; k++)
   {
      for(i = 0; i < 3; i++)
      {
         p = c[i][k];
         q = c[k][k];
         for(j = 0; j < 3; j++) 
         {
            if(i != k)
            {
               c[i][j] = c[i][j]*q - p*c[k][j];
               b[i][j] = b[i][j]*q - p*b[k][j];
            }
         }
      }
   }
   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 3; j++)
      {
         b[i][j] = b[i][j] / c[i][i];
      }
   }
}