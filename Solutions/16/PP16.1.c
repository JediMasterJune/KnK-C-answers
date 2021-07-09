//
//

#include <stdio.h>
#include <stdlib.h>

#define N (sizeof(countryCodes)/sizeof(countryCodes[0]))

typedef struct dialingCode {
    char* country;
    int code;
} DialingCode;

void codeSearch(int size, DialingCode countryCodes[], int num);

int main(void)
{
    const DialingCode countryCodes[] =
            {{"Argentina",           54},
             {"Bangladesh",          880},
             {"Brazil",              55},
             {"Burma (Myanmar)",     95},
             {"China",               86},
             {"Colombia",            57},
             {"Congo, Dem. Rep. of", 243},
             {"Egypt",               20},
             {"Ethiopia",            251},
             {"France",              33},
             {"Germany",             49},
             {"India",               91},
             {"Indonesia",           62},
             {"Iran",                98},
             {"Italy",               39},
             {"Japan",               81},
             {"Mexico",              52},
             {"Nigeria",             234},
             {"Pakistan",            92},
             {"Philippines",         63},
             {"Poland",              48},
             {"Russia",              7},
             {"South Africa",        27},
             {"South Korea",         82},
             {"Spain",               34},
             {"Sudan",               249},
             {"Thailand",            66},
             {"Turkey",              90},
             {"Ukraine",             380},
             {"United Kingdom",      44},
             {"United States",       1},
             {"Vietnam",             84}};
    int num;
    for (;;) {
        printf("Enter desired number(Enter a negative integer to quit): ");
        scanf("%d", &num);
        codeSearch(N, countryCodes, num);
    }
    return 0;
}

void codeSearch(int size, DialingCode countryCodes[], int num)
{
    if (num < 0) exit(EXIT_SUCCESS);
    for (int i = 0; i < size; ++i) {
        if (countryCodes[i].code == num) {
            printf("The country with code %d is %s\n", num, countryCodes[i].country);
            return;
        }
    }
    printf("The country with code %d is not found\n", num);
}
