#include <iostream>
using namespace std;


int powerMeUp(int n, int f){
   int h = n;
   for (int i = 0; i < f-1; i++){
      h *= n;
   }
   return h;
}


int main (){
   cout << powerMeUp(3,9) << endl;
   // cout << "Done!\n"; 
}