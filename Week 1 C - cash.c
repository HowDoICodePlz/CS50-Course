//the functioin headers we called out  
#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Function callout
int maths(int);

int main(void)
    {
    //call out customer use variables
        float price;
        do
            {
                price = get_float("Enter Price:");
            }
        while(price <= 0.00);
    //convert $ & float input into c & integer output for greedy algorithm  
        int cents = round(price * 100);
        printf("%i\n",maths(cents));
    }

int maths(cents)
    {
    //Variable to store # of coins used in the greedy algorithm
        int twfi = 0; int ten = 0; int  fv = 0; int one = 0;
    //Variables to show how much value remains at each greedy algorithm
        int twfic = 0; int tenc = 0; int fvc = 0;
    //Variable to store the sum of all coins used
        int coins;
    //Individual value breakdown
        if(cents >24)
            {
                twfi = cents / 25;
                twfic = cents % 25;
                cents = twfic;            
            }
        if(cents > 9)
            {
                ten = cents / 10;
                tenc = cents % 10;
                cents = tenc;            
            }
        if(cents > 4)
            {
                fv = cents / 5;
                fvc = cents % 5;
                cents = fvc;            
            }
        if(cents > 0)
            {
                one = cents / 1;
            }
    //return total coins used from the above if calculations
    coins = twfi + ten + fv + one;
    return coins;
    }
