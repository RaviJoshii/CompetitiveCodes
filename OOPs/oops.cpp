#include<iostream>

using namespace std;

class parent {
    public:
        const double pi = 3.14;
        int d = 10;
        int d1 = 100;

        void fun1() {
            cout << "p's f1" << endl;
        }

        virtual void fun2() {
            cout << "p's f2" << endl;
        }

        void fun3(){
            cout << "p's f3" << endl;
        }

        parent(){
            
        }
};

class child: public parent {
    public:
        int d = 20;
        int d2 = 200;

        void fun4() {
            cout << "c's f4" << endl;
        }

        void fun2() {
            cout << "c's f2" << endl;
        }

        void fun3(){
            cout << "c's f3" << endl;
        }
};

class person
{
    public:
        int age;
        string name;
};

void swap1(person& one, person& two)
{
    person temp = one;
    one = two;
    two = temp;

}

void fun1(){
    static int i = 100;
    int j = 200;

    i++;
    j++;

    cout << i << " " << j << endl;
}

void fun2(){
    static int i = 10;
    int j = 20;

    i++;
    j++;
    
    cout << i << " " << j << endl;
}


int main(int argc, char** argv)
{
    fun1();
    fun2();

    fun1();
    fun2();
    
    // parent* p = new child();

    // cout << p->d << " " << p->d1 << endl;
    // p->fun1();
    // p->fun2();
    // p->fun3();

    // child co;
    // cout << co.d << " " << co.d1 << " " << co.d2 << endl;
    // co.fun1();
    // co.fun2();
    // co.fun3();
    // co.fun4();

    // parent po = co;

    // cout << po.d1 << " " << po.d << endl;
    // po.fun1();
    // po.fun2();
    // po.fun3();

    // dummy d;
    // cout << sizeof(dummy) << endl;

    // person p1;
    // person p2;

    // p1.age = 10;
    // p1.name = "A";

    // p2.age = 20;
    // p2.name = "B";

    // cout << p1.age << " " << p1.name << endl;
    // cout << p2.age << " " << p2.name << endl;
    // swap1(p1, p2);
    // cout << p1.age << " " << p1.name << endl;
    // cout << p2.age << " " << p2.name << endl;
}