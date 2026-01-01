//infix to postfix

#include<iostream>
using namespace std;

#define max 15
char stack[max];
int top=-1;

int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==max-1;
}
char peek(){
    return stack[top];
}
char pop(){
    if(isEmpty()){
        return -1;
    }
    return stack[top--];
}
void push(char ch){
    if (!isFull()){
        stack[++top]=ch;
    }    
}
int IfOperand(char ch){
    return (ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9');
}

int precedence(char ch){
    if(ch=='+'||ch=='-'){
        return 1;
    }
    else if(ch=='*'||ch=='/'){
        return 2;
    }
    else if(ch=='^'){
        return 3;
    }
    else{
        return -1;
    }
}
int isRightAssocivity(char op){
    return op=='^';
}
int isLeftAssocivity(char op){
    return op=='+'|| op=='-' || op=='*' || op=='/';
}

void convertInfixToPostfix(char* exp,int n){
    char postfix[n];
    int j=0;

    for(int i=0;i<n;i++){
        if (IfOperand(exp[i])){
            postfix[j++]=exp[i];
        }

        else if(exp[i]=='('){
            push(exp[i]);
        }

        else if(exp[i]==')'){
            while(!isEmpty() && peek()!='('){
                postfix[j++]=pop();
            }
            pop(); //to remove ( 
        }
        else{
            while(!isEmpty() && (precedence(peek()) >= precedence(exp[i]) && isLeftAssocivity(exp[i]))){
                postfix[j++]=pop();
            }
            push(exp[i]);
        }
    }
    while(!isEmpty()){
        postfix[j++]=pop();
    }
    cout << "postfix:";
    for(int a=0;a<n;a++){
        cout << postfix[a];
    }

}
int main(){
    char expression[]="a+b*(c-d/e^f)*g";
    //15=number of character in the expression
    convertInfixToPostfix(expression,15);
    return 0;
}