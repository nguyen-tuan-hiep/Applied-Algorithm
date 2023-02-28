#include<iostream>
#include<deque>
using namespace std;


// size()
// push_front()
// push_back()
// pop_front()
// pop_back()
// empty
// front()
// back()

void printFromFront(deque<int> q){
    if(q.empty())   return;
    int x = q.front();
    cout << x << " ";
    q.pop_front();
    printFromFront(q);
    q.push_front(x);
}

int main(){
    deque<int> deq;
    deq.push_front(31);
    deq.push_back(15);
    deq.push_front(4);
    deq.push_back(27);
    deq.push_front(34);
    deq.push_front(66);
    deq.push_back(9);
    printFromFront(deq);
    return 0;
}