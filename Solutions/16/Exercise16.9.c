#include <stdio.h>
#include <stdbool.h>

#define DEBUG

struct color
{
    int red, green, blue;
};

struct color makeColor(int red, int green, int blue);
int getRed(struct color c);
bool equalColor(struct color color1, struct color color2);
struct color brighter(struct color c);
struct color darker(struct color c);


int main(void)
{
    struct color test = makeColor(123, 39, 255);
    test = brighter(test);
#ifdef DEBUG
    printf("The number of elements in the structure:%d\n", sizeof(struct color) / sizeof(int));
#endif
    printf("Brighter test : %d/%d/%d\n", test.red, test.green, test.blue);
    
    return 0;
}

struct color makeColor(int red, int green, int blue)
{
    struct color ret;
    
    if (red < 0) ret.red = 0;
    else if (red > 255) ret.red = 255;
    else ret.red = red;
    
    if (blue < 0) ret.blue = 0;
    else if (blue > 255) ret.blue = 255;
    else ret.blue = blue;
    
    if (green < 0) ret.green = 0;
    else if (green > 255) ret.green = 255;
    else ret.green = green;
    
    return ret;
}

int getRed(struct color c)
{
    return c.red;
}

bool equalColor(struct color color1, struct color color2)
{
    if (color1.red == color2.red && color1.blue == color2.blue && color1.green == color2.green) return true;
    else return false;
}

struct color brighter(struct color c)
{
    int* colorPick = &c.red;
    
    if (c.red == 0 && c.green == 0 && c.blue == 0) {
        c.red = c.green = c.blue = 3;
    }
    else {
        c.red = (c.red < 3) ? 3 : c.red;
        c.green = (c.green < 3) ? 3 : c.green;
        c.blue = (c.blue < 3) ? 3 : c.blue;
        
        c.red /= 0.7;
        c.green /= 0.7;
        c.blue /= 0.7;
    }
    for (int i = 0; i < sizeof(c) / sizeof(int); ++i) {
        if (*colorPick > 255) (*colorPick) = 255;
        colorPick++;
    }
    return c;
}

struct color darker(struct color c)
{
    int* colorPick = &c.red;
    
    if (c.red == 0 && c.green == 0 && c.blue == 0) {
        c.red = c.green = c.blue = 3;
    }
    else {
        c.red = (c.red < 3) ? 3 : c.red;
        c.green = (c.green < 3) ? 3 : c.green;
        c.blue = (c.blue < 3) ? 3 : c.blue;
        
        c.red *= 0.7;
        c.green *= 0.7;
        c.blue *= 0.7;
    }
    for (int i = 0; i < sizeof(c) / sizeof(int); ++i) {
        if (*colorPick > 255) *colorPick = 255;
        colorPick++;
    }
}

