#include<iostream>
using namespace std;

int fibonacciSeries(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return fibonacciSeries(n-1)+fibonacciSeries(n-2);
}
int main(){
    int n,result;
    cout << "enter the number of term you want:";
    cin >> n;
    for(int i=1;i<=n;i++){
        result = fibonacciSeries(i);
        cout << result << endl;
    }
    return 0; 
}