#include <stdio.h>
#include <cs50.h>
// credit card number
// multiply every Other digit by 2 starting with the CC number 2nd to last digit
// then add those products' digits together
// add the sum to the sum of the digits that were NOT multiplied together
// if the totals last digit is 0 then it is a valid number

int main(void)
{
    int multiplied_sum = 0;
    long cc_number = get_long("Enter your card number ");   // get cc number from user
    int arr[16];

    printf("Number is :%li\n",cc_number);           // sanity check

    // need to separate digits for validation process
    for(int i = 0; i < 16; i++)
    {
        arr[15-i] = cc_number%10;                   // need to get an array of the CC number
        cc_number /=10;                             // need to remove the last number and then save new number
        printf("new cc number: %li", cc_number);
    }

    return(0);
}
