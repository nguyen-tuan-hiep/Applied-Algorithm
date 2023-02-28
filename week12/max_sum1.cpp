#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int s[1000];
int check[1000];
int a[1000];
int maxSum(int n)
{
    if (n == 1)
    {
        return a[1];
    }
    if (check[n] != 0)
        return s[n];
    int res = max(maxSum(n - 1) + a[n], a[n]);
    s[n] = res;
    check[n] = 1;
    return res;
}

int main()
{
    int size;
    cout << "Nhap so phan tu cua mang: ";
    cin >> size;

    cout << "Nhap phan tu: ";
    for (int i = 1; i <= size; ++i)
    {
        cin >> a[i];
    }
    int res = 0;
    int k = maxSum(size);

    for (int i = 1; i <= size; ++i)
    {
        if(res < s[i])  res = s[i];
    }
    cout << res;
    return 0;
}