#include <iostream>
#include <algorithm>


using namespace std;

const int N = 1000010;

int q[N];
int s;

void down(int u){
    int t = u;
    if(u * 2 <= s && q[u * 2] < q[t]) t = u * 2;
    if(u * 2 + 1 <= s && q[u * 2 + 1] <= q[t]) t = 2 * u + 1;
    if(u != t){
        swap(q[u], q[t]);
        down(t);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n; ++i) cin >> q[i];
    s = n;
    for(int i = n / 2; i; i--) down(i);
    while(m--){
        cout << q[1] << endl;
        q[1] = q[s];
        --s;
        down(1);
    }
    return 0;
}