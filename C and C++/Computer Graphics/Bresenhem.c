#include<stdio.h>
#include<graphics.h>
#include<math.h>


int direction(int difference)
{
    if(difference>0)
       {	return 1;  }
    else if(difference<0)
       {	return -1;  }
    else return 0;

}


void bres(int x1,int y1, int x2, int y2)
{   int x,y,swap=0,s1,s2,dx,dy;
	dx= abs(x2-x1);
	dy= abs(y2-y1);
	s1=direction(x2-x1);
	s2=direction(y2-y1);
	x=x1;y=y1;
	if(dy>dx)
	{ 
        int temp= dx;
		dx= dy;
		dy= temp;
		swap =1;
	}
	int p = 2*dy-dx ;
	for (int i=0; i<=dx; i++)
    {       putpixel(x,y,WHITE);
            while(p>=0)
            {
                p=p-2*dx;
                if(swap)
                {
                    x=x+s1;
                }
                else y=y+s2;
            }
            p=p+2*dy;
            if(swap)
            {
                y=y+s2;
            }
            else x=x+s1;


	}




}


void house(){
    bres(100,200,300,200);
    bres(100,200,100,400);
    bres(100,400,300,400);
    bres(300,200,300,400);
    bres(100,200,200,100);
    bres(200,100,300,200);
    bres(200,100,400,100);
    bres(400,100,500,200);
    bres(500,200,500,400);
    bres(300,400,500,400);
    bres(300,200,500,200);
}

void main()
{
    /* request auto detection */
    int gd = DETECT, gm, errorcode;

    /* initialize graphics mode */
    initgraph(&gd, &gm, NULL);

    house();



    delay(10000);

    closegraph();

}


