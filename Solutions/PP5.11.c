//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num;
    bool teenCheck = false;
    
    printf("Enter a two-digit number : ");
    scanf("%d", &num);
    
    printf("You entered ");
    switch (num / 10)
    {
        case 9:
            printf("ninety-");
            break;
        case 8:
            printf("eighty");
            break;
        case 7:
            printf("seventy-");
            break;
        case 6:
            printf("sixty-");
            break;
        case 5:
            printf("fifty-");
            break;
        case 4:
            printf("forty-");
            break;
        case 3:
            printf("thirty-");
            break;
        case 2:
            printf("twenty-");
            break;
        default:
            teenCheck = true;
            break;
    }
    
    if (teenCheck)
    {
        switch (num)
        {
            case 19:
                printf("nineteen\n");
                break;
            case 18:
                printf("eighteen\n");
                break;
            case 17:
                printf("seventeen\n");
                break;
            case 16:
                printf("sixteen\n");
                break;
            case 15:
                printf("fifteen\n");
                break;
            case 14:
                printf("fourteen\n");
                break;
            case 13:
                printf("thirteen\n");
                break;
            case 12:
                printf("twelve\n");
                break;
            case 11:
                printf("eleven\n");
                break;
            case 10:
                printf("ten\n");
                break;
        }
    }
    else
    {
        switch (num % 10)
        {
            case 1:
                printf("one\n");
                break;
            case 2:
                printf("two\n");
                break;
            case 3:
                printf("three\n");
                break;
            case 4:
                printf("four\n");
                break;
            case 5:
                printf("five\n");
                break;
            case 6:
                printf("six\n");
                break;
            case 7:
                printf("seven\n");
                break;
            case 8:
                printf("eight\n");
                break;
            case 9:
                printf("nine\n");
                break;
        }
    }
    
    return 0;
}