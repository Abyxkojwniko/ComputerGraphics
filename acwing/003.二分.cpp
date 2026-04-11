#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000000;
int q[N];


int bsearch_l(int l, int r, int k){
    while(l < r){
        int mid = l + r >> 1;
        if(q[mid] >= k) r = mid;
        else l = mid + 1;
    }
    return r;
}

int bsearch_r(int l, int r, int k){
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(q[mid] <= k) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main(){
    int n, m, k;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> q[i];
    }
    for(int i = 0; i < m; i++){
        cin >> k;
        int left = bsearch_l(0, n - 1, k);
        int right = bsearch_r(0, n - 1, k);
        if(q[left] != k) cout << "-1 -1" << endl;
        else cout << left << " " << right << endl;
    }
    return 0;
}