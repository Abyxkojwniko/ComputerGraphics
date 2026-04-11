#include <iostream>

using namespace std;

const int N = 100010;

int p[N], s[N];

int find(int a) {
    if (p[a] != a) p[a] = find(p[a]);
    return p[a];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        s[i] = 1;
    }
    string op;
    int a, b;
    while (m--) {
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            int ra = find(a), rb = find(b);
            if (ra != rb) {
                // 只有合并时，才把 a 帮派的人数加到 b 帮派老板头上
                s[rb] += s[ra];
                p[ra] = rb;
            }
        } else if (op == "Q1") {
            cin >> a >> b;
            cout << (find(a) == find(b) ? "Yes" : "No") << "\n"; // 用 \n 提速
        } else {
            cin >> a;
            cout << s[find(a)] << "\n";
        }
    }
    return 0;
}