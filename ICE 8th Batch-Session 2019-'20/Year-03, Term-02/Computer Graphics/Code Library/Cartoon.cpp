#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

// Function to draw a cartoon character
void drawCharacter(int x, int y) {
    // Head
    circle(x, y, 40);
    // Eyes
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x - 20, y - 10, 10, 10);
    fillellipse(x + 20, y - 10, 10, 10);
    // Mouth
    arc(x, y, 225, 315, 20);
    // Body
    rectangle(x - 30, y + 40, x + 30, y + 100);
    // Arms
    line(x - 30, y + 60, x - 60, y + 40);
    line(x + 30, y + 60, x + 60, y + 40);
    // Legs
    line(x - 15, y + 100, x - 30, y + 150);
    line(x + 15, y + 100, x + 30, y + 150);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set background color
    setbkcolor(LIGHTBLUE);

    // Draw the cartoon character at different positions
    for (int i = 0; i < 500; i += 20) {
        cleardevice(); // Clear the screen
        drawCharacter(i, 200);
        delay(100); // Delay for smooth animation
    }

    getch();
    closegraph();
    return 0;
}
