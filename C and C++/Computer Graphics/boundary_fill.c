#include<stdio.h>
#include<graphics.h>
#include<math.h>

void boundary_fill(int x,int y,int bc,int nc){
    if(getpixel(x,y)!=bc && getpixel(x,y)!=nc){
        putpixel(x,y,nc);
        boundary_fill(x,y+1,bc,nc);
        boundary_fill(x,y-1,bc,nc);
        boundary_fill(x+1,y,bc,nc);
        boundary_fill(x-1,y,bc,nc);
        boundary_fill(x+1,y+1,bc,nc);
        boundary_fill(x+1,y-1,bc,nc);
        boundary_fill(x-1,y+1,bc,nc);
        boundary_fill(x-1,y-1,bc,nc);
    }
}

void main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    rectangle(20,20,80,150);
    boundary_fill(30,30,WHITE,WHITE);
    delay(5000);    
    closegraph();
}