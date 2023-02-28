#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> queue){
    if(queue.empty())   return;
    int x = queue.front();
    cout << x << " ";
    queue.pop();
    printQueue(queue);
    queue.push(x);
}

int main(){

    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);

    cout << "myQueue: ";
    printQueue(myQueue);

    
}