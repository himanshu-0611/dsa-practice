#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

bool isSafe(vector<vector<int>> maze, int newX, int newY, vector<vector<bool>>& visited) {
    if(0 <= newX && newX < maze.size()
            && 0 <= newY && newY < maze[0].size()
            && maze[newX][newY] == 1
            && visited[newX][newY] == false) {
        return true;
    }
    return false;
}

void printPath(vector<vector<int>>& maze, int currX, int currY, int destX, int destY,
               vector<vector<bool>>& visited, vector<string>& ans, string output) {

    if (currX == destX && currY == destY) {
        ans.push_back(output);
        return;
    }

    visited[currX][currY] = true;

    // Up
    if (isSafe(maze, currX, currY - 1, visited)) {
        printPath(maze, currX, currY - 1, destX, destY, visited, ans, output + 'U');
    }

    // Down
    if (isSafe(maze, currX, currY + 1, visited)) {
        printPath(maze, currX, currY + 1, destX, destY, visited, ans, output + 'D');
    }

    // Left
    if (isSafe(maze, currX - 1, currY, visited)) {
        printPath(maze, currX - 1, currY, destX, destY, visited, ans, output + 'L');
    }

    // Right
    if (isSafe(maze, currX + 1, currY, visited)) {
        printPath(maze, currX + 1, currY, destX, destY, visited, ans, output + 'R');
    }

    visited[currX][currY] = false;
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    int destX = maze.size() - 1;
    int destY = maze[0].size() - 1;
    vector<string> ans;

    if (maze[0][0] == 1) {
        printPath(maze, 0, 0, destX, destY, visited, ans, "");
    }

    for(auto it : ans) {
        cout << it << endl;
    }
    return ans;
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 1, 1}};
    ratInMaze(maze);
    return 0;
}
