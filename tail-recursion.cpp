//tail recursion:print first call later
#include<iostream>
using namespace std;

void Print(int n){
    if(n==0){
        return ;
    }
    cout << "hello world" << endl;
    Print(n-1);

    
}

int main(){
    Print(4);
    return 0;
}