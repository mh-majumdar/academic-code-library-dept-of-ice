#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set text color
    setcolor(RED);

    // Set background color
    setbkcolor(LIGHTGRAY);

    // Draw text
    outtextxy(100, 100, "Hello, World!");

    getch();
    closegraph();
    return 0;
}
