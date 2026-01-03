#include<iostream>
using namespace std;
int factorialB(int n);
int factorialA(int n){
    if(n==0){
        return 1;
    }
    return n*factorialB(n-1);
}
int factorialB(int n){
    if(n==0){
        return 1;
    }
    return factorialA(n);
}
int main(){
    int n,result;
    cout << "enter a number:";
    cin >> n;
    result = factorialA(n);
    cout << "factorial of " << n << " is " << result;
    return 0;
}