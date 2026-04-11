#include <iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;

void insert(string str){
    int p = 0;
    for(int i = 0; str[i]; ++i){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    ++cnt[p];
}

int query(string str){
    int p = 0;
    for(int i = 0; str[i]; ++i){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string op, s;
        cin >> op >> s;
        if(op == "I") insert(s);
        if(op == "Q") cout << query(s) << endl;
    }
    return 0;
}
