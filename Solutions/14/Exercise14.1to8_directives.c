#include <stdio.h>
#include <string.h>
#include <math.h>

#define CUBE(x) (x)*(x)
#define LESS100(x, y) ((x)*(y) < (100))
#define RE4(n) ((n)%(4))
#define TOUPPER(c) ('a' <= (c) && (c)<='z' ? (c)-'a'+'A':(c))
#define DISP(f, x) printf(#f "(%g) = %g\n", (x), (f(x)))
#define DISP2(f, x, y) printf(#f "(%g,%g) = %g\n", (x),(y), (f(x,y)))

#define STRINGIZE(n) #n // # operator is available only in parameterized macro definitions.
#define EXPAND_MACRO(n) STRINGIZE(n) // This macro is necessary to make the conversion from __LINE__ to the line number happen.
#define LINE_FILE ("Line " EXPAND_MACRO(__LINE__) " of file " __FILE__) //The __LINE__ is first converted to an integer and then stringized.

#define GENERIC_MAX(type) \
type type##_max(type x, type y) \
{                         \
    return x > y ? x : y;\
}

/* Preprocessor's expansion of GENERIC_MAX(long) (Exercise 7-b)
long long_max(long x, long y)
 {
    return x > y ? x : y;
 }
*/

int main(void)
{
    int x = 10;
    int y = CUBE(x);
    int n = 5;
    
    char s[101]; // Exercise 5
    int i;
    
    const char* str = LINE_FILE; // Exercise 8
    
    printf("x = %d, y = %d, n = %d\n", x, y, n);
    printf("Is x*n less than 100? -> %d\n", LESS100(x, n));
    printf("n %% 4 = %d\n\n", RE4(n));
    
    strcpy(s, "abcd"); // Exercise 5
    i = 0;
    putchar(TOUPPER(s[++i])); // 조건문에서 2번, 대체 연산 시 1번 증가하여 i의 값은 3
    
    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i])); // 이 경우엔 i의 값이 2 (한쪽의 거짓이 확정된 후 바로 &&연산을 수행한 것으로 추정)
    
    printf("\n");
    
    DISP(sqrt, 3.0);
    
    printf("str is defined at ");
    puts(str); //Exercise 8
    
    return 0;
}
