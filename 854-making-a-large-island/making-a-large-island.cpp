#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize; // islandId -> size
        int id = 2; // start labeling islands from 2 to distinguish from 0 and 1

        // DFS to label islands and calculate their sizes
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int size = dfs(grid, i, j, id);
                    islandSize[id] = size;
                    id++;
                }
            }
        }

        int ans = 0;
        bool hasZero = false;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    hasZero = true;
                    unordered_set<int> neighborIslands;
                    for(int k=0; k<4; k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj] > 1){
                            neighborIslands.insert(grid[ni][nj]);
                        }
                    }

                    int potentialSize = 1; // flip this 0 to 1
                    for(int neighborId : neighborIslands){
                        potentialSize += islandSize[neighborId];
                    }
                    ans = max(ans, potentialSize);
                }
            }
        }

        // If there was no zero, the whole grid is already one island
        if(!hasZero) return n*n;

        return ans;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int id){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j] != 1) return 0;
        grid[i][j] = id; // mark the island
        int size = 1;
        for(int k=0; k<4; k++){
            size += dfs(grid, i + dx[k], j + dy[k], id);
        }
        return size;
    }
};
