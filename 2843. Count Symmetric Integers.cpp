Question : You are given two positive integers low and high.

An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

Return the number of symmetric integers in the range [low, high].

//Approach : BruteForce
//T.C : O(n^2)
//S.C : O(1)

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++){
            string num = to_string(i);
            if(num.size() % 2 == 1)continue;
            string prefix = num.substr(0, num.size()/2);
            string suffix = num.substr(num.size()/2, num.size());
            cout<<prefix<<" "<<suffix<<endl;
            int s1 = 0, s2 = 0;
            for(char ch : prefix)s1 += ch - 'a';
            for(char ch : suffix)s2 += ch - 'a';

            if(s1 == s2)cnt++;
        }
        return cnt;
    }
};

//Approach : Optimal
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++){
            if (i < 100 && i % 11 == 0)cnt++;
            else if(i >= 1000 && i < 10000){
                int l = i/1000 + (i%1000)/100;
                int r = i%10 + (i % 100)/10;
                if(l == r)cnt++;
            }
        }
        return cnt;
    }
};
