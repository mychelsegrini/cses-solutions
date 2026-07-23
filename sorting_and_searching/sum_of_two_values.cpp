#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool comp(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

int main() {
    int n, x, val, counter = 0;
    cin >> n >> x;
    vector<vector<int>> nums(n);

    for(int k = 0; k < n; k++){
        cin >> val;
        nums[k] = {val, counter};
        counter++;
    }

    sort(nums.begin(), nums.end(), comp);
    int beg;
    int end;
    int mid;
    int target;

    for(int k = 0; k < n; k++){
        beg = k + 1;
        end = n - 1;
        target = x - nums[k][0];

        while(beg <= end){
            mid = (end - beg)/2 + beg;
            if(nums[mid][0] < target){
                beg = mid + 1;
            } else if (nums[mid][0] > target){
                end = mid - 1;
            } else {
                cout << nums[mid][1] + 1 << " " << nums[k][1] + 1;
                return 0;
            }
            
        }
    }

    cout << "IMPOSSIBLE";
}