template <typename T>
class Stack {
    private:
        struct node {
            T val;
            struct node *next = nullptr;
            node(T value) : val(value) {};
        } *first = nullptr;
    public:
        bool empty_stack() {
            return first==nullptr;
        };

        T show_top() {
            if (!empty_stack())
                return first->val;
        };

        void push_back(T value) {
            node *tmp = new struct node(value);
            if (first==nullptr)
                first = tmp;
            else {
                tmp->next = first;
                first = tmp;
            };
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

        ~Stack() {
            node *tmp, *i = first;
            while (i!=nullptr) {
                tmp = i;
                i = i->next;
                delete tmp;
            };
        };
};
