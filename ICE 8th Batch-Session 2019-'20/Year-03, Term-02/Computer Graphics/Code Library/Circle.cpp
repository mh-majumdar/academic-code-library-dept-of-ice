// C Implementation for drawing circle 
#include <graphics.h> 

//driver code 
int main() 
{ 
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); 

	// circle function 
	circle(250, 200, 50); 

	getch(); 
	closegraph(); 

	return 0; 
} 
