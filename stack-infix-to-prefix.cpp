//infix to prefix

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

void convertInfixToPrefix(char* exp,int n){
    char prefix[n];
    int j=0;

    for(int i=n-1;i>=0;i--){
        if (IfOperand(exp[i])){
            prefix[j++]=exp[i];
        }

        else if(exp[i]==')'){
            push(exp[i]);
        }

        else if(exp[i]=='('){
            while(!isEmpty() && peek()!=')'){
                prefix[j++]=pop();
            }
            pop(); //to remove ) 
        }
        else{
            while(!isEmpty() && (precedence(peek()) >= precedence(exp[i]) && isRightAssocivity(exp[i]))){
                prefix[j++]=pop();
            }
            push(exp[i]);
        }
    }
    while(!isEmpty()){
        prefix[j++]=pop();
    }
    cout << "prefix:";
    for(int a=n-1;a>=0;a--){
        cout << prefix[a];
    }

}
int main(){
    char expression[]="a+b*(c-d/e^f)*g";
    //15=number of character in the expression
    convertInfixToPrefix(expression,15);
    return 0;
}