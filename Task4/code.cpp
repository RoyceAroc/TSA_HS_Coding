#include <bits/stdc++.h> 

using namespace std;

string positions[6] = {"President", "Vice President", "Secretary", "Treasurer", "Reporter", "Sergeant-at-Arms"}; // 6 positions stored in a string array

bool cmp(pair<string, int>& a, 
         pair<string, int>& b) 
{ 
    // Addition to sorting mechanism to make the values in DESCENDING order
    return a.second > b.second; 
} 

void sort(map<string, int>& M, int current) 
{ 
    vector<pair<string, int>> A; 
    for (auto& it : M) { 
        A.push_back(it); // Transform and replicate map to a vector string/int pair
    } 
    sort(A.begin(), A.end(), cmp); // Use the sorting mechanism to sort values in descending order
    vector<pair<string, int>>::iterator first;
    first = A.begin(); // Get the first element
    vector<pair<string, int>>::iterator second;
    second = A.begin(); second++; // Get the second element
    if(first->second > second->second || A.size() == 1) {  // If the value of the first element is greater than the second element OR the vector only contains 1 element
        cout << positions[current] << ": " << first->first << ", " << first->second << endl; // Print the position, followed by a colon, followed by Name, a comma, and the total number of ballots he/she received
    } else {
        cout << positions[current] << ": -tie-"; // Print a tie since there was a tie for this position
        for (auto& it : A) { 
            if(it.second == first->second) {
                cout << " " + it.first; // Print the name of the person who tied for this position
            }
        }
        cout << ", " << first->second << endl; // Print the total number of ballots they tied for 
    }
    A.clear(); // Clear the replicated vector
} 

int main()
{
    freopen("input.txt", "r", stdin); // Get input from file "input.txt"
    freopen("output.txt", "w", stdout); // Print output to the file "output.txt"

    int bal; cin >> bal; // Initialize variable bal by inputting the total number of ballots
    string pos[6][bal]; // Initialize a 2D string array composed of 6 rows and bal columns

    for(int i=0; i<bal; ++i) { // Iterate across each row
        for(int j=0; j<6; ++j) { // Iterate across each column
            string name; cin >> name; 
            pos[j][i] = name; // Store value in the corresponding string array
        }
    }

    map<string, int> occurence; // Key-value pair containing the person's name and his/her number of ballots
    for(int i=0; i<6; ++i) { // Iterate for each position
        sort(pos[i], pos[i]+bal); // Sort names alphabetically in the array 
        for(int j=0; j<bal; ++j) { // Iterate through all names 
            if(occurence.find(pos[i][j]) == occurence.end()) {
                occurence[pos[i][j]] = 1; // New person so create pair
            } else {
                occurence[pos[i][j]] += 1; // Person was created beforehand so increment value in the pair
            }
        }
        sort(occurence, i); // Call the void sort function (code above) to print out the expected output
        occurence.clear(); // Clear the occurence map for the next iterated position
    }
}
