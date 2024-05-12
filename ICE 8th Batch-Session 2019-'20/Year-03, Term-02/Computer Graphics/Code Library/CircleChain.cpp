#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set color for circles
    setcolor(BLUE);

    // Set initial position for the first circle
    int x = 100, y = 200;

    // Draw chain of circles
    for (int i = 0; i < 5; ++i) {
        circle(x, y, 20); // Draw circle
        x += 50; // Move to next position
    }

    getch();
    closegraph();
    return 0;
}
