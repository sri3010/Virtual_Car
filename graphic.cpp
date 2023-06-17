/*#include<graphics.h>
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	circle(320,240,200);
	getch();
	closegraph();
	
}*/
#include <graphics.h>
int main()
{
   int gd = DETECT, gm;
   int x = 320, y = 240, radius;
       
   initgraph(&gd, &gm,(char*)"");
       
   for ( radius = 25; radius <= 125 ; radius = radius + 20)
      circle(x, y, radius);
       
   getch();
   closegraph();
   return 0;
}
