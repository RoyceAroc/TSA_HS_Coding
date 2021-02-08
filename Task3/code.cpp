#include <bits/stdc++.h> 

using namespace std;

int main()
{
    string varGiven; cin >> varGiven;
    double valGiven; cin >> valGiven;
    if(varGiven == "volume") {
        double radius = cbrt(((3.0)*(valGiven))/((4.0)*(3.14159)));
        printf("%.1f",radius);
    } else {
        double volume = (4.0/3.0) * (3.14159) * (valGiven) * (valGiven) * (valGiven);
        printf("%.1f",volume);
    }
}
