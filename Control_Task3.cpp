#include <iostream>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

#define N 5

queue <string> q, qminmax, qrest; 

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    string str;
    
    fin>>str;
    q.push(str);
    int shsize = str.size();
    int lsize = str.size();
    
    for (int i=1; i<N; i++) {
        fin>>str;
        q.push(str);
        if (str.size()>lsize())
            lsize = str.size();
        if (str.size()<shsize)
            shsize = str.size();
    };
    
    while(!(q.empty())) {
        if (q.front()>shsize && q.front()<lsize)
            qminmax.push(q.front());
        else
            qrest.push(q.front());
        q.pop();
    };
    
    while(!(qminmax.empty())) {
        fout<<qminmax.front();
        qminmax.pop();
    };
    
     while(!(qrest.empty())) {
        fout<<qrest.front();
        qrest.pop();
    };
}
