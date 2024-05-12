#include <graphics.h>
#include <cmath>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to rotate a point about the pivot point
void rotatePoint(int &x, int &y, float pivotX, float pivotY, float angle) {
    float rad = angle * 3.14159265358979323846 / 180.0;
    float newX = pivotX + (x - pivotX) * cos(rad) - (y - pivotY) * sin(rad);
    float newY = pivotY + (x - pivotX) * sin(rad) + (y - pivotY) * cos(rad);
    x = round(newX);
    y = round(newY);
}

// Function to rotate a triangle about a pivot point
void rotateTriangle(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float pivotX, float pivotY, float angle) {
    rotatePoint(x1, y1, pivotX, pivotY, angle);
    rotatePoint(x2, y2, pivotX, pivotY, angle);
    rotatePoint(x3, y3, pivotX, pivotY, angle);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Coordinates of the first vertex
    int x2 = 200, y2 = 200; // Coordinates of the second vertex
    int x3 = 300, y3 = 100; // Coordinates of the third vertex

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Rotation angle (in degrees)
    float angle = 45.0;

    // Pivot point coordinates
    float pivotX = (x1 + x2 + x3) / 3.0;
    float pivotY = (y1 + y2 + y3) / 3.0;

    // Rotate the triangle about the pivot point
    rotateTriangle(x1, y1, x2, y2, x3, y3, pivotX, pivotY, angle);

    // Draw the rotated triangle
    setcolor(RED);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
