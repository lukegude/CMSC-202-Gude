// for i in range(7):
//     print(i)
//     for n in range(i):
//         print(n)


#include <iostream>
using namespace std;
int main (){
    int n;
    cin >> n;
    for (int i = 1; i<=n;i++){
        for (int j = 1; j <= i*1;j++){
            cout << j%10;
        }
        cout << endl;
    }
}