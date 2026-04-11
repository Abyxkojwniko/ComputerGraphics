#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> nums;
    int count = 1;
    int first, last;
    while(cin >> first >> last){
        nums.push_back({first, last});
    }
    sort(nums.begin(), nums.end());
    first = nums[0].first;
    last = nums[0].second;
    for(int i = 1; i < nums.size(); ++i){
        if(nums[i].first <= last) last = max(nums[i].second, last);
            last = nums[i].second;
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}