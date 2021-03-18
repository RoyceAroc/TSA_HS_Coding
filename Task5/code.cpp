#include <bits/stdc++.h> 

using namespace std;

char pos[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

bool final = true;
bool check(int boundA, int boundB, int x, int y) {
    /* Return bool function to check whether the robot is within the bounds of the map */
    if((x > boundA || x < 0) || (y > boundB || y < 1))
        return false;
    return true;
}

void calculate(int cols, int rows, int x, int y, string moves) {
    //Make a move for every character in moves
    for(int i=0; i<moves.length(); ++i) {
        if(check(cols, rows, x, y)) { // Check to see if robot has reached bounds, if true (has not reached bounds) then continue
            if(moves[i] == 'N') {
                y -= 1; // Move robot north one unit
            } else if(moves[i] == 'E') {
                x += 1; // Move robot east one unit
            } else if(moves[i] == 'S') {
                y += 1; // Move robot south one unit
            } else {
                x -= 1; // Move robot west one unit
            }
        } else {
            cout << "Out of bounds."; // Since the condition is false, the robot has reached the bounds
            final = false; // Set the bool final to false in order to prevent the printing of the "final coordinate"
            break; // Break out of the for loop
        }
    }
    if(final) // If final is true (could be set to false in the conditional check above)
        cout << pos[x] << y; // Print the "final coordinate"
}

int main()
{
    freopen("input.txt", "r", stdin); // Get input from file "input.txt"
    freopen("output.txt", "w", stdout); // Print output to the file "output.txt"

    int cols; int rows; 
    cin >> cols; cin >> rows; // Input the number of rows & columns

    char startCol; cin >> startCol; int startRow; cin >> startRow; // Input the starting coordinates

    string moves;cin.ignore(); getline(cin, moves); // Get directions

    /* Convert startCol (character) to integer using iterated character array */
    for(int i=0; i<26; ++i) {
        if(startCol == pos[i]) {
            calculate(cols, rows, i, startRow, moves); // Calls the calculate() function to print out the expected output
        } 
    }
}
