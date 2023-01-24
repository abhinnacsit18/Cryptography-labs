#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int c_box_48[48] = {
                        29, 17, 11, 24, 37, 5, 3, 28, 15, 6, 21, 10,
                        26, 19, 12, 4, 23, 50, 16, 7, 26, 20, 13, 2,
                        41, 52, 31, 1, 47, 55, 30, 40, 51, 45, 33, 48,
                        44, 49, 39, 56, 34, 53, 46, 42, 8, 6, 14, 32  
                        };
    char data_64[64] = {
                        '1','0','0','0','1','1','1','1','1','1','1','0','1','0','0','0',
                        '0','1','0','0','1','0','0','0','1','1','0','0','0','0','0','0',
                        '1','0','1','1','1','1','0','0','1','1','1','0','1','1','0','1',
                        '1','0','0','0','1','1','0','0','0','1','1','0','1','0','1','1'
                        };
    char data_56[56];
    char data_48[48];
    char lh_28[28], rh_28[28];
    int i, j = 0, tl, tr, x, choice;
    char input[64];

    printf("\nEnter 1 if you want to input your own 64 bit binary key");
    printf("\nEnter any other key if you want to continue with the default 64 bit key:\n");
    for(i = 0; i < 64; i++)
    {
        printf("%c", data_64[i]);
    }
    printf("\n\nEnter choice: ");
    scanf("%d", &choice);
    fflush(stdin);
    if(choice == 1)
    {
        printf("\n\nEnter 64 bit key: ");
        gets(input);
        for(i = 0; i < 64; i++)
        {
            data_64[i] = input[i];
        }
    }
    //removing data on 8th, 16th, ... 64th index
    for(i = 0; i < 64; i++)
    {
        if((i + 1) % 8 != 0)
        {
            data_56[j] = data_64[i];
            j++;
        }
    }
    //dividing data into 2 halves
    for(i = 0; i < 28; i++)
    {
        lh_28[i] = data_56[i];
        rh_28[i] = data_56[i + 28];
    }
    //left circlar shift once on both halves
    tl = lh_28[0];
    tr = rh_28[0];
    for(i = 0; i < 28; i++)
    {
        j = i + 1;
        if(j == 28)
        {
            lh_28[j] = tl;
            rh_28[j] = tr;       
        }
        else
        {
            lh_28[i] = lh_28[j];
            rh_28[i] = rh_28[j];
        }        
    }
    //combining left and right shifted halves
    for(i = 0; i < 28; i++)
    {
        data_56[i] =  lh_28[i];
        data_56[i + 28] = rh_28[i];
    }
    //comperssion box replacement
    for (i = 0; i < 48; i++)
    {
        j = c_box_48[i] - 1;
        //-1 because values in c-box is from 1 to 56 but index is from 0 o 55
        data_48[i] = data_56[j];
    }
    //printing the key
    printf("\nThe 48 bit key for round 1 is: ");
    for(i = 0; i < 48; i++)
    {
        printf("%c", data_48[i]);
    }

    getch();
}