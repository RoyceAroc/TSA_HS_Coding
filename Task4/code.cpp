#include <bits/stdc++.h> 

using namespace std;

int main()
{
    int bal; cin >> bal;
    string pos[6][bal*6];
    for(int i=0; i<bal; ++i) {
        for(int j=0; j<6; ++j) {
            string name; cin >> name;
            pos[i][j] = name;
        }
    }
    //Alphabetical sort & Analysis TBD
}
