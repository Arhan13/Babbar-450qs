#include <bits/stdc++.h>
using namespace std;

int minComputation(int size, int files[])
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < size; i++)
    {
        pq.push(files[i]);
    }

    int counter = 0;
    while (pq.size() > 1)
    {
        int smallet_element = pq.top();
        pq.pop();
        int second_smallet_element = pq.top();
        pq.pop();
        int temp = smallet_element + second_smallet_element;
        counter += temp;
        pq.push(temp);
    }
    return counter;
}

int main()
{
    int n = 6;
    int files[] = {2, 3, 4, 5, 6, 7};
    cout << minComputation(n, files);
    return 0;
}