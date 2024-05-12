#include <graphics.h>

// Function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

// Function to scale a rectangle about the origin
void scaleRectangle(int &x1, int &y1, int &x2, int &y2, float sx, float sy) {
    x1 *= sx;
    y1 *= sy;
    x2 *= sx;
    y2 *= sy;
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

    // Scale the rectangle about the origin
    scaleRectangle(x1, y1, x2, y2, sx, sy);

    // Draw the scaled rectangle
    setcolor(RED);
    drawRectangle(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
