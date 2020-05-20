#include <iostream>
#include <algorithm>
#include <vector>
#include "SimpleVector.h"
#include <fstream>

#define FN 5        //размер SimpleVector

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int dig;

vector <SimpleVector <int>> vc;

int main() {
    for (int i=0; i<FN; i++) {
        SimpleVector <int> spvc;
        for (int j=0; j<FN; j++) {
            fin>>dig;
            spvc.push_back(dig);
        };
        vc.push_back(spvc);
    };
    
    sort(vc.begin(), vc.end());

    for (int i=0; i<FN; i++) {
        for (int j=0; j<FN; j++)
            fout<<vc[i][j]<<" ";
        fout<<endl;
    };
}
