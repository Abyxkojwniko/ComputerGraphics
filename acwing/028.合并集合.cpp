#include <iostream>

using namespace std;

const int N = 1000010;
int p[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n; ++i) p[i] = i;
    while(m--){
        char op;
        int a, b;
        cin >> op >> a >> b;
        if(op == 'M') p[find(a)] = find(b);
        else{
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}