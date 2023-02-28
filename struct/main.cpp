#include<bits/stdc++.h>
using namespace std;

struct SinhVien{
    int id;
    string name;
    double grade;

    void print(){
        cout << id << " " << name << " " << fixed << setprecision(2) << grade << endl;
    }
};

int main(){
    SinhVien a = {20205151, "Nguyen Tuan Hiep",3.60};
    a.print();
    return 0;
}