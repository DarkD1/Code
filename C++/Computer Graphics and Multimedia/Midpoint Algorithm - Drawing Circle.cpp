/* Copyright (C) Sazzad Shopno - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Sazzad Shopno <sazzadshopno6@gmail.com>, August 1999
 */
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
void midpointCircle(int r);
void drawCircle(int x, int y);
int main(){
    int gd = DETECT, gm, radius;
    cout << "Enter the radius: ";
    cin >> radius;
    initgraph(&gd, &gm, "");
    midpointCircle(radius);
    getch();
    closegraph();
    return 0;
}
void midpointCircle(int r){
    int x = 0, y = r, d = 1 - r;
    drawCircle(x, y);
    while (y >= x){
        drawCircle(x, y);
        if (d > 0){
            d += (2 * (x - y) + 5);
            y--;
        }
        else{
            d += (2 * x + 3);
        }
        x++;
    }
}
// 8 point symmetry of a circle
void drawCircle(int x, int y){
    int xc = getmaxx() / 2, yc = getmaxy() / 2;
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

