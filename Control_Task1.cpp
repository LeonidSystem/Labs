#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

#define N 5

struct student {
    string fname, sname;
    int source[3];
};

bool Comp (struct student st1, struct student st2) {
    if (st1.source[0]+st1.source[1]+st2.source[2]<st2.source[0]+st2.source[0]+st2.source[0])
        return true;
    else if (st1.source[0]+st1.source[1]+st2.source[2]==st2.source[0]+st2.source[0]+st2.source[0] && max(st1.source[0], max(st1.source[1], st1.source[2]))<max(st2.source[0], max(st2.source[1], st2.source[2])))
        return true;
    else if (max(st1.source[0], max(st1.source[1], st1.source[2]))==max(st2.source[0], max(st2.source[1], st2.source[2])) &&  min(st1.source[0], min(st1.source[1], st1.source[2]))<=min(st2.source[0], min(st2.source[1], st2.source[2])))
        return true;
    return false;
};

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    student *st = new struct student [N];
    for (int i=0; i<N; i++) 
        fin>>st[i].fname>>st[i].sname>>st[i].source[0]>>st[i].source[1]>>st[i].source[2];
        
    sort(st, st+N, Comp);    
}
