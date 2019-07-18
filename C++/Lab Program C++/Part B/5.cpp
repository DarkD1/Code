#include <bits/stdc++.h>
using namespace std;
class POLAR{
    float radius, angle, x, y;
public:
    POLAR(){
        radius = 0, angle = 0, x = 0, y = 0;
    }
    POLAR(float radius, float angle){
        this->radius = radius;
        this->angle = angle;
        this->x = this->radius * cos(this->angle);
        this->y = this->radius * sin(this->angle);
    }
    POLAR operator+(POLAR OBJ){
        POLAR TEMP;
        TEMP.x = this->x + OBJ.x;
        TEMP.y = this->y + OBJ.y;
        TEMP.radius = sqrt(TEMP.x*TEMP.x + TEMP.y*TEMP.y);
        TEMP.angle = atan(TEMP.x/TEMP.y);
        return TEMP;
    }
    void display(){
        cout << "Radius : " << radius << endl << "Angle : " << angle << endl;
    }

};
int main(){
    POLAR OBJ1(5.5,30), OBJ2(5.75,60), OBJ3;
    OBJ3 = OBJ1 + OBJ2;
    OBJ3.display();
    return 0;
}
