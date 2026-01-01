//postfix evaluation

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

#define max 15
int stack[max];
int top=-1;

int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==max-1;
}
int peek(){
    return stack[top];
}
int pop(){
    if(isEmpty()){
        return -1;
    }
    return stack[top--];
}
void push(int ch){
    if (!isFull()){
        stack[++top]=ch;
    }    
}
int IfOperand(char ch){
    return (ch>='0' && ch<='9');
}

int main(){
    char arr[15];
    cout << "enter the expression:";
    cin >> arr;
    int n;
    n = strlen(arr);

    for(int i=0;i<n;i++){
        if(IfOperand(arr[i])){
            push(arr[i]-'0');
        }
        else{
            int b=pop();
            int a=pop();
            
            if(arr[i]=='+'){
                push(a+b);
            }
            else if(arr[i]=='-'){
                push(a-b);
            }
            else if(arr[i]=='*'){
                push(a*b);
            }
            else if(arr[i]=='/'){
                push(a/b);
            }
            else if(arr[i]=='^'){
                push(pow(a,b));
            }
        }    
    }
    cout <<"result:" << peek();
    return 0;
}