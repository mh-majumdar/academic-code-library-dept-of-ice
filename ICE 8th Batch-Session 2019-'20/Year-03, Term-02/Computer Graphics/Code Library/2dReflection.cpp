#include <graphics.h>

// Function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2, int color) {
    setcolor(color);
    rectangle(x1, y1, x2, y2);
}

// Function to reflect a point about the x-axis
void reflectX(int &x, int &y) {
    y = -y;
}

// Function to reflect a rectangle about the x-axis
void reflectRectangleX(int &x1, int &y1, int &x2, int &y2) {
    reflectX(x1, y1);
    reflectX(x2, y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Coordinates of the top-left corner
    int x2 = 300, y2 = 200; // Coordinates of the bottom-right corner

    // Draw the original rectangle
    drawRectangle(x1, y1, x2, y2, WHITE);

    // Reflect the rectangle about the x-axis
    reflectRectangleX(x1, y1, x2, y2);

    // Draw the reflected rectangle
    drawRectangle(x1, y1, x2, y2, RED);

    getch();
    closegraph();
    return 0;
}
