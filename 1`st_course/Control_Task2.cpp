#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

#define N 5

ifstream fin("input.txt");
ofstream fout("output.txt");

class Socks {
    private:
        struct socks {
            string color, maker;
            int size;
            bool warm;          //шерстяные(1) или обычные(0)
        };
        socks *arr = new struct socks [N];
        int end_socks = 0;
    public:
        static int counter1, counter2;  //счётчики для шерстяных и обычных
        
        struct socks operator[] (int index) {
            return arr[index];
        };
        
        Socks() {};
        
        int SocksSize() {
            return end_socks;
        };
        
        void SocksInfo(int i) {
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
            if (end_socks!=sc1.SocksSize())
                return false;
            for (int i=0; i<end_socks; i++)
                if (arr[i].maker!=sc1[i].maker)
                    return false;
                else if (arr[i].warm!=sc1[i].warm)
                    return false;
                else if (arr[i].size!=sc1[i].size)
                    return false;
            return true;
        };
        
        bool operator>= (class Socks sc1) {
            if (end_socks<sc1.SocksSize())
                return false;
            for (int i=0; i<end_socks; i++)
                if (arr[i].maker<sc1[i].maker)
                    return false;
                else if (arr[i].warm<sc1[i].warm)
                    return false;
                else if (arr[i].size<sc1[i].size)
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
