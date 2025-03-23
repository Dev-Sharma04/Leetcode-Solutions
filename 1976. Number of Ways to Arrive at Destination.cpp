Question : You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

  //Approach : Dijkstra
  //T.C : O(Elog(v))
  //S.C : O(V)

  class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(vector<int> &r : roads){
            int u  = r[0];
            int v = r[1];
            int time = r[2];

            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        } 

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<long long> ans(n,LLONG_MAX);
        vector<int> pathCount(n,0);
        ans[0] = 0;
        pathCount[0] = 1;

        while(!pq.empty()){
            long long currTime = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            for(auto &vec : adj[curr]){
                int ngbr = vec.first;
                int time = vec.second;

                if(time + currTime < ans[ngbr]){
                    ans[ngbr] = time+currTime;
                    pq.push({ans[ngbr],ngbr});
                    pathCount[ngbr] = pathCount[curr];
                }
                else if(time + currTime == ans[ngbr]){
                    pathCount[ngbr] = (pathCount[ngbr] + pathCount[curr])%mod;
                }
            }
        }
        return pathCount[n-1];
    }
};
