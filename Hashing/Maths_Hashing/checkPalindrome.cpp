#include<iostream>
using namespace std;
//Given String str consisting of lowercase characters 
//Check if the given strings can be rearranged to form a palindrome 
int solve(string str) {
    //String A consisit of lowercase characters 
    int data[26] = {0};
    for(int i = 0;i < str.size();i++){
        data[str[i] - 'a'] += 1;
    }
    //Now checks every occurence is even and 1 odd can be allowed 
    int number_of_odd_occ = 0;
    for(int i = 0;i < 26;i++){
        if(data[i] & 1){
            number_of_odd_occ += 1;
        }
    }
    if(number_of_odd_occ <= 1){
        return 1;
    }else{
        return 0;
    }
}
//This is the coolest approach using Bit Manipulation 
//instead of using array we can use int 
//If even times present than bit will become 0 and odd times it will be 1 
bool canFormPalindrome(const string &str) {
    int mask = 0;
    for(char c : str) {
        int bit = c - 'a';  
        mask ^= (1 << bit); // toggle bit
    }
    //If there is single bit present (n&(n-1) == 0)
    return (mask & (mask - 1)) == 0;
}

int main(){
    string str;cin>>str;
    cout<<solve(str)<<endl;
    return 0;
}