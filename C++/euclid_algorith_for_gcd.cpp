#include<bits/stdc++.h>
//#include<iostream>
int gcd(int a,int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
 return 0;
}
