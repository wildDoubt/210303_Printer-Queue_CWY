#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxValue(const vector<int>& arr){
    return *max_element(arr.begin(), arr.end());
}

int check(vector<int>& arr, int num){
    int maxValueExceptCurrent = getMaxValue(arr);
    int count = 0;
    int index = 0;
    while(!arr.empty()){
        if(arr[index]>=maxValueExceptCurrent){
            arr.erase(arr.begin()+index);
            maxValueExceptCurrent = getMaxValue(arr);
            count++;
            if(index<num){
                num--;
            }else if(index==num){
                return count;
            }
            index %= arr.size();
            continue;
        }
        ++index %= arr.size();
    }
    return -1;
}

int main() {
    int testCase;
    int N, M;

    cin>>testCase;
    for(int i = 0;i<testCase;i++){
        cin>>N>>M;
        vector<int> arr;
        for(int val, j = 0; j < N; ++j){
            cin >> val;
            arr.push_back(val);
        }
        cout<<check(arr, M)<<endl;
    }
    return 0;
}