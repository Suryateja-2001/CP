/*
    You have 'N' sticks with different sizes.You cut the sticks into 'X' sticks, such that you get x sticks with max size of Equal height.
    We have to find max height possible to cut into  x sticks.
    (Note: height of each stick should be only integer)

    N -> Given No.of Sticks.
    X -> bundel of sticks after cutting 'N' sticks
*/
#include<iostream>
#include<algorithm>
using namespace std;

bool maxHeight(int *arr, int Possible_height, int totalSticks, int cuttingSticks){
    int sticks = 0;

    for(int i=0;i<totalSticks;i++){
        sticks += arr[i]/Possible_height;
    }

    if(sticks >= cuttingSticks) return true;

    return false;
}

int maxHeight_Stick(int *arr,int totalSticks, int cuttingSticks){

    int start = 0, end = arr[totalSticks-1], height = 0;
    int mid = start + (end - start)/2;

    while(start < end){
        if(maxHeight(arr,mid,totalSticks,cuttingSticks)){
            height = mid;
            start = mid+1;
            mid = start + (end - start)/2;
        }else{
            end = mid;
            mid = start + (end - start)/2;
        }
    }

    return height;
}

int main(){

    int N = 3, X = 4;
    int arr[N] = {10,15,8};

    sort(arr, arr+N);

    cout<<"The maximum height of stick is "<<maxHeight_Stick(arr, N, X);

    return 0;
}