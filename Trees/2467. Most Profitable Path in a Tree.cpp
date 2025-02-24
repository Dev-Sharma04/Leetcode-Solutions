//Question : There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

// the price needed to open the gate at node i, if amount[i] is negative, or,
// the cash reward obtained on opening the gate at node i, otherwise.
// The game goes on as follows:

// Initially, Alice is at node 0 and Bob is at node bob.
// At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
// For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
// If the gate is already open, no price will be required, nor will there be any cash reward.
// If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
// If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
// Return the maximum net income Alice can have if she travels towards the optimal leaf node.


//Approach : Using DFS
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> bobMap;
    int aliceIncome ;
    bool dfsBob(int u, int time, vector<bool>&vis){
        vis[u] = true;
        bobMap[u] = time;

        if(u == 0)return true;
        for(int &v : adj[u]){
            if(!vis[v]){
                if(dfsBob(v,time+1,vis) == true)return true;
            }
        }
        bobMap.erase(u);
        return false;
    }

    void dfsAlice(int u, int time ,int income,vector<bool> &vis,vector<int>& amt ){
        vis[u] = true;
        if(bobMap.find(u) == bobMap.end() || bobMap[u] > time)income += amt[u];
        else if(bobMap[u] == time)income += amt[u]/2;

        if(adj[u].size() == 1 && u != 0){
            aliceIncome = max(aliceIncome,income);
        }
        for(int &v : adj[u]){
            if(!vis[v]){
                dfsAlice(v,time+1,income,vis,amt);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        aliceIncome = INT_MIN;
        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //DFS -> Bob to find time ofeach node till raech 0
        int time = 0;
        vector<bool> vis(n,false);
        dfsBob(bob,time,vis);
        vis.assign(n,false);
        int income = 0;
        dfsAlice(0,0,income, vis,amount);

        return aliceIncome;
    }
};
