// finding the closest value (or) same value of given value.

#include<bits/stdc++.h>
using namespace std;

int closestVal(int *arr,int size,int target){

    int mid = (size/2)-1;
    if(arr[mid] == target) return target;


    int i = 0, j = size-1, cVal = arr[mid], diffVal = abs(target-arr[mid]);
    while(i<j){
        if(target == arr[mid]) return arr[mid];

        if(target > arr[mid]){
            i = mid+1;
            mid = i+(j-i)/2;
            if(diffVal > abs(target-arr[mid])){
                diffVal = abs(target - arr[mid]);
                cVal = arr[mid];
            }
        }else{
            j = mid;
            mid = i+(j-i)/2;
            if(diffVal > abs(target-arr[mid])){
                diffVal = abs(target - arr[mid]);
                cVal = arr[mid];
            }
        }
    }

    return cVal;
}

int main(){

    int size,arr[] = {1,2,3,5,6,6,6,9,11,12,13};
    size = sizeof(arr)/sizeof(arr[0]);

    cout<<closestVal(arr,size,-2);

    return 0;
}
