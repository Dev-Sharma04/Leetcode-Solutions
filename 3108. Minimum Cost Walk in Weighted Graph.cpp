Question : There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

//Approach : DSU
//T.C  : O(Q + E*log(V))
//S.C : O(n)

Learning : And of any number with -1 is itself;

class Solution {
public:
    vector<int> parent;
    void Union(int x, int y){
        parent[y] = x;
    }
    int find(int x){
        if(parent[x] == x)return x;

        return parent[x] = find(parent[x]);
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> cost(n,-1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
            cost[i] = -1;
        }

        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            int par_u = find(u);
            int par_v = find(v);

            if(par_u != par_v){
                Union(par_u,par_v);
                cost[par_u] &=cost[par_v];
            }
            cost[par_u] &=wt;
        }
        vector<int> ans;
        for(auto &q : query){
            int u = q[0];
            int v = q[1];

            int par_u = find(u);
            int par_v = find(v);

            if(u == v)ans.push_back(0);

            else if(par_u != par_v)ans.push_back(-1);
            else {
                ans.push_back(cost[parent[u]]);
            }
        }
        return ans;
    }
};
