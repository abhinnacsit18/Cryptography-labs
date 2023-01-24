#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int m, v, i, x, j, t, flag = 0;
    int data[101];
    printf("\nEnter the modulo: ");
    scanf("%d", &m);
    printf("\nEnter the value to check (< modulo): ");
    scanf("%d", &v);
    //calculating the modulus value  from 1 to m-1
    for(i = 1; i < m; i++)
    {
        data[i] = ((int) pow(v, i)) % m;
        //making positive
        if(data[i] < 0)
        {
            data[i] = data[i] + m;
        }
        printf("\n(%d ^ %d) (mod %d) = %d", v, i, m, data[i]);
    }
    //sorting the obtained values in ascending order
    for(i = 1; i < m; i++)
    {
        for(j = i; j < m; j++)
        {
            if(data[j] < data[i])
            {
                t = data[i];
                data[i] = data[j];
                data[j] = t;
            }
        }
    }
    //checking if all the values obtained are properly arranegd to be primitive root
    for(i = 1; i < m; i++)
    {
        if (i != data[i])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        printf("\n%d is not a primitive root of %d", v, m);
    }
    else
    {
        printf("\n%d is a primitive root of %d", v, m);
    }
    
    getch();

}