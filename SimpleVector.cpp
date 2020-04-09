//1, 2, 3
#include <iostream>
using namespace std;

template <typename T>
class SimpleVector {
    private:
        struct node {
            T val;
            struct node *next = nullptr;
            node(T value) : val(value) {};
        } *first = nullptr, *last = nullptr;
    public:
        void push_back(T value) {
            node *tmp = new struct node(value);
            if (last!=nullptr) 
                last->next = tmp;
            last = tmp;
            if (first==nullptr)
                first = tmp;
        };
        
        int find(T value) {
            for (node *i = first, int j=0; i!=nullptr; j++, i = i->next)
                if (i->val == value)
                    return j;
            return -1;        
        };
        
        void Remove(T value) {
            for (node *i = first; i!=nullptr; i = i->next)
                if (i->next->val == val) {
                    node *tmp = i->next;
                    i->next = i->next->next;
                    delete tmp;
                    break;
                };
        };
        
        bool insert_after(T x, T y) {
            for (node *i = first; i!=nullptr; i = i->next)
                if (i->value==y) {
                    node *tmp = new struct node(x);
                    tmp->next = i->next;
                    i->next = tmp;
                    return true;
                };
            return false;
        };
        
        T operator[] (int index) {
            node *i;
            int j;
            for ( i = first, j=0; j<index; j++, i = i->next)
                ;
            return i->val;
        };
        
        ~SimpleVector() {
            node *tmp, *i = first;
            while (i!=nullptr) {
                tmp = i;
                i = i->next;
                delete tmp;
            };
        };
};

int main() {
    SimpleVector <int> sv;
    sv.push_back(5);
    sv.push_back(6);
    cout<<sv[0]<<" "<<sv[1];
}
