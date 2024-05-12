#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set initial dimensions for the ellipse
    int x = 200, y = 200;
    int rx = 150, ry = 100;

    // Draw ellipses with decreasing dimensions and filling color
    while (rx > 0 && ry > 0) {
        setfillstyle(SOLID_FILL, YELLOW); // Set fill color
        fillellipse(x, y, rx, ry); // Fill ellipse
        delay(50); // Delay for smooth animation
        // setfillstyle(SOLID_FILL, BLACK); // Set background color for clearing
        // fillellipse(x, y, rx, ry); // Clear previous ellipse
        rx -= 5; // Decrease x-radius
        ry -= 5; // Decrease y-radius
    }

    getch();
    closegraph();
    return 0;
}
