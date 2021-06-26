//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num;
    //bool teencheck;
    
    char* teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                     "Nineteen"};
    char* tynumbers[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char* numbers[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    
    printf("Enter a two-digit number : ");
    scanf("%d", &num);
    
    if (num / 10 < 1 || num / 10 > 9) {
        printf("I mean two-digit\n");
        return 1;
    }
    
    printf("You entered ");
    
    if (num / 10 < 2) {
        printf("%s\n", teens[num - 10]);
    }
    
    else {
        printf("%s-%s\n", tynumbers[num / 10 - 2], numbers[num % 10 - 1]);
    }
    
    return 0;
}