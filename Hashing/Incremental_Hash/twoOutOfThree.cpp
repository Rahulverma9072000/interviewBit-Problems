#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<unordered_set>
#include<algorithm>
//Given 3 arrays can have duplicates element in array
//Return the sorted list of numbers that are present in atleast 2 out of three arrays 
vector<int> solve(vector<int> &A,vector<int> &B,vector<int> &C){
    //Resultant Map 
    map<int,int> data;
    unordered_set<int> curr;
    vector<int> res;
    for(int i = 0;i < A.size();i++){
        if(curr.find(A[i]) == curr.end()){
            //Total New Element 
            curr.insert(A[i]);
            data[A[i]] += 1;
        }
    }
    curr.clear();
    for(int i = 0;i < B.size();i++){
        if(curr.find(B[i]) == curr.end()){
            //Total New Element 
            curr.insert(B[i]);
            data[B[i]] += 1;
        }
    }
    curr.clear();
    for(int i = 0;i < C.size();i++){
        if(curr.find(C[i]) == curr.end()){
            //Total New Element 
            curr.insert(C[i]);
            data[C[i]] += 1;
        }
    }
    for (auto it = data.begin(); it != data.end(); ++it) {
        if(it->second >= 2){
            res.push_back(it->first);
        }
    }
    return res;
}
//Optimisation we can do for the above approach is to dont do repetitive task instead make function and do it 

//Smallest and Better Code for this
void addUnique(const vector<int> &arr, unordered_map<int,int> &freq) {
    unordered_set<int> seen(arr.begin(), arr.end()); // unique elements of this array
    for (int x : seen) freq[x]++;                   // increment count once per array
}

vector<int> solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    unordered_map<int,int> freq;
    addUnique(A, freq);
    addUnique(B, freq);
    addUnique(C, freq);

    vector<int> res;
    for (auto &p : freq) if (p.second >= 2) res.push_back(p.first);
    sort(res.begin(), res.end());
    return res;
}
int main(){

}