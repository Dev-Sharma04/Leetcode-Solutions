Question : You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:

status[i] is 1 if the ith box is open and 0 if the ith box is closed,
candies[i] is the number of candies in the ith box,
keys[i] is a list of the labels of the boxes you can open after opening the ith box.
containedBoxes[i] is a list of the boxes you found inside the ith box.
You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.

Return the maximum number of candies you can get following the rules above.


//Approach : BFS
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;

        queue<int> q;
        for(auto it : initialBoxes){
            q.push(it);
        }
        vector<bool> vis(status.size(),false);
        while(!q.empty()){
            int box = q.front();
            q.pop();

            
            if(status[box] == 1){
                ans += candies[box];
                candies[box] = 0;
            }
            

            vector<int> key = keys[box];
            vector<int> contained = containedBoxes[box];

            for(auto it: contained){
                q.push(it);
            }

            for(auto it : key){
                status[it] = 1;
                if(vis[it]){
                    ans += candies[it];
                    candies[it] = 0;
                }

            }
            vis[box] = true;
        }
        
        return ans;
    }
};
