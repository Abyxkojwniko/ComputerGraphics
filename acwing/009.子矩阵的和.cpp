#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    // 直接初始化一个 (n+1) 行 (m+1) 列，全为 0 的二维 vector
    // 这完美解决了你的越界问题和“哨兵位”问题
    vector<vector<int>> S(n + 1, vector<int>(m + 1, 0));
    // 1. 读取数据并直接构建二维前缀和
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int val;
            cin >> val;
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + val;
        }
    }
    // 2. 处理 q 次查询
    while (q--) { // 规范写法，直接扣 q 次
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 核心查询：大矩形 - 上 - 左 + 左上角
        int result = S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
        cout << result << '\n'; // 别忘了用 \n 替换 endl
    }
    return 0;
}