#include <iostream>
#include <queue>
using namespace std;

// 길이가 짧은 거 우선
// 이름은 사전 순

struct Node
{
    string name;
    int len;
};

priority_queue<Node> q;

bool operator<(Node a, Node b)
{
    if (a.len > b.len)
        return 1;
    if (a.len < b.len)
        return 0;
    return b.name < a.name;
}

int main()
{
    q.push({"Tom", 2});
    q.push({"Jason", 1});
    q.push({"KFC", 3});
    q.push({"BBQ", 1});
    q.push({"MOMS", 2});
    q.push({"MC", 4});

    while (q.size() != 1)
    {
        Node a = q.top();
        q.pop();

        Node b = q.top();
        q.pop();

        string newName = a.name;
        if (newName > b.name)
            newName = b.name;

        Node newEber = {a.name, a.len + b.len};
        q.push(newEber);
    }

    cout << q.top().name << " " << q.top().len;

    return 0;
}