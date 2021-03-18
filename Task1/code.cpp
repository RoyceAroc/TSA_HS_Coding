#include <bits/stdc++.h> 

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin); // Get input from file "input.txt"
    freopen("output.txt", "w", stdout); // Print output to the file "output.txt"

    int num; string text;
    cin >> num; cin.ignore();
    getline(cin, text);

    for(int i=1; i<=num; ++i) { //For loop to iterate across instances
        cout << i << " " << text << endl; // Print out the iteration number, followed by a space, and ending with the text
    }
}