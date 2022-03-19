#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

int main()
{

    int gd = DETECT, gm;

    initgraph(&gd, &gm, NULL);
 
	rectangle(100,20.100, 150);
    circle(300, 200, 300);
 
getch();
    delay(500000);

    closegraph();

    return 0;
}
