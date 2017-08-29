#include <iostream>
#include <vector>
using namespace std;

int jumpStep(int n){
    if (n < 1) return 0;
    if (n == 1 || n == 2) return n;
    int a = 1, b = 2, c;
    for (int i = 3; i <= n; ++i){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(int argc, char** argv){
    int n;
    cin >> n;
    cout << jumpStep(n) << endl;
    return 1;
}