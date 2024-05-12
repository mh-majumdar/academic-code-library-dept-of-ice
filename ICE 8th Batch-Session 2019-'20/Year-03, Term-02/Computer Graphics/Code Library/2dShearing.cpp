#include <graphics.h>

// Function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

// Function to shear a rectangle
void shearRectangle(int &x1, int &y1, int &x2, int &y2, float shx, float shy) {
    int newX1 = x1 + shx * y1;
    int newY1 = y1 + shy * x1;
    int newX2 = x2 + shx * y2;
    int newY2 = y2 + shy * x2;
    x1 = newX1;
    y1 = newY1;
    x2 = newX2;
    y2 = newY2;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Coordinates of the top-left corner
    int x2 = 300, y2 = 200; // Coordinates of the bottom-right corner

    // Draw the original rectangle
    drawRectangle(x1, y1, x2, y2);

    // Shear factors
    float shx = 0.5, shy = 0.5;

    // Shear the rectangle
    shearRectangle(x1, y1, x2, y2, shx, shy);

    // Draw the sheared rectangle
    setcolor(RED);
    drawRectangle(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
