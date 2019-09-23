#include<stdio.h>
#include<graphics.h>
#include<math.h>

void main(){
    int gd = DETECT,gm,x1 = 170,y1 = 170,x2 = 270, y2 = 270, xx1,xx2,yy1,yy2,xxx1,yyy1;
    float  rad= 60*3.142/180;
    initgraph(&gd,&gm,NULL);
    line(x1,y1,x2,y2);
    xx2 = 0;
    yy2 = 0;
    xx1 = x1 - x2;
    yy1 = y1 - y2;
    xxx1 = xx1*cos(rad) - yy1*sin(rad);
    yyy1 = xx1*sin(rad) + yy1*cos(rad);
    x1 = xxx1 + x2;
    y1 = yyy1 + y2;
    line(x1,y1,x2,y2);
    delay(5000);
    closegraph();
}