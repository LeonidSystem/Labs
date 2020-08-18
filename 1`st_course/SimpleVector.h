#include <iostream>
long long N=100;

template <typename T>
class SimpleVector {
    private:
        T *arr = (T*)malloc(sizeof(T)*N);
        int end_vector = 0;          //указывает на следующий элемент после последнего
    public:
        void push_back(T value) {
            if (end_vector<N) {
                arr[end_vector] = value;
                end_vector++;
            }
            else {
                N*=2;
                arr = (T*)realloc(arr, sizeof(T)*N);
                arr[end_vector] = value;
                end_vector++;
            };
        };

        int find(T value) {
            for (long long i = 0; i<end_vector; i++)
                if (arr[i] == value)
                    return i;
            return -1;
        };

        void Remove(T value) {
            int j = -1;
            for (long long i = 0; i<end_vector; i++)
                if (arr[i]==value) {
                    j = i;
                    break;
                };
            if (j!=-1) {
                for (int i = j+1; i<end_vector; i++)
                    arr[i-1] = arr[i];
                end_vector--;
            };
        };

        bool insert_after(T x, T y) {
            int j = -1;
            bool flag = false;
            for (long long i = 0; i<end_vector; i++)
                if (arr[i]==x) {
                    j = i;
                    break;
                    flag = true;
                };
            if (j!=-1) {
                if (end_vector>=N)
                   arr = (T*)realloc(arr, sizeof(T)*N);
                for (long long i = end_vector; i>j; i--)
                   arr[i+1] = arr[i];
                arr[j+1] = y;
            };

            return flag;
        };

        T operator[] (int index) {
            return arr[index];
        };

        int spvsize() {
            return end_vector;
        };
        
        bool operator< (SimpleVector sp2) {
            for (int i=0; i<std::min(end_vector, sp2.spvsize()); i++) {
                if (arr[i] < sp2.arr[i]) 
                    return true;
                else if (arr[i] > sp2.arr[i])
                    return false;
            };
        
            if (end_vector < sp2.spvsize())
                return true;

            return false;
        };

        bool operator<= (SimpleVector sp2) {
            for (int i=0; i<std::min(end_vector, sp2.spvsize()); i++)
                if (arr[i] > sp2.arr[i])
                    return false;

            if (end_vector <= sp2.spvsize())
                return true;

            return false;
        };

        bool operator> (SimpleVector sp2) {
            for (int i=0; i<std::min(end_vector, sp2.spvsize()); i++)
                if (arr[i] > sp2.arr[i])
                   return true;
                else if (arr[i]<sp2.arr[i])
                   return false;

            if (end_vector > sp2.spvsize())
                return true;

            return false;
        };

        bool operator>= (SimpleVector sp2) {
            for (int i=0; i<std::min(end_vector, sp2.spvsize()); i++)
                if (arr[i] < sp2.arr[i])
                   return false;

            if (end_vector >= sp2.spvsize())
                return true;

            return false;
        };

        bool operator== (SimpleVector sp2) {
            if (end_vector!=sp2.spvsize())
                return false;

            for (int i=0; i<end_vector; i++)
                if (arr[i] != sp2.arr[i])
                   return false;

            return true;
        };

        bool operator!= (SimpleVector sp2) {
            if (end_vector==sp2.spvsize())
                return false;

            for (int i=0; i<end_vector; i++)
                if (arr[i] == sp2.arr[i])
                   return false;

            return true;
        };

        //~SimpleVector() {
        //    free(arr);
        //};
};

static bool Comparator(SimpleVector <int> sp1, SimpleVector <int> sp2) {
        for (int i=0; i<std::min(sp1.spvsize(), sp2.spvsize()); i++) {
                if (sp1[i] < sp2[i]) 
                    return true;
                else if (sp1[i] > sp2[i])
                    return false;
            };
        
            if (sp1.spvsize() < sp2.spvsize())
                return true;

            return false;
 };
