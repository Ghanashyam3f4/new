#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cstdlib>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    initwindow(720, 720, "A MAN WALKING A RAIN ");
    for (int i = 0; i < 1000; i++)
    {
        circle(60 + i, 200, 20); // face
        circle(60 + i, 200, 2);
        circle(50 + i, 200, 5);
        circle(70 + i, 200, 5);
        arc(60 + i, 210, 180, 360, 3);
        line(60 + i, 220, 60 + i, 270); // nake
        line(60 + i, 240, 40 + i, 270); // hands
        line(60 + i, 240, 100 + i, 270);
        line(60 + i, 270, 30 + i, 330); // legs
        line(60 + i, 270, 90 + i, 330);
        line(100 + i, 274, 100 + i, 150); // umbrella stick
        arc(100 + i, 150, 0, 180, 100);   // umbrella
        line(i, 150, 200 + i, 150);
        line(0, 330, 720, 330); // ground
        int x = getmaxx();
        int y = getmaxy();
        for (int j = 0; j < 100; j++)
        {
            setcolor(WHITE);
            outtextxy(rand() % x, rand() % y, "`"); // rain
        }
        cleardevice();
        delay(1);
    }
    getch();
    getch();
    closegraph();
}