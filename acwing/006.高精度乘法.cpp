#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string mul(string a, string b){
    if(a == "0" || b == "0") return "0";
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);
    for(int i = n - 1; i >= 0; --i){
        for(int j = m - 1; j >= 0; --j){
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    string result = "";
    for(int i = 0; i < res.size(); ++i){
        if(!(result.empty() && res[i] == 0)){
            result += to_string(res[i]);
        }
    }
    return result.empty() ? "0" : result;
}

int main() {
    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;
    
    cout << mul(s1, s2) << endl;
    
    return 0;
}
