/*
    Farmer Jhon has a barn with 'N' stalls with 'C' No.of cows.
    His cows don't like this  barn layout and become aggressive towards each other once put into a stall. 
    To prevent the cows from hurting each other, Farmer john wants to assign the cows to the stalls such that
    the minimum distance between ant two of them is as large as possible. What is the largest minimum distance? 
    
    C -> No.of Cows
    N -> No.of stalls in the barn.
    arr[N] -> where arr[i] tells the postion of stall.
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool possibleDistance(int mid, int *arr, int C, int N){
    int cows = 1, pos = arr[0];

    for(int i=0;i<N;i++){
        if(arr[i] - pos >= mid){
            pos = arr[i];
            cows++;

            if(cows == C) return true;
        }
    }

    return false;
}

int largeMinimum_distance(int *arr, int C, int N){
    int start = 0,end = arr[N-1], mid = (start+end)/2, maxDistance = 0;
    
    while (start < end){
        if(possibleDistance(mid,arr,C,N)){
            maxDistance = mid;
            start = mid+1;
        }else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    
    return maxDistance;
}

int main(){
    int C = 3,N = 5;
    int arr[N]={1, 2, 8, 4, 9};

    sort(arr,arr+N);
    cout<<"The largest minimum possible distance is "<<largeMinimum_distance(arr,C,N);

    return 0;
}