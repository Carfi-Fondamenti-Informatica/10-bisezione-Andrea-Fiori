#include <iostream>
#include "math.h"

using namespace std;

float f(float a);
bool control(float a, float b);
float rid(float a);
void bisezione(float a, float b);
void principale();

int main() {
    principale();
    return 0;
}

void principale(){
    cout << "inserire estremi" << endl;
    float a = 0;
    float b = 0;
    cin >> a;
    cin >> b;
    bisezione(a,b);
}

float f(float a){
    float b = 0;
    b = (pow(a,2) * cos(a) + 1);
    return b;
}

float rid(float a){
    return floorf(a * 10000) / 10000;
}

bool control(float a, float b){
    if (f(a)*f(b)< 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bisezione(float a, float b){
    float x = 0 ;
    float error = 0;
    if (control(a,b))
    {
        do{
            x = (a + b) / 2;
            if (f(x) == 0)
            {
                break;
            }
            else if (f(x) * f(b) < 0 )
            {
                a = x;
                error = abs( (b - a) / 2 );
            }
            else
            {
                b = x;
                error = abs( (b - a ) / 2 );
            }
        } while (error >= 1/ pow(M_E, 6));
        cout << rid(x)<< endl;
        cout << rid(f(x));
    }
    else {
        do {
            cout << "inserire estremi" << endl;
            cin >> a;
            cin >> b;
        } while (!control(a, b));
        bisezione(a,b);
    }
}
