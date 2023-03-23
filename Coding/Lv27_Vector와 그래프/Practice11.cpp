#include <iostream>
#include <vector>
using namespace std;

vector<int> stack;

void push(int n)
{
    stack.push_back(n);
}

void pop()
{
    stack.pop_back();
}

int top()
{
    return stack[stack.size() - 1];
}

int main()
{
    top();
    return 0;
}