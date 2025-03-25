Question : You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.

  //Approach : Merge Intervals
  //T.C : O(n*log(n))
  //S.C : O(n)

  class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < n; i++){
            if(ans.back()[1] > intervals[i][0] ){
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
            else ans.push_back(intervals[i]);
        }
        return ans;
    }


    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> X;
        vector<vector<int>> Y;

        for(auto &r : rectangles){
            int x1 = r[0];
            int y1 = r[1];
            int x2 = r[2];
            int y2 = r[3];

            X.push_back({x1,x2});
            Y.push_back({y1,y2});
        }
        vector<vector<int>> a = merge(X);
        if(a.size() > 2)return true;
        vector<vector<int>> b = merge(Y);

        return a.size() > 2 || b.size()> 2;
    }
};
