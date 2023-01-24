#include<stdio.h>
#include<conio.h>
//main
int main()
{
    int v, i, mod;
    int x, y;
    printf("\nEnter the value to calculate multiplicative inverse of: ");
    scanf("%d", &v);
    printf("\nEnter the modulus under which to calculate inverse: ");
    scanf("%d", &mod);
    for(i = 1; i < mod; i++)
    {
        //i will always be the modulus value under mod as i is less than mod
        //finding the modulus of entered value under mod
        x = v % mod;
        //calclating the multiplicative value under mod
        y = (x * i) % mod;
        //checking if the multiplicative modulus is 1. if so then i is multiplicative inverse of v
        if(y == 1)
        {
            printf("\nThe multiplicative inverse of %d is %d under modulus %d", v, i, mod);
        }
    }
    getch();
}