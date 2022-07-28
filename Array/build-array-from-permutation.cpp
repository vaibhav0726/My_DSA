#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// The idea is to store two numbers (nums[i] and nums[nums[i]]) at the same location.

// The important point to be noted is that all numbers in the array are less than size of the array.

// Example - Lets say we have two numbers in the array a = 3 , b = 2 and the size of the array is n = 5

// We can store both 3 and 2 in a as follows:-

// a = a + b * n

// To get initial value of a we do a%n
// To get the value of b we do a/n

// a = a + b * n = 3 + 2*5 = 13

// a % n = 13 % 5 = 3

// a / n = 13 / 5 = 2



vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]+(n*(nums[nums[i]]%n));
        }
        for(int i=0;i<n;i++){
            nums[i]/=n;
        }
        return nums;
    }

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

int main(){
     vector<int> v = {0,2,1,5,3,4};
    v = buildArray(v);
    printVector(v);
}