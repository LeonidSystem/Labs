//3
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

#define FN 25        

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int dig;

vector <int> vc;
queue <int>qt;
stack <int> st;

int main() {
    for (int i=0; i<FN; i++)  {
            fin>>dig;
            if (!(dig%3))
                qt.push(dig);
            else if (dig%3==1)
                st.push(dig);
            else
                vc.push_back(dig);
        };
    
    while (!(qt.empty())) {
        fout<<qt.front()<<" ";
        qt.pop();
    };
    
    fout<<endl;
    
    while(!(st.empty())) {
        fout<<st.top()<<" ";
        st.pop();
    };
    
    fout<<endl;
    
    int j=vc.size()-1;
    int i=0;
    while (j>=vc.size()/2) {
        fout<<vc[i]<<" "<<vc[j]<<" ";
        i++;
        j--;
    };
}
