#include<bits/stdc++.h>
using namespace std;

bool checkPhone(string s){
    if(s.length() != 10)    return false;
    for(int i = 0; i<=s.length();++i){
        if(!(s[i] >= '0' && s[i] <= '9'))   return false;
    }
    return true;
}

