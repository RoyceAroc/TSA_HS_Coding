#include <bits/stdc++.h> 

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin); // Get input from file "input.txt"
    freopen("output.txt", "w", stdout); // Print output to the file "output.txt"

    string varGiven; cin >> varGiven;
    double valGiven; cin >> valGiven;

    /* Conditional loop to proceed with the correct mathematical operation */
    if(varGiven == "volume") {
        double radius = cbrt(((3.0)*(valGiven))/((4.0)*(3.14159))); // Mathematical operations to find the radius (given the volume)
        printf("%.1f",radius); // Print the radius to the tenth place in decimal format
    } else {
        double volume = (4.0/3.0) * (3.14159) * (valGiven) * (valGiven) * (valGiven); // Mathematical operations to find the volume (given the radius)
        printf("%.1f",volume); // Print the volume to the tenth place in decimal format
    }
}
