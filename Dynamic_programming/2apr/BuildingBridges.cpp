#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class pairs{
    public:
     int north;
     int south;
     pairs(int north,int south){
         this->north=north;
         this->south=south;
     }
     bool operator<(const pairs &p1)const{
            return this->north<p1.north;
    }  
};
int LIS(vector<pairs> &vec){
    multiset<int> dp;
    for(int i=0;i<vec.size();i++){
        int s=vec[i].south;
        auto it=dp.upper_bound(s);
        if(it==dp.end()){
            dp.insert(s);
        }
        else{
            dp.erase(it);
            dp.insert(s);
        }
    }
    return dp.size();
}
int main(){
    int n;
    cin>>n;
    vector<int> north(n); 
    vector<int> south(n);
    for(int i=0;i<n;i++){
        cin>>north[i];
    }
    for(int i=0;i<n;i++){
        cin>>south[i];
    }
    vector<pairs> vec;
    for(int i=0;i<north.size();i++){
        vec.push_back(pairs(north[i],south[i]));
    }
    sort(vec.begin(),vec.end());
    cout<<LIS(vec);
    return 0;
}