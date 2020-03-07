/* Copyright (C) Sazzad Shopno - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Sazzad Shopno <sazzadshopno6@gmail.com>, August 1999
 */
#include <graphics.h>
#include <dos.h>
#include <cmath>
#include <iostream>
using namespace std;
void DDAalgorithm(int x1, int y1, int x2, int y2);
/**
    Algorithm:
    Step 1: set x := x1, y := y1, dx := abs(x1 - x2), dy := abs(y1 - y2);
    Step 2: set moves := max(dx, dy), xinc := round(dx / moves), yinc := round(dy / moves);
    Step 3: for i:= 0 to moves do {
        putpixel(x, y, WHITE);
        x := x + xinc;
        y := y + yinc;
    }
**/
int main(){
    /**INITIALIZE GRAPHICS**/
    int graphDriver = DETECT, graphMode;
    initgraph(&graphDriver, &graphMode, "c:\\bgi");
    /****/

    int x1, x2, y1, y2;
    cout << "Enter the value of x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter the value of x2 and y2: ";
    cin >> x2 >> y2;

    DDAalgorithm(x1, y1, x2, y2);

    getch();
    /** CLOSE GRAPHICS**/
    closegraph();
    return 0;
}

void DDAalgorithm(int x1, int y1, int x2, int y2){
    int dx, dy, moves, x, y;
    float m, xinc, yinc;
    dx = abs(x1 - x2);
    dy = abs(y1 - y2);
    moves = max(dx, dy);
    m = dy * 1.0 / dx;
    xinc = round(dx * 1.0 / moves);
    yinc = round(dy * 1.0 / moves);
    x = x1, y = y1;
    for(int i = 0; i < moves; i++){
        putpixel(x, y, WHITE);
        x += xinc;
        y += yinc;
    }
}
