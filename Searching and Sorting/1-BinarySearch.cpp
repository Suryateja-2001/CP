// Binary Search

#include<iostream>

using namespace std;

int binarySearch(int *arr, int left, int right, int val){

    int mid = left + (right-left)/2;

    if(arr[mid] == val) return mid;

    if(val > arr[mid]){

        return binarySearch(arr, mid+1, right, val);

    }else if(val < arr[mid]){

        return binarySearch(arr, left, mid, val);

    }else if(left == right){

        return -1;

    }
}

int main(){

    int arr[] = {1,3,5,7,9,12,15,16,18,20};
    int size = sizeof(arr)/sizeof(arr[0]);

    int left = 0, right = size, val = 5;

    cout<<"The index of the given element is "<<binarySearch(arr,left,right,val);

    return 0;
}
