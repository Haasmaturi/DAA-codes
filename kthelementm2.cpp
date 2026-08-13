#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    cin>>k;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    cout<<"Kth smallest element = "<<a[k-1];

    return 0;
}