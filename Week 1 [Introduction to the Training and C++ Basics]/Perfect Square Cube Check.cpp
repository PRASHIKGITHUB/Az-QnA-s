#include <iostream>
using namespace std;
bool isPerfectSquare(int n) {
    int root = 1;
    while (root * root < n) {
        root++;
    }
    return (root * root == n);
}

bool isPerfectCube(int n) {
    int root = 1;
    while (root * root * root < n) {
        root++;
    }
    return (root * root * root == n);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int q, n;
        cin >> q >> n;

        if (q == 1) {
            if (isPerfectSquare(n)) {
                cout << "YES" <<endl;
            } else {
                cout << "NO" <<endl;
            }
        } else if (q == 2) {
            if (isPerfectCube(n)) {
                cout << "YES" <<endl;
            } else {
                cout << "NO" <<endl;
            }
        }
    }

    return 0;
}