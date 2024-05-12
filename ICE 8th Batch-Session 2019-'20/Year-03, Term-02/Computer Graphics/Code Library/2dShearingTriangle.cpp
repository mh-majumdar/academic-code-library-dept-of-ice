#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to apply shear transformation to a point
void shearPoint(int &x, int &y, float shx, float shy) {
    int newX = x + shx * y;
    int newY = y + shy * x;
    x = newX;
    y = newY;
}

// Function to apply shear transformation to a triangle
void shearTriangle(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float shx, float shy) {
    shearPoint(x1, y1, shx, shy);
    shearPoint(x2, y2, shx, shy);
    shearPoint(x3, y3, shx, shy);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Coordinates of the first vertex
    int x2 = 200, y2 = 200; // Coordinates of the second vertex
    int x3 = 300, y3 = 100; // Coordinates of the third vertex

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Shear factors
    float shx = 0.5, shy = 0.5;

    // Apply shear transformation to the triangle
    shearTriangle(x1, y1, x2, y2, x3, y3, shx, shy);

    // Draw the sheared triangle
    setcolor(RED);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
