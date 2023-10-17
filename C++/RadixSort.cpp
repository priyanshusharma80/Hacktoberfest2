#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int>& v,int expo){
    vector<int> output(v.size(),0);
    vector<int> count(10,0);

    // storing occurences of digits;
    for(int i=0;i<v.size();i++) count[(v[i]/expo)%10]++;

    // STEP-2;
    for(int i=1;i<count.size();i++) count[i]+=count[i-1];

    for(int i=v.size()-1;i>=0;i--){
        output[count[(v[i]/expo)%10]-1] = v[i];
        count[(v[i]/expo)%10]--;
    }

    for(int i=0;i<v.size();i++){
        v[i] = output[i];
    }
}

void radixSort(vector<int>& v){
    int m = v[0];
    for(auto it:v) m = max(m,it);

    for(int expo=1;m/expo>0;expo*=10){
        countSort(v,expo);
    }
}

int main() {
    vector<int> v = {543, 986, 217, 765, 329};
    radixSort(v);

    for(auto it:v) cout<<it<<" ";
    return 0;
}
