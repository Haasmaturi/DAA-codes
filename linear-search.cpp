//Linear search program which takes input array and prints the index if found
#include<iostream>
using namespace std;

int main(){
    int n,i,key;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to search for: ";
    cin>>key;
    for(i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"Element found at index: "<<i<<endl;
            return 0;
        }
    }
    cout<<"Element not found in the array."<<endl;
    return 0;
}