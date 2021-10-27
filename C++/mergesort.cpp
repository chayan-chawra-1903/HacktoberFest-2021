#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1,n2=r-mid;
    int arr1[n1],arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        arr1[i]=arr[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i]=arr[mid+1+i];
    }
    int temp1=0,temp2=0,k=l;
    while (temp1<n1 && temp2<n2)
    {
        if(arr1[temp1]>arr2[temp2]){
            arr[k]=arr2[temp2];
            temp2++;
            k++;
        }
        else{
            arr[k]=arr1[temp1];
            temp1++;
            k++;
        }
    }
    while (temp1<n1)
    {
        arr[k]=arr1[temp1];
        temp1++;
        k++;
    }
    while (temp2<n2)
    {
        arr[k]=arr2[temp2];
        temp2++;
        k++;
    }  
}
void merge_sort(int arr[],int l,int r){
    int mid=(l+r)/2;
    if(l<r)
    {
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,(mid+1),r);

        merge(arr,l,mid,r);
    }
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    merge_sort(arr,0,(n-1));

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
 return 0;
}
