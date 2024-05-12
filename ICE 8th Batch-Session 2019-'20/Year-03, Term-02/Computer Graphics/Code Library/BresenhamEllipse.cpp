#include <iostream>
#include <cmath>

const int MAX_X = 20;
const int MAX_Y = 20;

void drawPixel(int x, int y, char grid[MAX_X][MAX_Y]) {
    if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y) {
        grid[x][y] = 'O';
    }
}

void drawEllipse(int xc, int yc, int rx, int ry) {
    char grid[MAX_X][MAX_Y];

    for (int i = 0; i < MAX_X; ++i) {
        for (int j = 0; j < MAX_Y; ++j) {
            grid[i][j] = ' ';
        }
    }

    int x = 0;
    int y = ry;
    int rx2 = rx * rx;
    int ry2 = ry * ry;
    int twoRx2 = 2 * rx2;
    int twoRy2 = 2 * ry2;
    int p;
    int px = 0;
    int py = twoRx2 * y;

    // Region 1
    p = round(ry2 - (rx2 * ry) + (0.25 * rx2));
    while (px < py) {
        drawPixel(x + xc, y + yc, grid);
        drawPixel(-x + xc, y + yc, grid);
        drawPixel(x + xc, -y + yc, grid);
        drawPixel(-x + xc, -y + yc, grid);
        x++;
        px += twoRy2;
        if (p < 0) {
            p += ry2 + px;
        } else {
            y--;
            py -= twoRx2;
            p += ry2 + px - py;
        }
    }

    // Region 2
    p = round(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
    while (y >= 0) {
        drawPixel(x + xc, y + yc, grid);
        drawPixel(-x + xc, y + yc, grid);
        drawPixel(x + xc, -y + yc, grid);
        drawPixel(-x + xc, -y + yc, grid);
        y--;
        py -= twoRx2;
        if (p > 0) {
            p += rx2 - py;
        } else {
            x++;
            px += twoRy2;
            p += rx2 - py + px;
        }
    }

    // Print the grid
    for (int j = MAX_Y - 1; j >= 0; --j) {
        for (int i = 0; i < MAX_X; ++i) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example usage
    drawEllipse(10, 10, 8, 5);
    return 0;
}
