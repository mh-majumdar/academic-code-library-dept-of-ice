#include <graphics.h> 

int main() 
{ 
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, ""); 

    // coordinates of hexagon
    int arr[] = {300, 100, 400, 150, 400, 250, 300, 300, 200, 250, 200, 150, 300, 100, 300, 100}; 

    drawpoly(7, arr); 

    getch(); 

    closegraph(); 

    return 0; 
} 
