//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int getGCD(int a, int b);
void reduce(int son, int mom, int* p_reducedSon, int* p_reducedMom);

int main(void)
{
    int son, mom;
    
    printf("약분할 분수를 입력 : ");
    scanf("%d / %d", &son, &mom);
    
    /*
    for (int i = 2; i < son || i < mom; ++i) { // My algorithm
        if (son % i == 0 && mom % i == 0) {
            gcd = i;
        }
    }
    */
    /*
     while (mom != 0) { //유클리드
         gcd = mom;
         mom = son % mom;
         son = gcd;
     }
     */
    
    reduce(son, mom, &son, &mom);
    
    //printf("최대공약수는 %d 입니다.\n", gcd);
    printf("약분된 분수는 %d/%d 입니다.\n", son, mom);
    
    return 0;
}

int getGCD(int m, int n)
{
    if (n == 0) {
        return m;
    }
    else {
        getGCD(n, m % n);
    }
}

void reduce(int son, int mom, int* p_reducedSon, int* p_reducedMom)
{
    int gcd = getGCD(son, mom);
    
    *(p_reducedSon) = son / gcd;
    *(p_reducedMom) = mom / gcd;
}
