Question : You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.


//Approach : Segment Tree
//T.C : O(nlog(n))
//S.C : O(4*n)

class Solution {
public:
    void updateSegmentTree(int i, int l , int r, int idx, vector<long long> &segmentTree ){
        if( l == r){
            segmentTree[i] = 1;//mark visited
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid)updateSegmentTree(2*i+1,l,mid,idx,segmentTree);
        else updateSegmentTree(2*i+2,mid+1,r,idx,segmentTree);


        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    long long querySegmentTree(int qs, int qe,int idx,  int l, int r, vector<long long> &segmentTree  ){
        if(r < qs || l > qe)return 0;

        if(l >= qs && r <= qe)return segmentTree[idx];

        int mid = l + (r-l)/2;

        long long left  = querySegmentTree(qs,qe,2*idx+1,l,mid,segmentTree);
        long long right  = querySegmentTree(qs,qe,2*idx+2,mid+1,r,segmentTree);

        return left + right;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp; // stores idx of nums2 
        int n = nums1.size();

        for(int i = 0; i < n; i++){
            mpp[nums2[i]] = i;
        }

        //segment Tree
        vector<long long> segmentTree(4*n);
        long long ans = 0;

        updateSegmentTree(0,0,n-1, mpp[nums1[0]],segmentTree); //(startidx ofsegmenttree, l, r, idx of nums1[i] in nums2, segmentTree)


        for(int i = 1; i < n; i++){ //1 se islie start kra coz uske phle we wont get any common elemnets
            int idx = mpp[nums1[i]];

            long long leftCommonCount = querySegmentTree(0,idx,0,0,n-1,segmentTree); // (startidx, endidx, startidx of segtree, start, end, ssegmnertree)
            long long leftNonCommonCount = i - leftCommonCount;
            long long elementAfterIdxNums2 = n - idx - 1;
            long long rightCommonCount = elementAfterIdxNums2 - leftNonCommonCount;

            ans += leftCommonCount*rightCommonCount;
            updateSegmentTree(0,0,n-1,idx,segmentTree); //(startidx of segtree, l , r, idx, segtree)
        }
        return ans;
    }
};
