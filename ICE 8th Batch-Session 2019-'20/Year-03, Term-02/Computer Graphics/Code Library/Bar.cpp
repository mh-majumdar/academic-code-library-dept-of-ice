// C implementation of bar() function 
#include <graphics.h> 

// driver code 
int main() 
{ 

	int gd = DETECT, gm; 

	initgraph(&gd, &gm, ""); 

	// location of sides 
	int left, top, right, bottom; 

	// left, top, right, bottom denotes 
	// location of rectangular bar 
	bar(left = 150, top = 150, 
	right = 190, bottom = 350); 

	bar(left = 220, top = 250, 
	right = 260, bottom = 350); 

	bar(left = 290, top = 200, 
	right = 330, bottom = 350); 

	// y axis line 
	line(100, 50, 100, 350); 

	// x axis line 
	line(100, 350, 400, 350); 

	getch();
	closegraph(); 
	
	return 0; 
} 
