#include <iostream>
#include <cmath>

void drawLine(int x1, int y1, int x2, int y2) {
    // Calculate the slope of the line
    float slope = (y2 - y1) / (float)(x2 - x1);
    
    // Determine the character to use for drawing the line
    char symbol;
    if (std::abs(slope) <= 1) {
        symbol = '.';
    } else {
        symbol = '.';
    }
    
    // Iterate through each point and print the line
    for (int x = std::min(x1, x2); x <= std::max(x1, x2); ++x) {
        int y = std::round(y1 + slope * (x - x1));
        std::cout << std::string(x, ' ') << symbol << std::endl;
    }
}

int main() {
    // Example usage
    drawLine(1, 2, 10, 5);
    return 0;
}
