#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <Windows.h>

void drawLine(int x1, int y1, int x2, int y2){
	int dx = x2 - x1;
	int dy = y2 - y1;
	
	putpixel(x1, y1, 15);
	
	if(dx < dy)
	{
		int G = 2*dx - dy;
		do{
		
			if(G >= 0)
			{
				x1++;
				y1++;
				G = G + (2*dx) - (2*dy);
			}
			else
			{
				y1++;
				G = G + (2*dx);
			}
			putpixel(x1, y1, 15);
		}while(y1 != y2);
	}
	
	else
	{
		int G = 2*dy - dx;
		do{
		
			if(G >= 0)
			{
				x1++;
				y1++;
				G = G + (2*dy) - (2*dx);
			}
			else
			{
				x1++;
				G = G + (2*dy);
			}
			putpixel(x1, y1, 15);
		}while(x1 != x2);
	}
	
}

void drawBox(int x1, int y1, int x2, int y2, int num){
	drawLine(x1, y1, x2, y1);
	drawLine(x1, y1, x1, y2);
	drawLine(x1, y2, x2, y2);
	drawLine(x2, y1, x2, y2);
	char s[2];
	sprintf(s, "%d", num);
	outtextxy((x1 + x2)/2, (y1 + y2)/2 - 5, (char*)s);
	Sleep(500);
}

int main(){
	int gd=DETECT, gm;
	int num, temp;
	printf("Enter a number to find the factorial of:\n");
	scanf("%d", &num);
	temp = num;
	int x1 = 250, y1 = 449, x2 = 390, y2 = 479;
	initgraph(&gd, &gm, (char*)"");
	
	outtextxy(10, 240, (char*)"Pushing...");
	
	for(int i=0; i<temp; i++){
		drawBox(x1, y1, x2, y2, num);
		y1 = y1 - 31;
		y2 = y2 - 31;
		num = num - 1;
	}
	
	outtextxy(10, 240, (char*)"Original state");
	outtextxy(10, 260, (char*)"Press any key to continue:");
	
	getch();
	
	cleardevice();
	num = temp;
	
	int fact = 1;
	for(int i=1; i<=temp; i++){
		x1 = 250, y1 = 449, x2 = 390, y2 = 479;
		for(int j=0; j<temp - i; j++){
			drawBox(x1, y1, x2, y2, num);
			y1 = y1 - 31;
			y2 = y2 - 31;
			num = num - 1;
		}
		num = temp;
		fact = fact * i;
		drawBox(x1, y1, x2, y2, fact);
		
		if(i!=temp){
			outtextxy(10, 240, (char*)"Pop the top 2 elements");
			outtextxy(10, 260, (char*)"Push their product to top of stack");
			outtextxy(10, 280, (char*)"Press any key for next stage:");
			getch();
		}
		cleardevice();
	}
	
	outtextxy(10, 240, (char*)"The final Factorial is:");
	outtextxy(10, 260, (char*)"Press any key to exit:");
	drawBox(x1, y1, x2, y2, fact);
	
	getch();
	closegraph();
	return 0;
}