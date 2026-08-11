#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a,r;
    int n;
    cin>>a>>r>>n;
    double sum=a*(pow(r,n)-1)/(r-1);
    cout<<"Sum = "<<sum;
    return 0;
}