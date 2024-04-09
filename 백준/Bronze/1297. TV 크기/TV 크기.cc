#include <iostream>
#include <cmath>
using namespace std;
int main(){

    int d,h,w;

    cin >> d >> h >> w;

    double i = sqrt(pow(d,2)/(pow(h,2)+pow(w,2)));

    cout << floor(h*i) << " " << floor(w*i);

}