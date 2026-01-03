//head recursion: call first work later 
#include<iostream>
using namespace std;

int Sum(int n){
    if(n==0){
        return 0 ;
    }
    return n+Sum(n-1);
}
int main(){
    int n,result;
    cout << "enter the number of term:";
    cin >> n;
    result = Sum(n);
    cout << "Sum=" << result;
    return 0;
}