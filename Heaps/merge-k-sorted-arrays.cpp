//Problem : Merge k sorted arrays
//GFG link : https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/
// Solved using Min Heap (Priority Queue)
// Time: O(N log N), Space: O(N) --- where N = K*K

class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> minheap;
        
        for(int i=0; i<K; i++){
            for(int j=0; j<K; j++){
                minheap.push(arr[i][j]);
            }
        }
        
        while(!minheap.empty()){
            int top = minheap.top();
            minheap.pop();
            ans.push_back(top);
        }
        
        return ans;
    }
};