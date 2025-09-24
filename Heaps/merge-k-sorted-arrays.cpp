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






/// ------ optimized solution ------
// Time: O(N log K)

class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        //min heap
        vector<pair<int, pair<int, int>>> temp;
        
        for(int i=0; i<k; i++){
            temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));
        }
       //store the element and the row and column of that element
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());
        
        
        vector<int> ans;
        pair<int, pair<int, int>> Element;
        
        int i, j;
        
        while(!p.empty()){
            Element = p.top();
            p.pop();
            ans.push_back(Element.first);
            i = Element.second.first;
            j = Element.second.second;
            if(j+1 < k){
                p.push(make_pair(arr[i][j+1], make_pair(i, j+1)));
            }
        }
        
        return ans;
        
    }
};
