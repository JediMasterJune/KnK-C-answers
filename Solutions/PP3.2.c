//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int item;
    int year, month, day;
    double unitPrice;
    
    printf("아이템 번호를 입력하십시오 : ");
    scanf("%d", &item);
    
    printf("단위 가격을 입력하십시오 : ");
    scanf("%lf", &unitPrice);
    
    printf("구입 날짜를 월/일/연도 형식으로 입력하십시오 : ");
    scanf("%d /%d /%d", &month, &day, &year);
    
    printf("Item\tUnit Price\tPurchase Date\n");
    printf("%-5d\t$%7.2f\t%d/%d/%d\n", item, unitPrice, month, day, year);
    
    return 0;
}