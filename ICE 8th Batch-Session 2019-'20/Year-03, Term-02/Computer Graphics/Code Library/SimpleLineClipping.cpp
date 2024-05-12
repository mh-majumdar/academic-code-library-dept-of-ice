#include <iostream>
#include <graphics.h>
using namespace std;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

const int X_MIN = 50;
const int X_MAX = 250;
const int Y_MIN = 50;
const int Y_MAX = 250;

// Function to clip a line using Liang-Barsky algorithm
void liangBarsky(int x1, int y1, int x2, int y2) {
    float t0 = 0, t1 = 1;
    int dx = x2 - x1;
    int dy = y2 - y1;

    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x1 - X_MIN, X_MAX - x1, y1 - Y_MIN, Y_MAX - y1};

    for (int i = 0; i < 4; ++i) {
        if (p[i] == 0) {
            if (q[i] < 0) return; // Line is parallel to clipping boundary and outside
        } else {
            float t = q[i] / p[i];
            if (p[i] < 0) {
                if (t > t1) return; // Line is outside
                t0 = max(t0, t);
            } else {
                if (t < t0) return; // Line is outside
                t1 = min(t1, t);
            }
        }
    }

    int x1_clip = x1 + t0 * dx;
    int y1_clip = y1 + t0 * dy;
    int x2_clip = x1 + t1 * dx;
    int y2_clip = y1 + t1 * dy;

    // Draw the clipped line
    line(x1_clip, y1_clip, x2_clip, y2_clip);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    int x1 = 20, y1 = 200;
    int x2 = 300, y2 = 10;

    line(x1, y1, x2, y2);

    liangBarsky(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
