#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> b(1010, vector<int>(1010, 0));

bool insert(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x2+1][y1] -= c;
    b[x1][y2+1] -= c;
    b[x2+1][y2+1] += c;
}
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> map(n+1, vector<int>(m+1, 0));
    int val = 0;
    for(int i = 1; i < n + 1; ++i){
        for(int j = 1; j < m + 1; ++j){
            cin >> val;
            insert(i, j, i, j, val);
        }
    }
    int x1, y1, x2, y2, c;
    while(cin >> x1 >> y1 >> x2 >> y2 >> c){
        insert(x1, y1, x2, y2, c);
    }
    for(int i = 1; i < n + 1; ++i){
        for(int j = 1; j < m + 1; ++j){
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}