#include <bits/stdc++.h> 

using namespace std;

int main()
{
    int num; string text;
    cin >> num; cin.ignore();
    getline(cin, text);
    for(int i=1; i<=num; ++i) {
        cout << i << " " << text << endl;
    }
}
