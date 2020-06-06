// https://leetcode.com/problems/maximum-frequency-stack/
// Maximum Frequency Stack
#include <bits/stdc++.h>
using namespace std;
class FreqStack {
public:
    unordered_map<int,list<int> > umapStack;
    unordered_map<int, int> umapFreq;
    int maxFreq;
    
    FreqStack() {
        
    }
    
    void push(int x) {
        umapFreq[x]++;
        int freq=umapFreq[x];
        umapStack[freq].push_back(x);
        maxFreq=max(freq,maxFreq);
    }
    
    int pop() {
        
        int ans=umapStack[maxFreq].back();
        umapFreq[ans]--;
        umapStack[maxFreq].pop_back();
        if(umapStack[maxFreq].size()==0){
            umapStack.erase(maxFreq);
                maxFreq--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */