#include <bits/stdc++.h> 

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin); // Get input from file "input.txt"
    freopen("output.txt", "w", stdout); // Print output to the file "output.txt"

    string text; getline(cin, text); 
    string subset; getline(cin, subset);
    string replace; getline(cin, replace);

    text = regex_replace(text, regex(subset), replace); // replace all instances in the original string that match the subsequent string format

    cout << text; // Print out the modified string
}
