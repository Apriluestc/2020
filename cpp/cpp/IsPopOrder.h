#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int>& input, vector<int>& output) {
    if (input.size() != output.size()) {
        return false;
    }
    stack<int> s;
    for (size_t i = 0, j = 0; i < input.size(); ++i) {
        s.push(input[i]);
        while (j < output.size() && s.top() == output[i]) {
            ++j;
            s.pop();
        }
    }
    return s.empty();
}
