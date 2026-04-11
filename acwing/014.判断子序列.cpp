#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int j = 0; j < m; ++j){
        cin >> b[j];
    }
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            ++i;
        }
        ++j;
    }
    if(i < n) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}