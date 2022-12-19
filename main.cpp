#include <iostream>
#include "math.h"
#include <iomanip>

using namespace std;

void principale(double a, double b);
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
    principale(a,b);
    return 0;
}

void principale(double a, double b){
    bisezione(a,b);
}

double f(double a){
    double b;
    b = (pow(a,2) * cos(a) + 1);
    return b;

}
double rid(double a){
    if (a<0)
    return a+0.0001;
    else
        return a;
}
void bisezione(double a, double b){
    double x = 0 ;
    double error = 1;
    double minlimit;
    char mstr[60];
    if (control(a,b))
    {
        minlimit= 0.00001;
        while (error > minlimit)
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
