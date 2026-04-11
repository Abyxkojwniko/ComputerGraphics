#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;
vector<int> a(N, 0), b(N, 0);

void insert(int l, int r, int c){
    b[l] += c;
    b[r+1] -= c; 
}

int main(){
    int n, m;
    cin >> n >> m;
    int l, r, c;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        insert(i, i, a[i]);
    }
    while(cin >> l >> r >> c){
        insert(l - 1, r - 1, c);
    }
    int temp = 0;
    for(int i = 0; i < n; ++i){
        temp += b[i];
        cout << temp << " ";
    }
    return 0;
}