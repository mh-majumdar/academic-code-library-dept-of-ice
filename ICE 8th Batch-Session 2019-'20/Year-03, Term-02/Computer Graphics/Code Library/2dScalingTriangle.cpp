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

// Function to scale a triangle about the origin
void scaleTriangle(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float sx, float sy) {
    scalePoint(x1, y1, sx, sy);
    scalePoint(x2, y2, sx, sy);
    scalePoint(x3, y3, sx, sy);
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

    // Scale the triangle about the origin
    scaleTriangle(x1, y1, x2, y2, x3, y3, sx, sy);

    // Draw the scaled triangle
    setcolor(RED);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
