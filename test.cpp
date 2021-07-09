#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
#define N 10

int main(){
     int size,a[N],n,index;
    cout<<"Enter the no of elements u want "<<endl;
    cin>>size;
    cout<<"Enter the elements of an array:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element you want to insert in an array"<<endl;
    cin>>n;
    cout<<"Enter the index"<<endl;
    cin>>index;
    for(int i=size;i>index;i--)
    {
        a[i]=a[i-1];
    }
    a[index]=n;
    cout<<"After inserting element in array:"<<endl;
    for(int i=0;i<=size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}