#include <stdio.h>
#include <stdbool.h>

#define DEBUG

struct point
{
    int x, y;
};
struct rectangle
{
    struct point upperLeft, lowerRight;
};

int getRectArea(struct rectangle rec);
struct point getRectCenter(struct rectangle rec);
struct rectangle movRect(struct rectangle rec, int x, int y);
bool PointInRect(struct rectangle rec, struct point p);

int main(void)
{
    struct rectangle sample = {{0, 7},
                               {5, 4}};
    int area = getRectArea(sample);
    printf("Area of the given rectangle: %d\n", area);
    
    return 0;
}

int getRectArea(struct rectangle rec)
{
    int area;
    area = (rec.lowerRight.x - rec.upperLeft.x) * (rec.upperLeft.y - rec.lowerRight.y);
    return area;
}

struct point getRectCenter(struct rectangle rec)
{
    struct point center;
    center.x = (rec.lowerRight.x + rec.upperLeft.x) / 2;
    center.y = (rec.lowerRight.y + rec.upperLeft.y) / 2;
    return center;
}

struct rectangle movRect(struct rectangle rec, int x, int y)
{
    rec.upperLeft.x += x;
    rec.lowerRight.x += x;
    
    rec.upperLeft.y += y;
    rec.lowerRight.y += y;
    
    return rec;
}

bool PointInRect(struct rectangle rec, struct point p)
{
    if ((rec.upperLeft.x < p.x && p.x < rec.lowerRight.x) && (rec.lowerRight.y < p.y && p.y < rec.upperLeft.y))
        return true;
    else return false;
}
