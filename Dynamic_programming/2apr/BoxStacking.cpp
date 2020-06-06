// https://www.geeksforgeeks.org/box-stacking-problem-dp-22/
// Box Stacking Problem | DP-22
#include<bits/stdc++.h>
using namespace std;
class box{
    public:
    int l,b,h;
    box(int l,int b,int h){
        this->l=l;
        this->b=b;
        this->h=h;
    }
};
class compartor{
    public:
    int operator()(const box &p1,const box &p2){
        return (p1.l*p1.b)>(p2.l*p2.b);
    }
};
int LIS(vector<box> &vec){
    int ans=0;
    vector<int> dp(vec.size());
    dp[0]=vec[0].h;
    for(int i=1;i<vec.size();i++){
        int maxPH=0;//maximum previous height
        int currl=vec[i].l;
        int currb=vec[i].b;
        int currh=vec[i].h;
        for(int j=0;j<i;j++){
            int prevl=vec[j].l;
            int prevb=vec[j].b;
            int prevh=vec[j].h;
            if(prevb>currb&&prevl>currl){
                maxPH=max(maxPH,dp[j]);
            }
        }
        dp[i]=currh+maxPH;
        ans=max(ans,dp[i]);
    }
    return ans;
}
int maxHeight(int height[],int width[],int length[],int n)
{   vector<box> vec;
    for(int i=0;i<n;i++){
        //original box;
        vec.push_back(box(max(length[i],width[i]),min(length[i],width[i]),height[i]));
        //first rotaion of box
        vec.push_back(box(max(length[i],height[i]),min(height[i],length[i]),width[i]));
        //second rotaion
        vec.push_back(box(max(width[i],height[i]),min(height[i],width[i]),length[i]));
    }
    sort(vec.begin(),vec.end(),compartor());
    return LIS(vec);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int L[n+1],W[n+1],H[n+1];
        for(int i=0;i<n;i++){
            cin>>H[i]>>W[i]>>L[i];
        }
        cout<<maxHeight(L,W,H,n)<<endl;
    }
    
    return 0;
}