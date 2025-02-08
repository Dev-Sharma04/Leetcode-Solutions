//Question : Design a number container system that can do the following:
// Insert or Replace a number at the given index in the system.
// Return the smallest index for the given number in the system.
// Implement the NumberContainers class:
// NumberContainers() Initializes the number container system.
// void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
// int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.

//Approach : Using hashmap and set 
//T.C : O(n)
//S.C : O(n)

class NumberContainers {
public:
    unordered_map<int,int> idx2Num; //idx->num
    unordered_map<int,set<int>> num2Idx; // num -> {idx..}
    NumberContainers() {
        //it is a constructor is case mai kch ni krna
        // idx2Num.clear();
        // num2Idx.clear();
    }
    
    void change(int index, int number) {
        if(idx2Num.count(index)){
            int num = idx2Num[index];
            num2Idx[num].erase(index);

            if(num2Idx[num].empty())num2Idx.erase(num);
            
        }
        idx2Num[index] = number;
        num2Idx[number].insert(index);
    }
    
    int find(int number) {
           if(num2Idx.count(number))return *num2Idx[number].begin();
        
        return -1;
    }
};

//Approach 2 : Using set and ppriority queue
//T.C : O(n)
//S.C : O(n)

class NumberContainers {
public:
    unordered_map<int,int> idx2Num; //idx->num
    unordered_map<int,priority_queue<int,vector<int>, greater<int>>> num2Idx; // num -> {idx..}
    NumberContainers() {
        //it is a constructor is case mai kch ni krna
        // idx2Num.clear();
        // num2Idx.clear();
    }
    
    void change(int index, int number) {
        
        idx2Num[index] = number;
        num2Idx[number].push(index);
    }
    
    int find(int number) {
        if(!num2Idx.count(number))return -1;

        auto &pq = num2Idx[number];
        while(!pq.empty()){
            int idx = pq.top();
            if(idx2Num[idx] == number)return idx;
            
            pq.pop();
        }
        return -1;
    }
};
