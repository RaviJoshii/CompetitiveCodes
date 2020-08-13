#include<iostream>

using namespace std;


class list {
    public:
        class node {
            public:
                int data;
                node* next;

                node(int data, node* next){
                    this->data = data;
                    this->next = next;
                }
        };

        class iterator {
            private:
                node* spot;
            public:
                iterator(node* n){
                    spot = n;
                }

                iterator(iterator& i){
                    this->spot = i.spot;
                }

                iterator& operator=(const iterator& i){
                    this->spot = i.spot;
                    return *this;
                }

                bool operator!=(const iterator& o) const{
                    return this->spot != o.spot;
                }

                void operator++() {
                    this->spot = this->spot->next;
                }

                int operator*() const {
                    return this->spot->data;
                }
        };

        node* head = NULL;

        void add(int val){
            if(head == NULL){
                head = new node(val, NULL);
            } else {
                node* n = new node(val, head);
                head = n;
            }
        }

        iterator begin(){
            return iterator(head);
        }

        iterator end(){
            return iterator(NULL);
        }
};

int main(int argc, char** argv){
    list l;
    l.add(50);
    l.add(40);
    l.add(30);
    l.add(20);
    l.add(10);

    auto itr = l.begin();
    while(itr != l.end()){
        cout << *itr << " ";
        itr.operator++();
    }
    cout << endl;
}


