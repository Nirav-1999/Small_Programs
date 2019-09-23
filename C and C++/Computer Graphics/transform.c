#include<stdio.h>
#include<graphics.h>
#include<math.h>

void main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int left = 100, top = 100, right = 200, bottom = 200;
    
    // Translate
    delay(500);
    int tx=300,ty=100,i=0;
    for(i = left; i < left+tx; i++)
    {
        rectangle(i,top,right+i,bottom);
        cleardevice();
    }
    rectangle(left,top,right,bottom);

    rectangle(left+tx,top+ty,right+tx,bottom+ty);
    
    // Rotate
    delay(500);
    int x1,x2,x3,x4,y1,y2,y3,y4;
    float rad = 10 * 3.14 / 180;
    x1=left*cos(rad) - bottom*sin(rad);
    x2=right*cos(rad) - bottom*sin(rad);
    x3=right*cos(rad) - top*sin(rad);
    x4=left*cos(rad) - top*sin(rad);
    y1=left*sin(rad) + bottom*cos(rad) ;
    y2=right*sin(rad) + bottom*cos(rad) ;
    y3=right*sin(rad) + top*cos(rad) ;
    y4=left*sin(rad) + top*cos(rad) ;
    line(fabs(x1),fabs(y1),fabs(x2),fabs(y2));
    line(fabs(x1),fabs(y1),fabs(x4),fabs(y4));
    line(fabs(x4),fabs(y4),fabs(x3),fabs(y3));
    line(fabs(x2),fabs(y2),fabs(x3),fabs(y3));

    // Scale
    int sx=2,sy=2;
    rectangle(left*sx,top*sx,right*sy,bottom*sy);

    delay(10000);
    closegraph();

    

}