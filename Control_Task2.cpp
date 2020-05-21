#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

#define N 5

class Socks {
    private:
        struct socks {
            string color, maker;
            int size;
            bool warm;          //шерстяные(1) или обычные(0)
        };
        socks *arr = new struct socks [N];
        end_socks = 0;
    public:
        static counter1, counter2;  //счётчики для шерстяных и обычных
        Socks() : color(0), maker(0), size(0), warm(0) {};
        
        int SocksSize() {
            return end_socks;
        }
        
        void SocksInfo(int index) {
            fout<<arr[i].color<<" "<<arr[i].maker<<" "<<arr[i].size<<" "<<arr[i].warm<<endl;
        };
        
        void SocksPush(string clr, string mkr, int sz, bool wrm) {
            arr[end_socks].color = clr;
            arr[end_socks].maker = mkr;
            arr[end_socks].size = sz;
            arr[end_socks].warm = wrm;
            end_socks++;
        };
        
        bool operator== (class Socks sc1) {
            if (end_vector!=sc1.SocksSize())
                return false;
            for (int i=0; i<end_vector; i++)
                if (maker!=sc1.maker)
                    return false;
                else if (warm!=sc1.warm)
                    return false;
                else if (size!=sc1.size)
                    return false;
            return true;
        };
        
        bool operator>= (class Socks sc1) {
            if (end_vector<sc1.SocksSize())
                return false;
            for (int i=0; i<end_vector; i++)
                if (maker<sc1.maker)
                    return false;
                else if (warm<sc1.warm)
                    return false;
                else if (size<sc1.size)
                    return false;
                return true;
        };
};

int main() {
    Socks sks;
    string clr, mkr;
    int sz;
    bool wrm;
    
    for (int i=0; i<N; i++) {
        fin>>clr>>mkr>>sz>>wrm;
        sks.SocksPush(clr, mkr, sz, wrm);
    };
    
    sks.SocksInfo(0);
}
