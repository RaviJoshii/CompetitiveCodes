#include<iostream>

using namespace std;

// class abs {
//     public:
//         virtual void fun() = 0;
//         void fun2(){
//             cout << "abs.fun2" << endl;
//         }
// };

// class cabs: public abs {
//     public:
//         // void fun(){
//         //     cout << "cabs.fun" << endl;
//         // }
// };

class a {
    public:
    a(int i){

    }
};

class b : public a {
    public:
    b(int i): a(i){

    }
};

int main(int argc, char** argv){
    // abs a; 
    cabs c;
    // abs a;   
}
