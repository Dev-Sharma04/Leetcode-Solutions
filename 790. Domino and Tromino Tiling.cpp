Question : You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

  //Approach : DP
  //T.C : O(n*logm)
  //S.C : O(n)

  class Solution {
public:
     int numTilings(int N) {
    int md=1e9;
    md+=7;
    vector<long long> v(1001,0);
    v[1]=1;
    v[2]=2;
    v[3]=5;
    if(N<=3)
        return v[N];
    for(int i=4;i<=N;++i){
        v[i]=2*v[i-1]+v[i-3]; 
        v[i]%=md;
    }
    return v[N];
    
}
};
