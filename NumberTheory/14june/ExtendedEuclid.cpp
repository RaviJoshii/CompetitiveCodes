// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
// 10104 - Euclid Problem-   Extended
#include<bits/stdc++.h>
using namespace std;
class pairs{
    public:
    int x;
    int y;
    int gcd;
    pairs(int x,int y,int gcd){
        this->x=x;
        this->y=y;
        this->gcd=gcd;
    }
    pairs(){

    }

};
pairs extended_Euclid(int a,int b){
    if(b==0){
        pairs it(1,0,a);
        return it;
    }
    pairs dash=extended_Euclid(b, a%b);
    int newx=dash.y;
    int newy=dash.x-ceil(a/b)*dash.y;
    return pairs(newx,newy,dash.gcd);
    
}
int main(){
    long long A, B;
    while (scanf("%lld %lld", &A, &B) == 2) {
        pairs ans=extended_Euclid(A, B);         
        cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;
    }
    return 0;
}