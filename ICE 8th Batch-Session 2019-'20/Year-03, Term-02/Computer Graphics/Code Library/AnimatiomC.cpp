#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm, x = 320, y = 240, radius = 30;
    int dx = 5, dy = 5;

    initgraph(&gd, &gm, "");

    while (!kbhit()) {
        // Clear screen
        cleardevice();

        // Draw ball
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        circle(x, y, radius);
        floodfill(x, y, WHITE);

        // Update ball position
        x += dx;
        y += dy;

        // Check for collisions with screen boundaries
        if (x + radius >= getmaxx() || x - radius <= 0) {
            dx = -dx;
        }
        if (y + radius >= getmaxy() || y - radius <= 0) {
            dy = -dy;
        }

        delay(50);
    }

    closegraph();
    return 0;
}
