//Question : You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
// Return the smallest index i at which either a row or a column will be completely painted in mat.


//Approach 1 : Brute Force (TLE)
//T.C : O(m*n) + O(m*n*(m+n))
//S.C : O(m*n)


class Solution {
public:
    bool checkRowPainted(int row, vector<vector<int>>& mat){
        for(int col = 0; col < mat[0].size(); col++){
            if(mat[row][col] >= 0)return false; //notPainted
        }
        return true;
    }

    bool checkColPainted(int col, vector<vector<int>>& mat){
        for(int row = 0; row < mat.size(); row++){
            if(mat[row][col] >= 0)return false; //notPainted
        }
        return true;
    }
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int,pair<int,int>> mpp; // stores coordinate of [i][j]

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                int val = mat[i][j];
                mpp[val] = {i,j};
            }
        }

        for(int i = 0; i < arr.size(); i++){
            int val = arr[i];

            auto [row,col] = mpp[val];
            mat[row][col] *= -1;//painted

            if(checkRowPainted(row,mat) || checkColPainted(col,mat)){
                return i;
            }        
        }
        return -1;
    }
};

//Approach 2 : Better using map 
//T.C : O(m*n )
//S.C : O(m*n + m*n)

class Solution {
public:
    
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int,pair<int,int>> mpp; // stores coordinate of [i][j]

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                int val = mat[i][j];
                mpp[val] = {i,j};
            }
        }

        vector<int> rowCountPainted(m,0);
        vector<int> colCountPainted(n,0);

        for(int i  = 0; i < arr.size(); i++){
            int val = arr[i];
            auto [row,col] = mpp[val];
            rowCountPainted[row]++;
            colCountPainted[col]++;

            if(rowCountPainted[row] == n || colCountPainted[col] == m)return i;
        
        }
        return -1;
    }
};

//Approach 3 : Optimal
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int,int>mpp; //stores idx at which arr[idx]is present


        for(int i = 0; i< arr.size(); i++){
            mpp[arr[i]] = i;
        }
        
        int minIdx = m*n;

        //check each row one by one
        for(int row = 0; row < m; row++){
            int lastIdx = INT_MIN; //last idx in arr when this row is completely painted
            for(int col = 0; col < n; col++){
                int val = mat[row][col];

                lastIdx = max(lastIdx,mpp[val]);
            }

            minIdx = min(lastIdx,minIdx);
        }

        //check each col one by one
        for(int col = 0; col < n; col++){
            int lastIdx = INT_MIN; //last idx in arr when this col is completely painted
            for(int row = 0; row < m; row++){
                int val = mat[row][col];

                lastIdx = max(lastIdx,mpp[val]);
            }

            minIdx = min(lastIdx,minIdx);
        }
        return minIdx;
    }
};
