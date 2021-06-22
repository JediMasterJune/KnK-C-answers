//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int num[4];
    int max, min;
    
    printf("4개의 정수 입력 : ");
    for (int i = 0; i < 4; ++i)
    {
        scanf("%d", num + i);
    }
    //max = num[0], min = num[0];
    
    /*
    max = (max > num[1]) ? ((max > num[2]) ? ((max > num[3]) ? max : num[3]) : (num[2] > num[3] ? num[2] : num[3])) :
          (num[1] > num[2] ? num[1] > num[3] ? num[1] : num[3] : num[2] > num[3] ? num[2] : num[3]);
    min = (min < num[1]) ? ((min < num[2]) ? ((min < num[3]) ? min : num[3]) : num[2] < num[3] ? num[2] : num[3]) :
          (num[1] < num[2] ? num[1] < num[3] ? num[1] : num[3] : num[2] < num[3] ? num[2] : num[3]);
    */
    
    if (num[0] > num[1])
    {
        if (num[2] > num[3])
        {
            max = num[0] > num[2] ? num[0] : num[2];
            min = num[1] < num[3] ? num[1] : num[3];
        }
        else
        {
            max = num[0] > num[3] ? num[0] : num[3];
            min = num[1] < num[2] ? num[1] : num[2];
        }
    }
    else
    {
        if (num[2] > num[3])
        {
            max = num[1] > num[2] ? num[1] : num[2];
            min = num[0] < num[3] ? num[0] : num[3];
        }
        else
        {
            max = num[1] > num[3] ? num[1] : num[3];
            min = num[0] < num[2] ? num[0] : num[2];
        }
    }
    
    
    printf("최댓값 : %d\n", max);
    printf("최솟값 : %d\n", min);
    
    return 0;
}