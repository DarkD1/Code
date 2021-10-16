/* Copyright (C) Sazzad Shopno - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Sazzad Shopno <sazzadshopno6@gmail.com>, August 1999
 */
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
const double PI = 3.14159265;
int X1, Y1, X2, Y2, X3, Y3;

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void translate(int v);
void rotation(int angle);
int main(){
    int gd = DETECT, gm, xcenter, ycenter, radius;
    initgraph(&gd, &gm, "");
    cout << "Enter the co-ordinates of Triangle: ";
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
    drawTriangle(X1 , Y1 , X2 , Y2 , X3 , Y3 );
    while(true){
        cout << "Operations" << endl;
        cout << "1. Translation\n2. Rotation" << endl;
        int op, angle, translateValue;
        cin >> op;
        switch(op){
        case 1:
            cout << "Enter the translation value: ";
            cin >> translateValue;
            translate(translateValue);
            break;
        case 2:
            cout << "Enter the angle of rotation: ";
            cin >> angle;
            rotation(angle);
            break;
        default:
            cout << "Invalid Operation" << endl;
            break;
        }
    }

    getch();
    closegraph();
    return 0;
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void translate(int v){
    X1 = X1 + v, Y1 = Y1 + v;
    X2 = X2 + v, Y2 = Y2 + v;
    X3 = X3 + v, Y3 = Y3 + v;
    drawTriangle(X1 , Y1 , X2 , Y2 , X3 , Y3 );
}

void rotation(int angle){
    float a =  PI * angle / 180;
    X1 = (X1 * cos(a) - Y1 * sin(a));
    Y1 = (X1 * sin(a) + Y1 * cos(a));
    X2 = (X2 * cos(a) - Y2 * sin(a));
    Y2 = (X2 * sin(a) + Y2 * cos(a));
    X3 = (X3 * cos(a) - Y3 * sin(a));
    Y3 = (X3 * sin(a) + Y3 * cos(a));
    drawTriangle(X1 , Y1 , X2 , Y2 , X3 , Y3 );
}


