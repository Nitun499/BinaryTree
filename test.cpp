#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
// int KthLargest(vector<int> & v,int k){
//     priority_queue<int,vector<int>,greater<int>> minheap;
//     for(int i=0;i<k;i++){
//         minheap.push(v[i]);
//     }
//     for(int i=k;i<v.size();i++){
//         if(v[i]>minheap.top()){
//             minheap.pop();
//             minheap.push(v[i]);
//         }
//     }
//     return minheap.top();

// }
void Partition(vector<int> &arr)
{
    int pindex = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            swap(arr[i], arr[pindex]);
            pindex++;
        }
    }
    sort(arr.begin(), arr.begin() + pindex);
    sort(arr.begin() + pindex, arr.end());
}

int main()
{
    vector<int> v = {12,31,10,5,8,9,56,32,11,45};

    cout << "Before sorting" << endl;
    for (int a : v)
    {
        cout << a << " ";
    }

    cout << "After sorting" << endl;
    Partition(v);
    for (int l : v)
    {
        cout << l << " ";
    }
    // int res=KthLargest(v,3);
    // cout<<res;
}