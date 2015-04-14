#include <iostream>
#include <stack>
using namespace::std;

class MinStack {
public:
    void push(int x) {
        if (s.empty()) {
            s.push(pair<int, int>(x, x));
        } else {
            s.push(pair<int, int>(x, min(x, s.top().second)));
        }
    }
    
    void pop() {
        if (!s.empty())
            s.pop();
    }
    
    int top() {
        if (s.empty())
            return INT_MIN;
        return s.top().first;
    }
    
    int getMin() {
        if (s.empty())
            return INT_MIN;
        return s.top().second;
    }
private:
    stack<pair<int, int>> s;
};

int main()
{
    MinStack stack;
    int arr[] = {3, 2, 5, 4, 1, 7, 6};
    int res[] = {3, 2, 2, 2, 1, 1, 1};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; ++i) {
        stack.push(arr[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        cout << ((stack.top() == arr[i]) & (stack.getMin() == res[i])) << endl;
        stack.pop();
    }
}
