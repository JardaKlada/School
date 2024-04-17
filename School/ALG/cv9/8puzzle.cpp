#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct PuzzleState {
    vector<vector<int>> board; // Hrací pole
    int emptyRow, emptyCol; // Pozice prázdné dlaždice

    // Konstruktor pro prázdný stav
    PuzzleState() : emptyRow(0), emptyCol(0) {}

    PuzzleState(const vector<vector<int>>& b, int er, int ec) : board(b), emptyRow(er), emptyCol(ec) {}

    // Funkce pro získání nových stavů
    vector<PuzzleState> getNextStates() const {
        vector<PuzzleState> nextStates;
        int numRows = board.size();
        int numCols = board[0].size();
        int dr[] = {1, -1, 0, 0}; // Posun dolů, nahoru, vpravo, vlevo
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; ++i) {
            int newRow = emptyRow + dr[i];
            int newCol = emptyCol + dc[i];

            if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols) {
                vector<vector<int>> newBoard = board;
                swap(newBoard[emptyRow][emptyCol], newBoard[newRow][newCol]);
                PuzzleState nextState(newBoard, newRow, newCol);
                nextStates.push_back(nextState);
            }
        }

        return nextStates;
    }

    // Funkce pro kontrolu výsledku
    bool isGoalState() const {
        int numRows = board.size();
        int numCols = board[0].size();
        vector<vector<int>> goalBoard(numRows, vector<int>(numCols));

        int number = 1;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                goalBoard[i][j] = number++;
            }
        }
        goalBoard[numRows-1][numCols-1] = 0; // Poslední prvek je prázdný

        return board == goalBoard;
    }

    // Funkce pro hashování
    size_t hashValue() const {
        size_t seed = 0;
        for (const auto& row : board) {
            for (int num : row) {
                seed ^= hash<int>()(num) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
        }
        return seed;
    }
};

void printSolution(const PuzzleState& solution);

// Funkce pro řešení 8-puzzle pomocí DFS
bool solvePuzzleDFS(const PuzzleState& initialState) {
    stack<PuzzleState> stack;
    unordered_set<size_t> visitedHashes;
    unordered_map<size_t, PuzzleState> parentMap;

    stack.push(initialState);
    visitedHashes.insert(initialState.hashValue());

    while (!stack.empty()) {
        PuzzleState currentState = stack.top();
        stack.pop();
        if (currentState.isGoalState()) {
            cout << "Found solution!" << endl;
            printSolution(currentState);
            return true;
        }     

        vector<PuzzleState> nextStates = currentState.getNextStates();
        for (const PuzzleState& nextState : nextStates) {
       
            size_t nextStateHash = nextState.hashValue();
            if (visitedHashes.find(nextStateHash) == visitedHashes.end()) {
                stack.push(nextState);
                visitedHashes.insert(nextStateHash);
                parentMap[nextStateHash] = currentState;
            }
        }
    }

    cout << "No solution found!" << endl;
    return false;
}

void printSolution(const PuzzleState& solution) {
    for (const auto& row : solution.board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> initialBoard = {
        {0, 3, 6},
        {7, 1, 4},
        {5, 2, 8},
    }; 

    int emptyRow = 0;
    int emptyCol = 0; 

    PuzzleState initialState(initialBoard, emptyRow, emptyCol);

    // Řešení puzzle pomocí DFS
    solvePuzzleDFS(initialState);

    return 0;
}
