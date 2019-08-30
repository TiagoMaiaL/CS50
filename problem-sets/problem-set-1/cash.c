// Author: Tiago Maia, in 30/08/2019.

#include <cs50.h>
#include <stdio.h>
#include <math.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

void compute_change();
int get_owed_value();
int get_min_change_coins(float owed_value);

// Given an amount of change, computes and prints the minimum 
// number of coins needed to give the change back.
int main(void)
{    
    compute_change();
    return 0;
}

// Asks the user for the amount of change, computes and prints the minimum 
// number of coins needed for the change.
void compute_change()
{
    int owed_value;
    owed_value = get_owed_value();
    
    printf("%d\n", get_min_change_coins(owed_value));
}

// Asks the user how much change is needed.
int get_owed_value()
{
    float f;
    
    f = 0;
    
    while (f <= 0)
    {
        f = get_float("Change owed: ");
    }
    
    return round(f * 100);
}

// Given the owed change value. returns the minimum number of 
// coins needed to give the change back.
int get_min_change_coins(float owed_value)
{
    int min_coins, curr_coins_count, curr_coin;
    
    min_coins = 0;
    
    while (owed_value > 0)
    {
        curr_coins_count = curr_coin = 0;
        
        if (owed_value >= QUARTER)
        {
            curr_coin = QUARTER;
        } 
        else if (owed_value >= DIME)
        {
            curr_coin = DIME;
        } 
        else if (owed_value >= NICKEL)
        {
            curr_coin = NICKEL;    
        } 
        else 
        {
            curr_coin = PENNY;
        }
        
        curr_coins_count = (int) floor(owed_value / curr_coin);
        min_coins += curr_coins_count;
        owed_value -= curr_coins_count * curr_coin;
    }
    
    return min_coins;
}

