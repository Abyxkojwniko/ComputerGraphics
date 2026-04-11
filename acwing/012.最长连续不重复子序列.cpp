#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> count(10000001, 0);

int main(){
    int n, length = 1;
    cin >> n;
    vector<int> b(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    int left = 0, right = 0;
    for(right = 0; right < n; ++right){
        if(count[b[right]] == 0){
            count[b[right]] = 1;
            length = max(length, right - left + 1);
        }
        else{
            while(count[b[right]] == 1){
                count[b[left]] = 0;
                ++left;
            }
            count[b[right]] = 1;
        }
    }
    cout << length << endl;
}