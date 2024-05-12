#include<graphics.h>
#include<stdio.h>
#include<conio.h>
int main( )
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");
  arc(100,100,90,280,10);
  //Arc(x1,y1,StartingAngle,EndingAngle,Radius)
  getch( );
  closegraph( );
}