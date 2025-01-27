//Question : There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
// For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
// Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.
// You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
// Return a boolean array answer, where answer[j] is the answer to the jth query.


//Approach : Using BFS
//T.C : O(Q*(V+E))
//S.C : O(V+E)

class Solution {
public:
    bool bfs(int start, int target, vector<bool>&vis,unordered_map<int,vector<int>> &adj){
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(vis[node])continue;
            vis[node] = true;
            if(node == target)return true;
            for(auto &v : adj[node]){
                if(!vis[v] ){
                    q.push(v);
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;

        unordered_map<int,vector<int>> adj;
        for(int i = 0 ; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(auto & query : queries){
            vector<bool> vis(numCourses,false);
            ans.push_back(bfs(query[0],query[1],vis,adj));
        }
        return ans;
    }
};
