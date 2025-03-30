Question : You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

//Approach : sliding window
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> result;

        //last occurance of each character
        //unordered_map<char, int> mp;
        vector<int> mp(26, -1);
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            mp[idx] = i;
        }

        int i = 0;
        int start = 0;
        int end = 0;
        while(i < n) {
            end = max(end, mp[s[i]-'a']);
            if(i == end) {
                result.push_back(end-start+1);
                start = end+1;
            }
            i++;
        }

        return result;
    }
};

