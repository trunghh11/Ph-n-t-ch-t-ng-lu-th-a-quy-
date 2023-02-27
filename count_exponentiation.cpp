#include <bits/stdc++.h>
using namespace std;
int d = 0;
void dem(int X, int n, int k){
    if (X == 0) d++;
    if (X > 0){
        for (int i = k+1; pow(i,n) <= X; i++){
            dem((X-pow(i,n)),n, i);
        }
    }
}


int main() {
    int X,n;
    cin >> X >> n;
    dem(X,n,0);
    cout << d << endl;

}
