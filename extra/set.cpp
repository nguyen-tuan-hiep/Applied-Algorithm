#include<iostream>
#include<set>
using namespace std;

void traverse(set<int> s){
    for(set<int>::iterator it = s.begin(); it!= s.end(); it++)
        cout << *it << " ";
}

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(3);
    
    cout << "Size of set: " << s.size() << endl;
    traverse(s);
    cout << endl;

    s.erase(5);
    traverse(s);
    return 0;
}