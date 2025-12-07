#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<unordered_set>
// Given a string A, find the length of the longest substring without repeating characters.

int lengthOfLongestSubstring(string str) {
    unordered_set<char> data;
    int s = 0;
    int res = 0;
    for(int i = 0;i < str.size();i++){
        if(data.count(str[i])){
            //present than move the start pointer till the point you avoid that character 
            while(str[s] != str[i]){
                //Remove the elements from the old window 
                data.erase(str[s]);
                s += 1;
            }
            //Now here we are at the index where s is at identical idx 
            s += 1;
        }else{
            data.insert(str[i]);
        }
        //see the result 
        // cout<<"Res "<<res<<" "<<s<<endl;
        res = max(res,i-s+1);
    }
    return res;
}
//Simplifying the duplicate removal logic 
int lengthOfLongestSubstring(string str) {
    unordered_set<char> data;
    int s = 0, res = 0;

    for (int i = 0; i < str.size(); i++) {
        while (data.count(str[i])) {
            data.erase(str[s]);
            s++;
        }
        data.insert(str[i]);
        res = max(res, i - s + 1);
    }
    return res;
}

//Faster Approach for interview , Used an index map to store index 
//Optimal Approach 
int lengthOfLongestSubstring_eff(string s){
    vector<int> last(256,-1); // Last seen index of each character 
    int s_ptr = 0 ; //Start of the current window 
    int res = 0; //Maximum length found 
    for(int i = 0;i < s.size();i++){
        if(last[s[i]] >= s_ptr){
            s_ptr = last[s[i]] + 1;
        }
        last[s[i]] = i;
        res = max(res,i - s_ptr + 1);
    }
    return res;
}


int main(){
    string str;cin>>str;
    cout<<lengthOfLongestSubstring(str)<<endl;
    return 0;
}