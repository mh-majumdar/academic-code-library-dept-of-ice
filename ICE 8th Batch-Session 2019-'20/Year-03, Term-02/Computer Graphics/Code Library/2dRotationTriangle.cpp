#include <graphics.h>
#include <cmath>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to rotate a point about the origin
void rotatePoint(int &x, int &y, float angle) {
    float rad = angle * 3.14159265358979323846 / 180.0;
    int newX = round(x * cos(rad) - y * sin(rad));
    int newY = round(x * sin(rad) + y * cos(rad));
    x = newX;
    y = newY;
}

// Function to rotate a triangle about the origin
void rotateTriangle(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float angle) {
    rotatePoint(x1, y1, angle);
    rotatePoint(x2, y2, angle);
    rotatePoint(x3, y3, angle);
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

    // Rotate the triangle about the origin
    rotateTriangle(x1, y1, x2, y2, x3, y3, angle);

    // Draw the rotated triangle
    setcolor(RED);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
