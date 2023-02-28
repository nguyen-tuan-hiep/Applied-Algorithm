#include<iostream>
#include<queue>
using namespace std;

void showpq(priority_queue<int> pq){
    if(pq.empty())  return;
    int x = pq.top();
    cout << x << " ";
    pq.pop();
    showpq(pq);
    pq.push(x);
}

int main(){
    priority_queue<int> pq;
    pq.push(1);
    pq.push(4);
    pq.push(2);
    pq.push(8);
    pq.push(10);
    pq.push(6);
    cout << "my priority queue: ";
    showpq(pq);
}