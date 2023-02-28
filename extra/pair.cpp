#include<iostream>
#include<tuple>
using namespace std;

int main(){
    pair<int, int> p = make_pair(100,200);  //v = {100,200}
    cout << "first: " << p.first << endl << "second: " << p.second << endl;

    // unpack pair
    int a, b;
    tie(a, b) = p;
    cout << a << " " << b << "\n";

    //pair of pair
    pair<int, pair<int, char> > pair3 = { 3, { 4, 'a' } };
    int x, y;
    char z;
  
    // tie(x,y,z) = pair3; Gives compilation error
    // tie(x, tie(y,z)) = pair3; Gives compilation error
    // Each pair needs to be explicitly handled
    x = pair3.first;
    tie(y, z) = pair3.second;
    cout << x << " " << y << " " << z << "\n";

    return 0;
}