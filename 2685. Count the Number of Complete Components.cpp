You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

//Approach : BFS
//T.C : O(V+E)
//S.C : O(V)

class Solution {
public:

    vector<int> BFS(int start,unordered_map<int,vector<int>> &adj,vector<bool> &vis ){
        queue<int> q;
        q.push(start);
        vector<int>v;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(vis[node])continue;
            v.push_back(node);
            vis[node] = true;

            for(int &v : adj[node]){
                if(!vis[v]){
                    q.push(v);
                }
            }
        }
        return v;
    }
    bool  check(vector<int> &v,unordered_map<int,vector<int>> &adj ){
        int n = v.size();

        for(int i = 0; i < n; i++){
            if(adj[v[i]].size() != n-1)return false;
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> cc;
        int ans = 0;
        vector<bool> vis(n,false); 
        for(int  i = 0; i < n; i++){
            if(!vis[i]){
                cc.push_back(BFS(i,adj,vis));
            }
        }
        for(int i = 0 ; i < cc.size(); i++){
            if(cc[i].size() <= 2)ans++;
            else{
                if(check(cc[i],adj))ans++;
            }
        }
        return ans;
    }
};
