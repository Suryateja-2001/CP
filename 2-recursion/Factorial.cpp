#include<iostream>

using namespace  std;

int factorial(int num){
    if(num == 1) return num;

    return (num * factorial(num - 1));
}

int main(){
    int num;

    cout<<"Enter the number to find factorial: ";
    cin>>num;

    cout<<factorial(num);

    return 0;
}