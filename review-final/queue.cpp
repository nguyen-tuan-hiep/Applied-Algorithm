// Perform a sequence of operations over a queue, each element is an integer:
// PUSH v: push a value v into the queue
// POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
// Input
// Each line contains a command (operration) of type
// PUSH  v
// POP
// Output
// Write the results of POP operations (each result is written in a line)
// Example
// Input
// PUSH 1
// PUSH 2
// PUSH 3
// POP
// POP
// PUSH 4
// PUSH 5
// POP
// #
// Output
// 1
// 2
// 3

#include<iostream>
#include<queue>
using namespace std;
queue<int> q;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(true);
    string cmd;

    do{
        cin >> cmd;
        if(cmd == "PUSH"){
            int v;
            cin >> v;
            q.push(v);
        }
        else if(cmd == "POP"){
            if(q.empty()){
                cout << "NULL" << endl;
                continue;
            }
            cout << q.front() << endl;
            q.pop();  
        }
    }while(cmd != "#");
    return 0;
}