#include <graphics.h>

// Function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

// Function to scale a point about the origin
void scalePoint(int &x, int &y, float sx, float sy) {
    x *= sx;
    y *= sy;
}

// Function to scale a rectangle about a pivot point
void scaleRectangle(int &x1, int &y1, int &x2, int &y2, float sx, float sy, int pivotX, int pivotY) {
    // Translate the rectangle to make pivot point the origin
    x1 -= pivotX;
    y1 -= pivotY;
    x2 -= pivotX;
    y2 -= pivotY;

    // Scale the rectangle
    scalePoint(x1, y1, sx, sy);
    scalePoint(x2, y2, sx, sy);

    // Translate the rectangle back to its original position
    x1 += pivotX;
    y1 += pivotY;
    x2 += pivotX;
    y2 += pivotY;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Coordinates of the top-left corner
    int x2 = 300, y2 = 200; // Coordinates of the bottom-right corner

    // Draw the original rectangle
    drawRectangle(x1, y1, x2, y2);

    // Scaling factors
    float sx = 1.5, sy = 0.5;

    // Pivot point coordinates
    int pivotX = 200, pivotY = 150;

    // Scale the rectangle about the pivot point
    scaleRectangle(x1, y1, x2, y2, sx, sy, pivotX, pivotY);

    // Draw the scaled rectangle
    setcolor(RED);
    drawRectangle(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
