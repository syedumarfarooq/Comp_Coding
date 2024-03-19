#include <iostream>
using namespace std;
void pr(int n){
    if(n==0){
        return;
    }
    pr(n/10);
    cout<<n%10<<" ";
}
int main()
{
    pr(673);

    return 0;
}
