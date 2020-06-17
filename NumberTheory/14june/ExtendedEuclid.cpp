// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
// 10104 - Euclid Problem-   Extended
#include<iostream>
#include<cmath>

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
pairs Euclids(int a,int b){
    if(b==0){
        pairs it(1,0,a);
        return it;
    }
    pairs dash=Euclids(b, a%b);
    int newx=dash.y;
    int newy=dash.x-ceil(a/b)*dash.y;
    return pairs(newx,newy,dash.gcd);
    
}
int main(){
    int a;
    int b;
    cin>>a>>b;
    pairs ans=Euclids(a,b);
    cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;
    return 0;
}