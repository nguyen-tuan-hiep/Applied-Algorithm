#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// The C++ function std::algorithm::includes() test whether first set is subset of another or not. This member function expects elements in sorted order. It use operator< for comparison.

int main(){
    vector<int> vec1 = {3,2,5,1,4};
    vector<int> vec2 = {3, 5, 1};

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    // using include() check if all elements
    // of vec2 lie in vec1
    if (includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end())){
        cout << "All elements of 2nd container are in 1st "
                "container";
    }
    else{
        cout << "All elements of 2nd container are not in "
                "1st container";
    }
}