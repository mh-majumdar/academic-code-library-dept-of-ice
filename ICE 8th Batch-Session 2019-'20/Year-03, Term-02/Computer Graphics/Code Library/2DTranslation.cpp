#include <graphics.h>

// Function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

// Function to translate a rectangle about the origin
void translateRectangle(int &x1, int &y1, int &x2, int &y2, int tx, int ty) {
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Coordinates of the top-left corner
    int x2 = 300, y2 = 200; // Coordinates of the bottom-right corner

    // Draw the original rectangle
    drawRectangle(x1, y1, x2, y2);

    // Translation offsets
    int tx = 50, ty = 50;

    // Translate the rectangle about the origin
    translateRectangle(x1, y1, x2, y2, tx, ty);

    // Draw the translated rectangle
    setcolor(RED);
    drawRectangle(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
