#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> sum;
    sum.push_back(0);
    int num = 0, temp = 0;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        num += temp;
        sum.push_back(num);
    }
    int l, r;
    while(cin >> l >> r){
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}