Question : You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

  //Approach : Brute Force
  //T.C : O(n*n*m)
  //S.C : O(S)

  class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> s(supplies.begin(),supplies.end());
        vector<string> ans;
        int n = recipes.size();

        vector<bool> cooked(n,false);

        int cnt = n;
        while(cnt--){
            for(int i = 0; i < n ; i++){
                if(cooked[i])continue;

                bool possible = true;
                for(int j = 0; j < ingredients[i].size(); j++){
                    if(!s.count(ingredients[i][j])){
                        possible = false;
                        break;
                    }
                }
                if(possible){
                    s.insert(recipes[i]);
                    cooked[i] = true;
                    ans.push_back(recipes[i]);
                }
            }

        }
        

        return ans;
    }
};

//Approach : Topo Sort(Kahn's Algo)
//T.C : O(n+m)
//S.C : O(S)

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> s(supplies.begin(),supplies.end());
        
        unordered_map<string,vector<int>> adj;
        vector<int> inDegree(n,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < ingredients[i].size(); j++){
                if(!s.count(ingredients[i][j])){
                    adj[ingredients[i][j]].push_back(i);
                    inDegree[i]++;
                }
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0)q.push(i);
        }
        vector<string> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            string recipe = recipes[node];
            ans.push_back(recipe);
            for(auto &adjNode :adj[recipe]
            ){
                inDegree[adjNode]--;
                if(inDegree[adjNode] == 0)q.push(adjNode);
            }
        }
        return ans;
    }
};
