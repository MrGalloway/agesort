#include <iostream>
#include <fstream>

int sort(int n, int arr[]);

int main(){
	int n = 1;
	int input = 0;
	
	while(n!=0){
		std::cin >> n;
		if(n!=0){
			int * arr = new int[n];
			for(int i=0;i<n;i++){
				std::cin >> arr[i];
			}
			sort(n,arr);
		}
	}
}

int sort(int n, int arr[]){
	
	
	int *pMin = &arr[0];
	int *pMax = &arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]<*pMin){
			pMin=arr+i;
		}else if(arr[i]>*pMax){
			pMax=arr+i;
		}
	}
	
	
	int len = *pMax-*pMin+1;
	int * index = new int[len];
	
	for(int i=0; i<len; i++){
		index[i]=0;
	}
	
	
	for(int i=0;i<n;i++){
		index[*(arr+i)-*pMin]++;
	}
	
	int * sumcount = new int[len];
	
	int sum = 0;
	
	for(int i=0; i<len; i++){
		sum+=index[i];
		sumcount[i]=sum;
	}
	
	int * out = new int[n];
	for(int i=0;i<n;i++){
		out[sumcount[arr[i]-*pMin]-1]=arr[i];
		sumcount[arr[i]-*pMin]--;
	}

	for(int i=0;i<n;i++){
		std::cout << *(out+i);
		if(i<n-1){std::cout << " ";}
	}
	std::cout << std::endl;
	
	delete [] out;
	delete [] index;
	delete [] sumcount;
	return 0;
}