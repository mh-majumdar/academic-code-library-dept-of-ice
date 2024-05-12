
#include <graphics.h> 

// Driver code 
int main() 
{ 
 
    int gd = DETECT, gm; 

    // location of left, top, right, bottom 
    int left = 100, top = 200; 
    int right = 300, bottom = 400; 

    initgraph(&gd, &gm, ""); 
    rectangle(left, top, right, bottom); 

    getch(); 
    closegraph(); 

    return 0; 
} 
