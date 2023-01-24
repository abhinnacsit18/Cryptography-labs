#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
    int p, q, phi, e, d, i, s, msg, cipher, n, decipher, choice;
    printf("\nEnter value of 1st prime number p: ");
    scanf("%d", &p);
    printf("\nEnter value of 2nd prime number q: ");
    scanf("%d", &q);
    // calculation phi and (p-1)*(q-1)
    phi = (p - 1) * (q - 1);
    n = p * q;
    //e and phi(n) mst be coprimes, n = p*q.
    printf("\nEnter e such that 1 < e < %d and gcd of e and %d = 1: ", phi, phi);
    scanf("%d", &e);

    for(i = 1; i < n; i++)
    {
        s = (e * i) % phi;
        if(s == 1)
        {
            d = i;
            break;
        }   
    }
    printf("\nEnter choice:");
    printf("\n[1] Encrypt");
    printf("\n[2] Decrypt");
    printf("\n[3] Exit");
    printf("\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("\nEnter messaege to encrypt: ");
            scanf("%d", &msg);
            // encryption = M^e mod n
            cipher = ((int) pow(msg, e)) % (n);
            if (cipher < 0)
            {
                cipher = cipher + n;
            }
            printf("\nencrypted message: %d", cipher);
        break;
        case 2:
            printf("\nEnter messaege to decrypt: ");
            scanf("%d", &msg);
            // decryption = M^d mod n
            decipher = ((int) pow(msg, d)) % (n);
            if (decipher < 0)
            {
                decipher = decipher + n;
            }
            printf("\ndecrypted message: %d", decipher);
        break;
        case 3:
            exit(-1);
    }

    getch();
}