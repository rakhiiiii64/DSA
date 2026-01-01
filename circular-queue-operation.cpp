//circular queue operation
#include<iostream>
using namespace std;

class Queue{
  int *arr;
  int capacity,rear,front;

  public:
  Queue(int cap){
    capacity=cap;
    arr=new int[capacity];
    front=-1;
    rear=-1;
  }
    
  bool isFull(){
    return (rear+1)%capacity==front;
  }

  bool isEmpty(){
    return (front==-1);
  }

  void enqueue(int value){
    if(isFull()){
      cout << "Queue overflow" << endl;
      return;
    }
    else{
      if(front==-1){
        front=0;
      }
      rear=(rear+1)%capacity;
      arr[rear]=value;
    }
  }
  void dequeue(){
    if(isEmpty()){
      cout << "Queue underflow" << endl;
      return ;
    }
    else{
      cout << arr[front] << " removed from the queue" << endl;
      if(rear==front){
        front=rear=-1;
      }
      else{
        front=(front+1)%capacity;
      }
    }
  }
   void size(){
    if(isEmpty()){
      cout << "the size of the queue is 0" << endl;
    }
    else{
      cout << "the size of the queue is " << (rear-front+capacity)%capacity+1 << endl;
    }  
  }
  void peek(){
    if(isEmpty()){
      cout << "queue is empty" << endl;
    }
    else{
      cout << arr[front] <<" is the peek of Queue " << endl;
    }  
  }
  void Front()
  {
    if(isEmpty()){
      cout << "Queue is empty" << endl;
      return ;
    }
    else{
      cout << "the front of the queue is " << arr[front] << endl;
    }
  }
  void Rear()
  {
    if(isEmpty()){
      cout << "Queue is empty" << endl;
      return ;
    }
    else{
      cout << "the rear of the queue is " << arr[rear] << endl;
    }  
  }
  void display(){
    cout << "the element in the Queue are:" << endl;
    for(int i=0 ; i<(rear-front+capacity)%capacity+1 ; i++)
    {
      cout << arr[i] << endl;
    }
  }
  ~Queue(){
    delete[] arr;
  }
};

int main()
{
  int n;
  cout << "enter the capacity of the Queue" << endl;
  cin >> n;
  Queue obj(n);
  int a;
  int choice;
  bool end=false;

  while(!end)
  {
    cout << endl << "make your choice:\n1.Enqueue\n2.Dequeue\n3.front\n4.rear\n5.peek\n6.size\n7.display\n8.Exit\n" << endl;
    cin >> choice;
    switch(choice){
      case 1:{
        cout << "enter the element to enqueue in the queue" << endl;
        cin >> a;
        obj.enqueue(a);
        break;
      } 
      case 2:{
        obj.dequeue();
        break;
      }
      case 3:{
        obj.Front();
        break;
      }
      case 4:{
        obj.Rear();
        break;
      }
      case 5:{
        obj.peek();
        break;
      }
      case 6:{
        obj.size();
        break;
      }
      case 7:{
        obj.display();
        break;
      }
      case 8:{
        end=true;
        break;
      }
      default :{
        cout << "invalid choice" << endl;
      } 
    }
  }   
  return 0;
}