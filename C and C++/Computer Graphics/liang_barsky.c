#include<stdio.h>
#include<graphics.h>
#include<math.h>

void main(){
    int gd = DETECT,gm,x1 = 150,y1 = 170,x2 = 270, y2 = 270, xmin = 200 ,ymin = 200,xmax = 300,ymax = 300,dx,dy,i,xx1,xx2,yy1,yy2;
    float t1,t2,P[4],Q[4],temp;
    initgraph(&gd,&gm,NULL);
    rectangle(xmax,ymax,xmin,ymin);
    dx = x2 - x1;
    dy = y2 - y1;

    P[0] = -dx;
    P[1] = dx;
    P[2] = -dy;
    P[3] = dy;

    Q[0] = x1 - xmin;
    Q[1] = xmax - x1;
    Q[2] = y1 - ymin;
    Q[3] = ymax - y1;

    for(i = 0;i<4;i++){
        if(P[i]==0){
            printf("Line is parallel to the window");
            if(Q[i]>=0){
                if(i<2){
                    if(y1<ymin){
                        y1 = ymin;
                    }
                    if(y2>ymax){
                        y2 = ymax;
                    }
                    line(x1,y1,x2,y2);
                }
                if(i>1){
                    if(x1<xmin){
                        x1 = xmin;
                    }
                    if(x2>xmax){
                        x2 = xmax;
                    }
                    line(x1,y1,x2,y2);
                }
            }
        }
    }

    t1 = 0;
    t2 = 1;

    for(i = 0;i<4;i++){
        temp = Q[i]/P[i];
        printf("%d %d %d ",P[i],Q[i],temp);
        if(P[i]<0){
            if(t1<=temp){
                t1 = temp;
            }
        }
        else
        {
            if(t2>temp){
                t2 = temp;
            }
        }
    }
    if(t1<t2){
        xx1 = x1 + t1*dx;
        xx2 = x1 + t2*dx;
        yy1 = y1 + t1*dy;
        yy2 = y1 + t2*dy;
        printf("%d %d %d %d",xx1,yy1,xx2,yy2);
        line(xx1,yy1,xx2,yy2);

    }  
    delay(100000);
    closegraph();
}