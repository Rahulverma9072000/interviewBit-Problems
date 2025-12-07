#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
int solve(vector<int> &A) {
    //Find the First repeating element 
    //Find the element that occurs more than once and whose index of fist occurence is smallest 
    int res = INT_MAX; 
    // int res = A.size() + 1 ; // instead of INT_MAX we can also assign (n+1) since it will not go above this 
    unordered_map<int,int> data;
    for(int i = 0;i < A.size();i++){
        if(data.find(A[i]) != data.end()){
            //present 
            res = min(res,data[A[i]]);
        }else{
            data[A[i]] = i;
        }
    }
    return (res==INT_MAX ? -1 : A[res]);
}
//Better solution is like in above method we are storing res = INT_MAX and at last we are doing a conditional check and everytime we find the duplicates there also we are doing which we can avoid IF WE TRAVERSE RIGHT TO LEFT 
//Why ? Because we want element repeating and whose index of first occurence is smallest 
int solve_1(vector<int> &arr){
    int res = -1;
    unordered_map<int,int> data;
    for(int i = arr.size()-1;i >= 0;i--){
        if(data.find(arr[i]) != data.end()){
            //present 
            res = i;
        }else{
            data[arr[i]] = i;
        }
    }
    return (res == -1 ? -1 : arr[res]);
}
int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr)<<endl;
    cout<<solve_1(arr)<<endl;
    return 0;
}