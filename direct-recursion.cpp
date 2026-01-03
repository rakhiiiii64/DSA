#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1 ;
    }
    return n*factorial(n-1);
}
int main(){
    int n,result;
    cout << "enter a number:";
    cin >> n;
    result = factorial(n);
    cout << "factorial of " << n << " is " << result;
    return 0;
}