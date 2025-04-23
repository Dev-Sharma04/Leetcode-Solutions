Question : You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.


//Approach : HasMap
//T.C : O(n*log(n))
//S.C : O(1)

  class Solution {
public:
    int find(int num){
        int sum = 0;
        while(num){
            int digit =  num % 10;
            sum += digit;
            num/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        int sumDigits[37]; // store how many num have sum of digits as i
        for(int i = 1; i <= n; i++){
            int digitSum = find(i); //find sum of digits of i

            cout<<digitSum<<endl;
            sumDigits[digitSum]++;
        }

        int maxi = INT_MIN;
        int cnt = 0;
        for(int i = 1; i < 37; i++){
            if(sumDigits[i] > maxi){
                maxi = sumDigits[i];
                cnt = 1;
            }
            else if(maxi == sumDigits[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
