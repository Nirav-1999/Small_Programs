#include<stdio.h>
#include<graphics.h>
#include<math.h>

void flood_fill(int x,int y,int oc,int nc){
    if(getpixel(x,y)==oc){
        putpixel(x,y,nc);
        flood_fill(x,y+1,oc,nc);
        flood_fill(x,y-1,oc,nc);
        flood_fill(x+1,y,oc,nc);
        flood_fill(x-1,y,oc,nc);
        flood_fill(x+1,y+1,oc,nc);
        flood_fill(x+1,y-1,oc,nc);
        flood_fill(x-1,y+1,oc,nc);
        flood_fill(x-1,y-1,oc,nc);
    }
}

void main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    rectangle(20,20,80,150);
    flood_fill(30,30,BLACK,WHITE);
    delay(5000);    
    closegraph();
}