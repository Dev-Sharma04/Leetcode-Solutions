//Question :You are given a 0-indexed integer array nums, and an integer k.
// In one operation, you will:
// Take the two smallest integers x and y in nums.
// Remove x and y from nums.
// Add min(x, y) * 2 + max(x, y) anywhere in the array.
// Note that you can only apply the described operation if nums contains at least two elements.
// Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.


//Approach : Using Heap
//T.C : O(n*log(n))
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long , vector<long >, greater<long >> pq(nums.begin(),nums.end()); //heapify -> T.C : 0(log(n))
        
        int cnt = 0;
        while(pq.top() < k){
            long x = pq.top();
            pq.pop();
            long y = pq.top();
            pq.pop();
            pq.push(x*2 + y);
            cnt++;
        }
        return cnt;
    }
};
