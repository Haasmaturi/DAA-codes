#include <iostream>
using namespace std;

int main(){
    double a,r,sum=0;
    int n;
    cin>>a>>r>>n;

    for(int i=1;i<=n;i++){
        sum=sum+a;
        a=a*r;
    }

    cout<<"Sum = "<<sum;
    return 0;
}