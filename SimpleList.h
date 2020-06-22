//Implementations of Queue and SimpleList are similar
template <typename T>
class SimpleList {
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
            int j=0;
            for (node *i = first; i!=nullptr; j++, i = i->next)
                if (i->val == value)
                    return j;
            return -1;        
        };
        
        void Remove(T value) {
            for (node *i = first; i!=nullptr; i = i->next)
                if (i->next->val == value) {
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
        
        ~SimpleList() {
            node *tmp, *i = first;
            while (i!=nullptr) {
                tmp = i;
                i = i->next;
                delete tmp;
            };
        };
};
