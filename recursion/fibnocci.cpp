#include<iostream>

using namespace std;

int fibonacci(int num){

    if(num == 0 || num == 1) return num;

    return (fibonacci(num - 1) + fibonacci(num - 2));
}

int main(){

    // printing 6th element in fibonacci series
    cout<<fibonacci(6);

    return 0;
}