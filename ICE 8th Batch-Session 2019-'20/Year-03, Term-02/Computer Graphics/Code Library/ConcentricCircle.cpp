#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set color for circles
    setcolor(BLUE);

    // Set center and radius for the first circle
    int x = 200, y = 200;
    int radius = 50;

    // Draw concentric circles
    for (int i = 0; i < 5; ++i) {
        circle(x, y, radius); // Draw circle
        radius += 20; // Increase radius for next circle
    }

    getch();
    closegraph();
    return 0;
}
