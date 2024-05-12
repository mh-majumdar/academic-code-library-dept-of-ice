#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = getmaxx() / 2;
    int y = getmaxy() / 2;
    int radius = 20;
    int dx = 5; // Initial movement in x-direction
    int dy = 5; // Initial movement in y-direction

    while (1) {
        cleardevice(); // Clear the screen
        circle(x, y, radius); // Draw the circle

        // Check for keyboard input
        if (kbhit()) {
            char ch = getch();
            if (ch == 'w' || ch == 'W') {
                y -= dy; // Move up
            } else if (ch == 's' || ch == 'S') {
                y += dy; // Move down
            } else if (ch == 'a' || ch == 'A') {
                x -= dx; // Move left
            } else if (ch == 'd' || ch == 'D') {
                x += dx; // Move right
            } else if (ch == 27) { // ASCII code for escape key
                break; // Exit the loop
            }
        }

        delay(50); // Delay for smooth movement
    }

    closegraph();
    return 0;
}
