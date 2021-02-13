#include <bits/stdc++.h> 

using namespace std;

char pos[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

bool final = true;
bool check(int boundA, int boundB, int x, int y) {
    if((x > boundA || x < 0) || (y > boundB || y < 1))
        return false;
    return true;
}

void calculate(int cols, int rows, int x, int y, string moves) {
    for(int i=0; i<moves.length(); ++i) {
        if(check(cols, rows, x, y)) {
            if(moves[i] == 'N') {
                y -= 1;
            } else if(moves[i] == 'E') {
                x += 1;
            } else if(moves[i] == 'S') {
                y += 1;
            } else {
                x -= 1;
            }
        } else {
            cout << "Out of bounds.";
            final = false;
            break;
        }
    }
    if(final) 
        cout << pos[x] << y;
}

int main()
{
    int cols; int rows; 
    cin >> cols; cin >> rows;
    char startCol; cin >> startCol;int startRow; cin >> startRow;
    string moves;cin.ignore(); getline(cin, moves);
    for(int i=0; i<26; ++i) {
        if(startCol == pos[i]) {
            calculate(cols, rows, i, startRow, moves);
        } 
    }
}
