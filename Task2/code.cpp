#include <bits/stdc++.h> 

using namespace std;

int main()
{
    string text; getline(cin, text); 
    string subset; getline(cin, subset);
    string replace; getline(cin, replace);
    text = regex_replace(text, regex(subset), replace);
    cout << text;
}
