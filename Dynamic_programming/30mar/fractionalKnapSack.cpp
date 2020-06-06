// https://www.geeksforgeeks.org/fractional-knapsack-problem/
// Fractional Knapsack Problem
#include<bits/stdc++.h>
using namespace std;
class items{
    public:
        int price;
        int weight;
        double pwr;
        items(int p, int w){
            price=p;
            weight=w;
            pwr=(p*(1.0))/w;
        }
};
class mycomparator{
    public:
    int operator()(const items i1, const items i2){
        return i1.pwr<i2.pwr;
    }
};
int fractionalKnapsack(vector<items> &item,int capacity){
    double maxprofit=0.0;
    int currCapacity=0;
    for(int i=item.size()-1;i>=0;i--){
        if(currCapacity+item[i].weight>capacity){
            maxprofit+=capacity*(item[i].pwr);
            capacity=0;
            break;
        }
        else{
            maxprofit+=item[i].price;
            capacity=capacity-item[i].weight;
            currCapacity+=item[i].weight;
        }
    }

    return maxprofit;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        vector<items> vec;
        int n,C;
        cin>>n>>C;
        for(int y=0;y<n;y++){
            int p,w;
            cin>>p>>w;
            vec.push_back(items(p,w));
        }
        sort(vec.begin(),vec.end(),mycomparator()); 
        
        cout<<fractionalKnapsack(vec,C)<<endl;
    }
	return 0;
    
}