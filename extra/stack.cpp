#include<iostream>
#include<stack>
using namespace std;


void printStackFromBottom(stack<int> stack){
    if(stack.empty()){
        return;
    }
    int x = stack.top();
    stack.pop();
    printStackFromBottom(stack);
    cout << x << " ";
    stack.push(x);
}

void printStackFromTop(stack<int> stack){
    if(stack.empty()) return;
    int x = stack.top();
    stack.pop();
    cout << x << " ";
    printStackFromTop(stack);
    stack.push(x);
}

int main(){
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    cout << "Number of elements on the stack: " << myStack.size() << endl;    
    printStackFromBottom(myStack);
    cout << endl;
    printStackFromTop(myStack);
    cout << endl;

    stack<int> anotherStack;
    anotherStack.push(10);
    anotherStack.push(9);
    anotherStack.push(8);
    anotherStack.push(7);
    anotherStack.push(6);

    myStack.swap(anotherStack);

    while(!myStack.empty()){
        cout << "Popping " << myStack.top() << endl;
        myStack.pop();
    }
    cout << "Number of elements on the stack: " << myStack.size() << endl;
}