#include<stdio.h>
#include<graphics.h>

void display(int x1,int y1,int x,int y){
    putpixel(x+x1,y+y1,WHITE);
    putpixel(x+x1,y-y1,WHITE);
    putpixel(x-x1,y+y1,WHITE);
    putpixel(x-x1,y-y1,WHITE);
    putpixel(x+y1,y+x1,WHITE);
    putpixel(x+y1,y-x1,WHITE);
    putpixel(x-y1,y+x1,WHITE);
    putpixel(x-y1,y-x1,WHITE);

}

void main(){
    int gd=DETECT,gm,x=300,y=300,r=100,p,x1,y1;
    initgraph(&gd,&gm,NULL);
    p=1-r;
    x1=0;
    y1=r;
    while(x1<=y1){
        if (p<0) {
            p=p+2*x1+1;
            x1++;

        }
        else
        {
            p=p+2*(x1-y1)+1;
            x1++;
            y1--;
        }
        
        display(x1,y1,x,y);
        
    }
    delay(5000);    
    closegraph();
}