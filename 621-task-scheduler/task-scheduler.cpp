#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequency of each task
        unordered_map<char, int> taskCount;
        for (char task : tasks) {
            taskCount[task]++;
        }
        
        // Step 2: Create a max-heap based on task frequency
        priority_queue<int> maxHeap;
        for (auto& it : taskCount) {
            maxHeap.push(it.second);
        }
        
        int time = 0; // Total time counter
        
        // Step 3: Process tasks in cycles of length n+1
        while (!maxHeap.empty()) {
            vector<int> temp;  // store tasks that are cooling down in this cycle
            int cycle = n + 1; // cycle length
            
            // Process up to n+1 tasks in one cycle
            for (int i = 0; i < cycle; i++) {
                if (!maxHeap.empty()) {
                    int cnt = maxHeap.top();
                    maxHeap.pop();
                    
                    // Decrease count; if still > 0, put in temp to re-add later
                    if (cnt - 1 > 0) {
                        temp.push_back(cnt - 1);
                    }
                }
                
                time++; // Increment time for each slot (task or idle)
                
                // Early exit: all tasks done
                if (maxHeap.empty() && temp.empty()) {
                    break;
                }
            }
            
            // Push remaining tasks back into the heap
            for (int cnt : temp) {
                maxHeap.push(cnt);
            }
        }
        
        return time;
    }
};
