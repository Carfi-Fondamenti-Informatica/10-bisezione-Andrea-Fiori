#include <iostream>
#include "math.h"

using namespace std;

void principale(float a, float b);
void bisezione(float a, float b);
float f(float a);
float rid(float a);
bool control(float a, float b);

int main() {
    float a = 0;
    float b = 0;
    cout << "inserire estremi" << endl;
    cin >> a;
    cin >> b; 
    principale(a,b);
    return 0;
}

void principale(float a, float b){
    bisezione(a,b);
}
float f(float a){
    float b;
    b = (pow(a,2) * cos(a) + 1);
    return b;
}
float rid(float a){
    return floorf(a * 10000) / 10000;
}
void bisezione(float a, float b){
    float x = 0 ;
    float error = 0;
    if (control(a,b))
    {
        do{
            x = (a+b)/2;
            if (f(x) == 0)
            {
                break;
            }
            else if (f(x )*f(b) < 0 )
            {
                a = x;
                error = abs( (b-a)/2 );
            }
            else
            {
                b = x;
                error = abs( (b-a)/2 );


            }
        } while (error >= 0.000001);
        cout << x;
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
