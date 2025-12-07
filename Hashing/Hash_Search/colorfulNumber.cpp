#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//My initial thought was to first convert it into strings and than generate all contigous subsequences and than find the product of each and store it in hashmap and do checks 
//Than i realise its easy to use vector and find the product 
//This solution i coded using vectors 


//For a Given Number A , Find its a colorful number or not 
//NUmber can be divided into different contigous sub sequences parts 
//If product of all subsequences is different than its a colorful number 
int colorful(int n) {
    //First lets put all digits in a vector 
    vector<int> digits;
    while(n){
        digits.push_back(n%10);
        n = n/10;
    }
    unordered_set<int> st;
    //Now Traverse over the digits 
    for(int i = 0;i < digits.size();i++){
        int curr = 1;
        for(int j = i;j < digits.size();j++){
            curr = curr*digits[j];
            if(st.find(curr) != st.end()){
                //it exisit 
                return 0;
            }else{
                st.insert(curr);
            }
        }
    }
    //if all are uniques 
    return 1;
}

int main(){
    int n;cin>>n;
    cout<<colorful(n)<<endl;
    return 0;
}