#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int factorial(int a){
    int res = 1;
    for (int i = 1; i <= a; i++)
        res *= i;
    return res;
}
int main(){
    int a;
    cin >> a;
    int res;
    res = factorial(a);
    cout << res << endl;
    return 0;
}

