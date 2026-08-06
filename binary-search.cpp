//Binary search program which takes input array and prints the index if found
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
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key){
            cout<<"Element found at index: "<<mid<<endl;
            return 0;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"Element not found in the array."<<endl;
    return 0;
}