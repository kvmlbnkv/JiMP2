#include <iostream>
using namespace std;

void filltab(int **A, int n, int m){
	int l=1;
	for(int i = 0; i<n ; i++){
		for(int j = 0; j<m ; j++){
			A[i][j]=l;
			l++;
		}
	}
	
}

void readtab(int **A, int n, int m){
	for(int i = 0; i<n ; i++){
		for(int j = 0; j<m ; j++){
			cout << A[i][j] << " ";
			if(j==m-1){
				cout << endl;
			}
		}	
	}
}

void deletetab(int **A, int n){
	for (int i = 0; i<n; i++){
		delete A[i];
	}
	delete* A;
}

int main(void){
	int n,m;
	
	cout << "Długość:" << endl;
	cin >> n;
	cout << "Szerokość:" << endl;
	cin >> m;
	
	int **A = new int*[n];
	for(int i = 0; i<n ; i++){
		A[i] = new int[m];
		
	}
	
	filltab(A,n,m);
	cout << endl;
	readtab(A,n,m);
	deletetab(A,n);

	return 0;
}
