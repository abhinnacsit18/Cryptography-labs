#include<stdio.h>
#include<conio.h>
//functioin prototype for gcd calcuation
int gcd(int a, int b);
//main function starts here
int main()
{
   int x, y, g;
   //takinng 2 values from user
   printf("Enter two values x and y separated by space: ");
   scanf("%d %d", &x, &y);
   //calculating GCD
   g = gcd(x,y);
   //if gcd of 2 numbers is 1 then they are relatively prime
   if(g == 1)
   {
       printf("\nThe numbers %d and %d are relatively prime", x, y);
   }
   else
   {
       printf("\nThe numbers %d and %d are not relatively prime", x, y);
   }
   //waiting for key press before exiting
   getch();
   return 0;
}
//fuction of GCD
int gcd(int a, int b)
{
   //when a is 0, return the GCD
   if(a == 0)
   {
      return b;
   }
   //if a is not 0, recall funnction with b mod a and a
   return gcd(b % a, a);
}