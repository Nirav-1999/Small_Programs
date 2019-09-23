#include<stdio.h>
#include<graphics.h>
#include<math.h>

void bezier(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    float t;
    for(t = 0;t < 1.0; t+= 0.0005){
        double xt = pow(1-t,3)*x1 + 3*t*pow(1-t,2)*x2 + 3*t*t*(1-t)*x3 + t*t*t*x4;
        double yt = pow(1-t,3)*y1 + 3*t*pow(1-t,2)*y2 + 3*t*t*(1-t)*y3 + t*t*t*y4;
        putpixel(xt,yt,WHITE);
    }
}

void main(){
    int gd = DETECT,gm,x1 = 50,y1 = 250,x2 = 200, y2 = 400, x3 = 400 ,y3 = 400,x4 = 600,y4 = 100;
    initgraph(&gd,&gm,NULL);
    bezier(x1,y1,x2,y2,x3,y3,x4,y4);
    bezier(x1,y1,x2,y1-150,x3,y1-150,x4,y1+150);
    line(x4,y4,x4,y1+150);
    bezier(70,250,74,255,78,255,82,250);
    bezier(70,250,74,245,78,245,82,250);
    delay(10000);
    closegraph();
}