#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to scale a point about the origin
void scalePoint(int &x, int &y, float sx, float sy) {
    x *= sx;
    y *= sy;
}

// Function to translate a point to make the pivot point the origin
void translateToOrigin(int &x, int &y, int pivotX, int pivotY) {
    x -= pivotX;
    y -= pivotY;
}

// Function to translate a point to its original position
void translateBack(int &x, int &y, int pivotX, int pivotY) {
    x += pivotX;
    y += pivotY;
}

// Function to scale a triangle about a pivot point
void scaleTriangle(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float sx, float sy, int pivotX, int pivotY) {
    translateToOrigin(x1, y1, pivotX, pivotY);
    translateToOrigin(x2, y2, pivotX, pivotY);
    translateToOrigin(x3, y3, pivotX, pivotY);

    scalePoint(x1, y1, sx, sy);
    scalePoint(x2, y2, sx, sy);
    scalePoint(x3, y3, sx, sy);

    translateBack(x1, y1, pivotX, pivotY);
    translateBack(x2, y2, pivotX, pivotY);
    translateBack(x3, y3, pivotX, pivotY);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Coordinates of the first vertex
    int x2 = 200, y2 = 200; // Coordinates of the second vertex
    int x3 = 300, y3 = 100; // Coordinates of the third vertex

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Scaling factors
    float sx = 1.5, sy = 0.5;

    // Pivot point coordinates
    int pivotX = 200, pivotY = 150;

    // Scale the triangle about the pivot point
    scaleTriangle(x1, y1, x2, y2, x3, y3, sx, sy, pivotX, pivotY);

    // Draw the scaled triangle
    setcolor(RED);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
