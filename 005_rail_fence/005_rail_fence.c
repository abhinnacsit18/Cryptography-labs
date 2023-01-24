//railfencec cipher
#include<stdio.h>
#include<string.h>
//function prototpes
void encrypt_rail();
void decrypt_rail();
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
            encrypt_rail();
         break;
         case 2:
            decrypt_rail();
         break;
         case 3:
         exit(-1);
      }
   }
}
//function definitions
void encrypt_rail()
{
    char message[100];
    int i, j, k = -1, row = 0, col = 0, key;
    printf("\nEnter the plaintext message: ");
    fflush(stdin);
    gets(message);
    printf("\nEnter the encryption key: ");
    fflush(stdin);
    scanf("%d", &key);
    int messageLen = strlen(message);
    char railMatrix[key][messageLen];
    for(i = 0; i < key; ++i)
    {
        for(j = 0; j < messageLen; ++j)
        {
           railMatrix[i][j] = '\n';

        }
    }
    for(i = 0; i < messageLen; ++i)
    {
        railMatrix[row][col++] = message[i];
        if(row == 0 || row == key-1)
        {
            k= k * (-1);
        }
        row = row + k;
    }
    printf("\nThe encrypted message is: ");
    for(i = 0; i < key; ++i)
    {
        for(j = 0; j < messageLen; ++j)
        {
            if(railMatrix[i][j] != '\n')
            {
                printf("%c", railMatrix[i][j]);
            }
        }
            
    }      
}
void decrypt_rail()
{
    char message[100];
    int i, j, k = -1, row = 0, col = 0, m = 0, key;
    printf("\nEnter the cipher message: ");
    fflush(stdin);
    gets(message);
    printf("\nEnter the decryption key: ");
    fflush(stdin);
    int messageLen = strlen(message);
    char railMatrix[key][messageLen];
    scanf("%d", &key);
    for(i = 0; i < key; ++i)
    {
        for(j = 0; j < messageLen; ++j)
        {
            railMatrix[i][j] = '\n';
        }
    }
    for(i = 0; i < messageLen; ++i)
    {
        railMatrix[row][col++] = '*';
        if(row == 0 || row == key-1)
        {
            k= k * (-1);
        }
        row = row + k;
    }
    for(i = 0; i < key; ++i)
    {
        for(j = 0; j < messageLen; ++j)
        {
            if(railMatrix[i][j] == '*')
            {
                railMatrix[i][j] = message[m++];
            }
        }
            
    }
    row = col = 0;
    k = -1;
    printf("\nThe decrypted ciphertext message is: ");
    for(i = 0; i < messageLen; ++i)
    {
        printf("%c", railMatrix[row][col++]);
        if(row == 0 || row == key-1)
        {
            k= k * (-1);
        }
        row = row + k;
    }
}