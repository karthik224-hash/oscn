// Banker's Algorithm 
#include <iostream> 
using namespace std; 

int main() 
{ 
	// P0, P1, P2, P3, P4 are the Process names here 

    int n,m;
	cout<<"Enter the no of processes and resources that are present : ";
	cin>>n>>m;
	int alloc[n][m];
	int max[n][m];
	int avail[m];
	cout<<"Enter the allocation resources : \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>alloc[i][j];
		}
	}
	cout<<"Enter the maximum  resources : \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>max[i][j];
		}
	}
	cout<<"Enter the available  resources : \n";
	for(int i=0;i<m;i++)
		cin>>avail[i];

	int f[n], ans[n], ind = 0; 
	for (int k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][m]; 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	for (int i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (int j = 0; j < m; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (int y = 0; y < m; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
	} 
	

	cout << "Following is the SAFE Sequence" << endl; 
	for (int i = 0; i < n - 1; i++) 
		cout << " P" << ans[i] << " ->"; 
	cout << " P" << ans[n - 1] <<endl; 

	return (0); 
} 

// This code is contributed by SHUBHAMSINGH10 

