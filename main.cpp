#include <iostream>
#include "math.h"

using namespace std;

void bisezione(double a, double b);
double f(double a);
double rid(double a);
bool control(double a, double b);

int main() {
    double a = 0;
    double b = 0;
    cout << "inserire estremi" << endl;
    cin >> a;
    cin >> b;
    bisezione(a,b);
    return 0;
}
double f(double a){
    double b;
    b = (pow(a,2) * cos(a) + 1);
    return b;

}

bool control(double a, double b){
    if (f(a)*f(b)< 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double rid(double a){
        return a;
}

void bisezione(double a, double b){
    double x = 0;
    double error = 1;
    char mstr[60];
    if (control(a,b))
    {
        while (error > 0.00001)
        {
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
        }
        sprintf(mstr,"%.4f",rid(x));
        cout << mstr;
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
