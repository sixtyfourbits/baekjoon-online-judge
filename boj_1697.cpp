#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    queue<long long> q;
    vector<long long> v(200001);

    q.push(n);
    v[n] = 1;

    while (!q.empty()) 
    {
        if (q.front() < 100000 && v[q.front() + 1] == 0)
        {
            v[q.front() + 1] = v[q.front()] + 1;
            q.push(q.front() + 1);
        }
        if (q.front() < 100000 && v[q.front() * 2] == 0)
        {
            v[q.front() * 2] = v[q.front()] + 1;
            q.push(q.front() * 2);
        }
        if (q.front() > 0 && v[q.front() - 1] == 0)
        {
            v[q.front() - 1] = v[q.front()] + 1;
            q.push(q.front() - 1);
        }

        q.pop();
    }

    cout << v[k] - 1;
}