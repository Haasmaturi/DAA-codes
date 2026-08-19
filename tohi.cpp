#include <iostream>
#include <cmath>
using namespace std;

void moveDisk(char from,char to,int disk){
    cout<<"Move disk "<<disk<<" from "<<from<<" to "<<to<<endl;
}
int main(){
    int n;
    cout<<"Enter number of disks: ";
    cin>>n;
    char A='A',B='B',C='C';
    if(n%2==0)
        swap(B,C);
    int totalMoves=pow(2,n)-1;
    for(int i=1;i<=totalMoves;i++){
        if(i%3==1){
            int disk=1;
            int x=i;
            while(x%2==0){
                disk++;
                x/=2;
            }
            moveDisk(A,C,disk);
        }
        else if(i%3==2){
            int disk=1;
            int x=i;
            while(x%2==0){
                disk++;
                x/=2;
            }
            moveDisk(A,B,disk);
        }
        else{
            int disk=1;
            int x=i;
            while(x%2==0){
                disk++;
                x/=2;
            }
            moveDisk(B,C,disk);
        }
    }
    return 0;
}