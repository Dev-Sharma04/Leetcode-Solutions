//Question : Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.
// Implement the ProductOfNumbers class:
// ProductOfNumbers() Initializes the object with an empty stream.
// void add(int num) Appends the integer num to the stream.
// int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
// The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.


//Approach : Using vector
//T.C : O(k)
//S.C : O(n)

class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {

    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int32_t ans = 1;
        int idx = nums.size()-1;
        while(k--){
            ans*=nums[idx--];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
