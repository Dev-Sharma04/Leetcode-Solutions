Question : You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.

//Approach : Simulation
//T.C : O(nlogn + n)
//S.C : O(1)

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int s = 0;
        int end = 0;
        int ans  = 0;
        for(auto &meet : meetings){
            if(meet[0] > end){
                ans += meet[0] - end -1;
            }
            end = max(end,meet[1]);
            
        }
        if(end < days)ans += days-end;
        return ans;
    }
};
