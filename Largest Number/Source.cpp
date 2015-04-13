#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> v;
        for_each(num.cbegin(), num.cend(), [&](int i){
            v.push_back(to_string(i));
        });
        sort(v.begin(), v.end(), [&](const string &a, const string &b){
            return (a + b) > (b + a);
        });
        string str;
        for_each(v.cbegin(), v.cend(), [&](const string& s){
            if (str.empty() && s == "0") return;
            str += s;
        });
        return str.empty()? "0": str;
    }
};

int main()
{
    int arr[] = {3, 30, 34, 5, 9};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    cout << solution.largestNumber(num) << endl;
}
