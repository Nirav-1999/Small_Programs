#include<stdio.h>
#include<graphics.h>
#include<math.h>

void display(int x1,int y1,int x,int y){
    putpixel(x+x1,y+y1,WHITE);
    putpixel(x+x1,y-y1,WHITE);
    putpixel(x-x1,y+y1,WHITE);
    putpixel(x-x1,y-y1,WHITE);

}

void main(){
    int gd=DETECT,gm,x=300,y=250,p,rx=150,ry=150,x1,y1;
    float d1,d2;
    initgraph(&gd,&gm,NULL);
    x1=0;
    y1=ry;
    display(x1,y1,x,y);
    d1 = ry*ry + rx*rx*(-ry +1/4);
    while(ry*ry*x1<=rx*rx*y1){
        x1++;
        if (d1<=0) {
            d1+=ry*ry*(2*x1+3);
        }
        else
        {
            d1+=ry*ry*(2*x1+3) + rx*rx*(-2*y1+2) ;
            y1--;
        }
        display(x1,y1,x,y);
    }
    d2 = ry*ry*(x1+0.5)*(x1+0.5) + rx*rx*(y1-1)*(y1-1) - rx*rx*ry*ry;
    
    while(y1>0){
        y1--;
        if (d2>0) {
            d2+=rx*rx*(-2*y1+3);
        }
        else
        {
            x1++;
            d2+=rx*rx*(-2*y1+3) + ry*ry*(2*x1+2) ;
        }
        display(x1,y1,x,y);
    }
    

    delay(5000);    
    closegraph();
}