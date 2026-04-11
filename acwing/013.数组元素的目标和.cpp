#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n, 0), b(m, 0);
    int i = 0, j;
    for(i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(j = 0; j < m; ++j){
        cin >> b[j];
    }
    i = 0;
    j = m - 1;
    while(i < n && j >= 0 && a[i] + b[j] != x){
        if(j >0 && a[i] + b[j] > x) --j;
        else if(i < n - 1 && a[i] + b[j] < x) ++i;
        else break;
    }
    cout << i << " " << j << endl;
    return 0;
}