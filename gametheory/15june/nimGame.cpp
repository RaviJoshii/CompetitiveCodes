// https://www.geeksforgeeks.org/combinatorial-game-theory-set-2-game-nim/
// Combinatorial Game Theory | Set 2 (Game of Nim)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a^b^c==0){
        cout<<"B wins"<<endl;
    }else{
        cout<<"A wins"<<endl;
    }
    return 0;
}