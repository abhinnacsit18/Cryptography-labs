#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
    int n, n_1, k = 0, m, t, a, b, i, prime = 0, x, y;
    printf("\nEnter the value to check primality: ");
    scanf("%d", &n);
    n_1 = n - 1;
    //if n-1 is odd, k3 = 0 directly as it is not divisible b 2
    if(n_1 % 2 == 1)
    {
        m = n_1;   
    }
    else
    {
        t = n_1;
        while(1)
        {
            if(t % 2 == 0)
            {
                t = t / 2;
                //increment k until the value is divisible by 2 to get value of k
                k++;    
            }
            else
            {
                //residuual odd number is t
                m = t;
                break;
            }
        }
    }
    //takinng a ranndomolt between 1 and n-1
    a = rand() % n_1 + 1;

    b = ((int) pow(a, m)) % n;
    if(b < 0)
    {
        b = b + n;
    }
    // if b = 1 mod n return prime
    // if (b-1) (mod n) == 0, return prime
    x = (b - 1) % n;
    if(x == 0)
    {
        prime = 1;
    }
    //looped algorithm
    for(i = 0; i < k; i++)
    {
        // if b = -1 mod n return prime
        // if (b+1) (mod n) == 0, return prime
        x = (b + 1) % n;
        if(x == 0)
        {
            prime = 1;
            break;
        }
        else
        {
            y = (b * b) % n;
            if(y < 0)
            {
                y = y + n;
            }
            b = y;
        }
    }
    
    if(prime == 0)
    {
        printf("%d is composite", n);
    }
    else
    {
        printf("%d is prime", n);

    }

    getch();
}
