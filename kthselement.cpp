#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    cin>>k;

    for(int i=0;i<k;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min])
                min=j;
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }

    cout<<"Kth smallest element = "<<a[k-1];

    return 0;
}