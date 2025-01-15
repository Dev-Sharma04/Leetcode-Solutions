//Question :Given two positive integers num1 and num2, find the positive integer x such that:
// x has the same number of set bits as num2, and
// The value x XOR num1 is minimal.
// Note that XOR is the bitwise XOR operation.
// Return the integer x. The test cases are generated such that x is uniquely determined.
// The number of set bits of an integer is the number of 1's in its binary representation.
  
//Approach 1: Using bitManipulation
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    bool isSet(int &num, int bit){
        return  num & (1<<bit);
    }
    void setBit(int &num, int bit){
         num = num | (1<<bit);
    }
    void unsetBit(int &num, int bit){
         num = num & ~(1<<bit);
    }

    int minimizeXor(int num1, int num2) {
        int targetbitcount = __builtin_popcount(num2);

        int currbitcount = __builtin_popcount(num1);
        int x = num1;
        int bit = 0; //bitposition

        if(currbitcount > targetbitcount){
            while(currbitcount > targetbitcount){
                if(isSet(x,bit)){
                    unsetBit(x,bit);
                    currbitcount--;
                }
                bit++;
            }
        }
        if(currbitcount < targetbitcount){
            while(currbitcount < targetbitcount){
                if(!isSet(x,bit)){
                    setBit(x,bit);
                    currbitcount++;
                }
                bit++;
            }
        }

        return x;
    }
};

//T.C : O(logn)
//S.C : O(1)

class Solution {
public:
    bool isSet(int &num, int bit){
        return  num & (1<<bit);
    }

    bool unSet(int &num, int bit){
        return  !(num & (1<<bit));
    }
    void setBit(int &num, int bit){
         num = num | (1<<bit);
    }
    void unsetBit(int &num, int bit){
         num = num & ~(1<<bit);
    }

    int minimizeXor(int num1, int num2) {
        int targetbitcount = __builtin_popcount(num2);

        int x = 0;
        for(int bit = 31; bit >= 0 && targetbitcount >0; bit--){
            if(isSet(num1,bit)){
                x = x | (1 << bit);
                targetbitcount--;
            }
        }
        for(int bit = 0; bit < 32 && targetbitcount > 0 ; bit++){
            if(unSet(num1,bit)){
                x = x  | (1 << bit);
                targetbitcount--;
            }
        }
        return x;
    }
};
