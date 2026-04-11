#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010, M = 30000010;
int son[M][2], a[N], idx = 0;

void insert(int x){
    int p = 0;
    for(int i = 30; ~i; --i){
        int &s = son[p][x >> i & 1];
        if(!s) s = ++idx;
        p = s;
    }
}

int query(int x){
    int p = 0, res = 0;
    for(int i = 30; ~i; --i){
        int s = x >> i & 1;
        if(son[p][!s]){
            res += 1 << i;
            p = son[p][!s];
        }
        else p = son[p][s];
    }
    return res;
}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for(int i = 0; i < n; ++i){
        res = max(res, query(a[i]));
    }
    cout << res << endl;
    return 0;
}