#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    // int sum=0,temp=0,mx=INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     sum=0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum+=arr[j];
    //         mx=max(mx,sum);
    //     }
    // }
    // cout<<mx;

    //kadane's theorm
    int currentsum=0 ,maxsum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentsum+=arr[i];
        if (currentsum<0)
        {
            currentsum=0;
        }
        maxsum=max(maxsum,currentsum);
    }
    cout<<maxsum;

 return 0;
}
