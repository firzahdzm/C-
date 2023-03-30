#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
        	if(i==3 && j==1 || i==3 && j==2){
        		cout << arr[i][j]-1 << " ";
			} else if(i==4 && j==1 || i==4 && j==3){
				cout << arr[i][j]-2 << " ";
			} else if(i==4 && j==2){
				cout << arr[i][j]-3 << " ";
			}
			else cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < n-i-1; j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
        	if(i==n-2 && j==1 || i==n-2 && j==2){
        		cout << arr[i][j]-1 << " ";
			}
            else cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
