#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to reflect a point about the x-axis
void reflectX(int &x, int &y) {
    y = -y;
}

// Function to reflect a point about the y-axis
void reflectY(int &x, int &y) {
    x = -x;
}

// Function to reflect a triangle about the x-axis
void reflectTriangleX(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) {
    reflectX(x1, y1);
    reflectX(x2, y2);
    reflectX(x3, y3);
}

// Function to reflect a triangle about the y-axis
void reflectTriangleY(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) {
    reflectY(x1, y1);
    reflectY(x2, y2);
    reflectY(x3, y3);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Coordinates of the first vertex
    int x2 = 200, y2 = 200; // Coordinates of the second vertex
    int x3 = 300, y3 = 100; // Coordinates of the third vertex

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Reflect the triangle about the x-axis
    reflectTriangleX(x1, y1, x2, y2, x3, y3);

    // Draw the reflected triangle
    setcolor(RED);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
