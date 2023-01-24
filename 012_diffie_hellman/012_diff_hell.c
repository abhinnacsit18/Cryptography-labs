#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int pk_1, pk_2, m, b;
    int key_1, key_2, c_key_1, c_key_2;
    printf("\nEnter the modulus number m: ");
    scanf("%d", &m);
    printf("\nEnter the base number b: ");
    scanf("%d", &b);
    printf("\nEnter the private key of 1st party: ");
    scanf("%d", &pk_1);
    printf("\nEnter the private key of 2nd party: ");
    scanf("%d", &pk_2);
    //the keys to be shared are key_1 and key_2 calculated:
    key_1 = (int) (pow(b, pk_1)) % m;
    key_2 = (int) (pow(b, pk_2)) % m;
    //making modulo +ve as c givevs in -ve also
    if(key_1 < 0)
    {
        key_1 = key_1 + m;
    }
    if(key_2 < 0)
    {
        key_2 = key_2 + m;
    }
    printf("\nkey shared by party 1: %d", key_1);
    printf("\nkey shared by party 2: %d", key_2);

    //computing the key again from shared key
    c_key_1 = (int) (pow(key_2, pk_1)) % m;
    c_key_2 = (int) (pow(key_1, pk_2)) % m;
    if(c_key_1 < 0)
    {
        c_key_1 = c_key_1 + m;
    }
    if(c_key_2 < 0)
    {
        c_key_2 = c_key_2 + m;
    }
    printf("\ncommon key calculated by party 1: %d", c_key_1);
    printf("\ncommonn key calculated by party 2: %d", c_key_2);
    getch();
}