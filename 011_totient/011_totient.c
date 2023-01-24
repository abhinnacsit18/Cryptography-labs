#include<stdio.h>
#include<conio.h>
//function prototype
int gcd(int a, int b);
int totient(int n);
//main
void main()
{
    int p, n;
    //taking value of n from user to calculate phi
    printf("\nEnter the value to calculate value of Totient function phi(n): ");
    scanf("%d", &n);
    p = totient(n);
    printf("\nThe totient function value, phi(%d) is %d", n, p);
    getch();
}
int gcd(int a, int b)
{
   if(a == 0)
   {
      return b;
   }
   return gcd(b % a, a);
}
int totient(int n)
{
    int g, i, t = 1;
    for(i = 2; i < n; i++)
    {
        g = gcd(n, i);
        // if gcd between said nuumber and number less than it is 1 increase the conut for totient function
        if(g == 1)
        {
            t = t + 1;
        }
    }
    return t;
}