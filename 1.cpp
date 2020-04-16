#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int f[n+1]; // минимальчное количсетво банкнот для n рублей
    int a[6] = {10,20,50,100,200,500};
    f[0] = 0;

    for (int k = 1; k <= n; ++k){
        f[k] = 1000000000;
        for (int i = 0; i < 6; ++i){
             if((k >= a[i]) && (f[k-a[i]] + 1 < f[k])) {
                f[k] = f[k-a[i]]+1;
             }
        }
    }

    int sum = 0;
    if (f[n] == 1000000000)
        cout<<-1;
    else{
        while(n > 0){
            for(int i=0; i < 6; ++i){
                if (f[n-a[i]] == f[n]-1){
                    sum++;
                    n = n - a[i];
                    break;
                }
            }
        }
        cout << sum;
    }

}
