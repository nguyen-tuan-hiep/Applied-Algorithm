#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> vec;
    // vector<int> vec = {1,2,3,4,5,6}};
    cout << "Before: vector size = " << vec.size() << endl;
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(10);
    vec.push_back(6);
    cout << "After: vector size = " << vec.size() << endl;

    cout << "\nLast element: " << vec.back() << endl; //vec[vec.size()-1]

    cout << "\nDuyet bang index: ";
    for(int i = 0; i<vec.size(); i++)
        cout << vec[i] << " ";

    cout << "\nDuyet bang for-each: ";
    for(int x : vec)
        cout << x << " ";

    cout << "\nDuyet bang iterator: ";
    for(vector<int>::iterator it = vec.begin(); it!= vec.end(); it++){
        cout << *it << " ";
    }

    cout << "\nDuyet bang auto: ";
    for(auto it = vec.begin(); it!= vec.end(); it++){
        cout << *it << " ";
    }

    cout << "\nvec[3]: " << *(vec.begin()+3) << endl;     //vec[3]

    return 0;   
}



