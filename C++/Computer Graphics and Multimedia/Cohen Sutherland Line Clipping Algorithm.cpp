/* Copyright (C) Sazzad Shopno - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Sazzad Shopno <sazzadshopno6@gmail.com>, August 1999
 */

#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;
int  WX1 = 150, WY1 = 150, WX2 = 400, WY2 = 350;

class coordinate{
public:
    int x, y, code[4];
    coordinate(){
        for(int i = 0; i < 4; i++){
            code[i] = 0;
        }
    }
    ~coordinate(){}
    void setCode(){
        if(x < WX1){
            code[3] = 1;
        }if(x > WX2){
            code[2] = 1;
        }if(y < WY1){
            code[1] = 1;
        }if(y > WY2){
            code[0] = 1;
        }
    }
};

void drawWindow(){
    line(WX1, WY1, WX2, WY1);
    line(WX1, WY1, WX1, WY2);
    line(WX1, WY2, WX2, WY2);
    line(WX2, WY1, WX2, WY2);
}


int visibilityCheck(coordinate a, coordinate b){
    int sum = 0;
    for(int i = 0; i < 4; i++){
        sum += (a.code[i] + b.code[i]);
    }
    if(sum == 0){
        return 0;
    }else{
        sum = 0;
        for(int i = 0; i < 4; i++){
            sum += (a.code[i] & b.code[i]);
        }
        if(sum != 0){
            return -1;
        }else{
            return 1;
        }
    }
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawWindow();
    while(1){
        coordinate a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        a.setCode();
        b.setCode();
        line(a.x, a.y, b.x, b.y);
        int r = visibilityCheck(a, b);
        if(r == 0){
            printf("Visible!\n");
        }else if(r == -1){
            printf("Not visible.\n");
        }else if(r == 1){
            printf("Clipping candidate.\n");
        }
    }
    getch();
    closegraph();
    return 0;
}
