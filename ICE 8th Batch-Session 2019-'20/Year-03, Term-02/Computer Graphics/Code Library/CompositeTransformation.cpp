#include <graphics.h>
#include <cmath>

// Function to apply translation to a point
void translate(int &x, int &y, int dx, int dy) {
    x += dx;
    y += dy;
}

// Function to apply rotation to a point
void rotate(int &x, int &y, double angle) {
    double rad = angle * 3.14159265358979323846 / 180.0;
    int newX = round(x * cos(rad) - y * sin(rad));
    int newY = round(x * sin(rad) + y * cos(rad));
    x = newX;
    y = newY;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Coordinates of a triangle
    int triangle[6] = {100, 100, 200, 100, 150, 200};
    int numPoints = sizeof(triangle) / sizeof(triangle[0]) / 2;

    // Draw original triangle
    drawpoly(numPoints, triangle);

    // Apply translation to each vertex
    for (int i = 0; i < numPoints; i += 2) {
        translate(triangle[i], triangle[i + 1], 100, 100);
    }

    // Draw translated triangle
    setcolor(RED);
    drawpoly(numPoints, triangle);

    // Reset triangle to original coordinates
    for (int i = 0; i < numPoints; i += 2) {
        translate(triangle[i], triangle[i + 1], -100, -100);
    }

    // Apply rotation to each vertex
    for (int i = 0; i < numPoints; i += 2) {
        rotate(triangle[i], triangle[i + 1], 45);
    }

    // Draw rotated triangle
    setcolor(GREEN);
    drawpoly(numPoints, triangle);

    getch();
    closegraph();
    return 0;
}
