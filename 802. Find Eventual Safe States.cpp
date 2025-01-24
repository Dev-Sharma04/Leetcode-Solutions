//Question : There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order

//Approach : Using DFS cycle check
//T.C : O(V+E)
//S.C : O(V)

class Solution {
public:
    bool isCycleDFS(vector<vector<int>>&  adj, int u , vector<bool> &vis,vector<bool>&inRecursion){
        vis[u] = true;
        inRecursion[u] = true;

        for(int &v : adj[u]){
            if(!vis[v] && isCycleDFS(adj,v,vis,inRecursion))return true;
            else if(inRecursion[v])return true;
        }
        inRecursion[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> vis(V,false);
        vector<bool> inRecursion(V,false);
        vector<int> ans;

        for(int i = 0; i < V; i++){
            if(!vis[i] ){
                isCycleDFS(graph,i,vis,inRecursion);
            }
        }

        for(int i  =0 ; i < V; i++){
            if(inRecursion[i] == false)ans.push_back(i);
        }
        return ans;
    }
};

//Approach : Using BFS cycle check(Kahn Algo)
//T.C : O(V+E)
//S.C : O(V)

class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        queue<int> q;
        int V = graph.size();
        vector<vector<int>> adj(V);
        vector<int> inDegree(V,0);

        for(int u = 0; u < V; u++){
            for(int& v : graph[u]){
                adj[v].push_back(u);
                inDegree[u]++;
            }
        }
    
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0)q.push(i);
        }

        vector<bool> safe(V);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            safe[u] = true;
            for(int& v : adj[u]){
                inDegree[v]--;

                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        vector<int>ans;
        for(int i = 0; i < V; i++){
            if(safe[i])ans.push_back(i);
        }
        return ans;
    }
};
