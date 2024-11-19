#include <stdio.h>
#include <cs50.h>

/*
make a program that prints the minimum coins
needed to make the given amount of change in cents
example :
Change Owed: 25
return 1
Change Owed: 70
return 4
*/

int main()
{
    // define the amount of change
    int change_due = get_int("Enter a value > 0: ");
    printf("Change due: %i\n", change_due);

    int coins_used = 0;

    while (change_due > 0)
    {
        if (change_due >= 25)               // logic for using a quarter
        {
            // printf("Used a Quarter\n");
            coins_used += 1;
            change_due -= 25;
        }
        else if (change_due >= 10)          // logic for using a dime
        {
            // printf("Used a Dime\n");
            coins_used +=1;
            change_due -= 10;
        }
        else if (change_due >= 5)
        {
            // printf("Used a Nickel\n");
            coins_used +=1;
            change_due -=5;
        }
        else
        {
            // printf("Used a Penny\n");
            coins_used += 1;
            change_due -=1;
        }
    }
    printf("Coins Used: %i\n", coins_used);
    return(0);
}
