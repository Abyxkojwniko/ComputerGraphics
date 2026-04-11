#include <iostream>
#include <string>

using namespace std;

const int N = 100010;
int q[N], head = 0, tail = 0; 

void push(int x) {
    q[tail++] = x;
}

void pop() {
    head++;
}

void empty() {
    if (head == tail) cout << "YES" << endl;
    else cout << "NO" << endl;
}

void query() {
    cout << q[head] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    while (m--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            push(x);
        } else if (op == "pop") {
            pop();
        } else if (op == "empty") {
            empty();
        } else {
            query();
        }
    }
    return 0;
}