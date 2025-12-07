#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>

//Basic Approach will be to run 2 loops and count the odd_cnt 
int solve_basic(vector<int> &arr,int b){
    int res = 0;
    for(int i = 0;i < arr.size();i++){
        int odd_cnt = 0;
        for(int j = i;j < arr.size();j++){
            if(arr[j] & 1){
                odd_cnt += 1;
            }
            if(odd_cnt == b){
                res += 1;
            }
        }
    }
    return res;
}
//Idea is to use Hashmaps to track the frequency of prefix subarrays with a given count of odd numbers 
int solve(vector<int> &arr, int b) {
    //Subarray with B odd numbers 
    //Return Total number of subarray with exactly b odd numbers 
    int res = 0;
    unordered_map<int,int> data;
    int odd_cnt = 0;
    data[odd_cnt] = 1;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] &1) odd_cnt += 1;
        if(data.find(odd_cnt - b) != data.end()){
            res += data[odd_cnt - b];
        }
        data[odd_cnt] += 1;
    }
    return res;
}

//Optimal Approach : Using 2 pointers 
//Idea 


//TO Find the subarray with atMost x odd elements 
int atMostX(vector<int> &arr,int x){
    //Edge Case 
    if (x < 0) return 0;
    int n = arr.size();
    int odd = 0;
    int ans = 0;
    int start = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] % 2){
            odd +=1;
        }
        //If count of odd elements is greater than x 
        //then remove elements from the start 
        while(odd > x){
            if(arr[start] %2){
                odd --;
            }
            start += 1;
        }
        //Add the number of subarray with atMost X 
        //Odd elements ending at the current index
        ans +=  (i - start + 1);
    }
    return ans;
}



int countSubArrays(vector<int> &arr,int k){
    int x = atMostX(arr,k);
    int y = atMostX(arr,k-1);
    cout<<x<<" "<<y<<endl;
    return x - y;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    int b;cin>>b;
    cout<<countSubArrays(arr,b)<<endl;
    return 0;
}