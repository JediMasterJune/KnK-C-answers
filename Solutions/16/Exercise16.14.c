#include <stdio.h>
#include <stdbool.h>

#define DEBUG
#define PI 3.141592

enum shapes { RECTANGLE, CIRCLE };

struct point {
    int x, y;
};

typedef struct shape {
    int shapeKind; // RECTANGLE or CIRCLE
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} Shape;

int getArea(Shape fig)
{
    int area;
    switch (fig.shapeKind) {
        case RECTANGLE:
            area = fig.u.rectangle.height * fig.u.rectangle.width;
            break;
        case CIRCLE:
            area = (int) (fig.u.circle.radius * fig.u.circle.radius * PI);
            break;
    }
    return area;
}

Shape mov(Shape fig, int x, int y)
{
    fig.center.x += x;
    fig.center.y += y;
    return fig;
}

Shape scale(Shape fig, double c)
{
    switch (fig.shapeKind) {
        case RECTANGLE:
            fig.u.rectangle.height *= c;
            fig.u.rectangle.width *= c;
            break;
        case CIRCLE:
            fig.u.circle.radius *= c;
            break;
    }
    return fig;
}