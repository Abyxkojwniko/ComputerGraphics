#include <iostream>
#include <stack>

using namespace std;

stack<int> nums;

int main(){
    int n = 0;
    cin >> n;
    int val = 0;
    for(int i = 0; i < n; ++i){
        cin >> val;
        while(!nums.empty() && val <= nums.top()){
            nums.pop();
        }
        if(!nums.empty()){
            cout << nums.top() << " ";
        }
        else{
            cout << "-1" << " ";
        }
        nums.push(val);
    }
    return 0;
}