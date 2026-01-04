/*
 * Problem: 1926. Nearest Exit from Entrance in Maze
 * URL: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
 * Difficulty: 
 * Topics: 
 */

#include "./common.hpp"
#include "./structures.hpp"

class Solution {
public:
    // iterate on the neighbours using di, dj
    int di[4]={-1, 0, 1, 0};
    int dj[4]={0, 1, 0, -1};
    bool isValid(int n, int m, int i, int j){
        if(i>=n || i<0 || j>=m || j<0) return false;
        return true;
    }
    bool isExit(int i, int j, int n, int m){
        if(((i==0) || (i==n-1)) || ((j==0) || (j==m-1))) return true;
        return false;
    }
    int bfs(vector<vector<char>>& maze, pair<int, int> src){
        queue<pair<int, int>> q; 
        int num_of_steps=0, n=maze.size(), m=maze[0].size();
        q.push(src);
        maze[src.first][src.second]='+'; // mark as visited
        while(!q.empty()){
            int s=q.size();
            for(int it=0; it<s; it++){
                pair<int, int> p = q.front(); q.pop();
                // iterate on neighbours of maze[i][j]
                int i=p.first, j=p.second;
                for(int k=0; k<4; k++){
                    int p1=i+di[k], p2=j+dj[k];
                    if(isValid(maze.size(), maze[0].size(), p1, p2) && maze[p1][p2]!='+'){
                        q.push({p1,p2});
                        maze[p1][p2]='+'; // mark as visited
                        if(isExit(p1, p2, n, m)) return num_of_steps+1;
                    }
                }
            }
            num_of_steps++;
        }
        return -1; // we never reached an exit
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        return bfs(maze, {entrance[0], entrance[1]});
    }
};