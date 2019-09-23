#include <graphics.h>
#include<math.h>

int main()
{
   int gd = DETECT,gm,x1=20,y1=120,x2=60,y2=90,dx,dy,steps,xinc,yinc,i,x,y;
   initgraph(&gd,&gm,NULL);
   dx = abs(x2 - x1);
   dy = abs(y2 - y1);
   if (dx>dy) {
      steps = dx;
   }
   else
   {
      steps = dy;
   }
   xinc = dx/steps;
   yinc = dy/steps;
   x = xinc;
   y = yinc;

   putpixel(x,y,15);

   for( i = 0; i < steps; i++)
   {
      x += xinc;
      y += yinc;
      putpixel(x,y,15);
   }
   
   

   delay(5000);
   closegraph();
   return 0;
}