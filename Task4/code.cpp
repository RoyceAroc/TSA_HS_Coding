#include <bits/stdc++.h> 

using namespace std;

string positions[6] = {"President", "Vice President", "Secretary", "Treasurer", "Reporter", "Sergeant-at-Arms"};

bool cmp(pair<string, int>& a, 
         pair<string, int>& b) 
{ 
    return a.second > b.second; 
} 

void sort(map<string, int>& M, int current) 
{ 
    vector<pair<string, int>> A; 
    for (auto& it : M) { 
        A.push_back(it); 
    } 
    sort(A.begin(), A.end(), cmp); 
    vector<pair<string, int>>::iterator first;
    first = A.begin();
    vector<pair<string, int>>::iterator second;
    second = A.begin(); second++;
    if(first->second > second->second || A.size() == 1) {
        cout << positions[current] << ": " << first->first << ", " << first->second << endl;
    } else {
        cout << positions[current] << ": -tie-";
        for (auto& it : A) { 
            if(it.second == first->second) {
                cout << " " + it.first;
            }
        }
        cout << ", " << first->second << endl;
    }
    A.clear();
} 

int main()
{
    int bal; cin >> bal;
    string pos[6][bal];
    for(int i=0; i<bal; ++i) {
        for(int j=0; j<6; ++j) {
            string name; cin >> name;
            pos[j][i] = name;
        }
    }
    map<string, int> occurence;
    for(int i=0; i<6; ++i) { 
        sort(pos[i], pos[i]+bal);
        for(int j=0; j<bal; ++j) {
            if(occurence.find(pos[i][j]) == occurence.end()) {
                occurence[pos[i][j]] = 1;
            } else {
                occurence[pos[i][j]] += 1;
            }
        }
        sort(occurence, i);
        occurence.clear();
    }
}
