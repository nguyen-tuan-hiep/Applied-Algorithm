#include<iostream>
#include<algorithm>
using namespace std;

// UCLN
//  Library: 'algorithm'
//  __gcd(m, n) 
// Parameter :  m, n
// Return Value :  0 if both m and n are zero, 
// else gcd of m and n.

int lcm(int a, int b){
    return (a / __gcd(a, b)) * b;
}

 int main(){
    cout << "gcd(90,72) = " << __gcd(90,72) << endl;
    cout << "lcm(6,20) = " << lcm(6,20);
 }