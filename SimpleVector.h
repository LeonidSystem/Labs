//1, 2, 3
long long N=100;

template <typename T>
class SimpleVector {
    private:
        T *arr = (T*)malloc(sizeof(T)*N);
        int end_vector = -1;
    public:
        void push_back(T value) {
            if (end_vector<N) {
                arr[end_vector+1] = value;
                end_vector++;
            }
            else {
                N*=2;
                arr = (T*)realloc(arr, sizeof(T)*N);
                arr[end_vector+1] = value;
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
        
        ~SimpleVector() {
            free(arr);
        };
};
