#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//void gen_arr( float V[], int n, float dg, float gg);

// function for generating array
void gen_arr(float V[], int n, float dg, float gg){
	srand(time(NULL));
	printf("%f %f", dg, gg);
	for(int i=0; i<n; i++){
		V[i] = ((float)rand() / (gg-dg+1)+dg);
	}	
	return 0;
}

int sekv_pret(float V[], int n, float x){
	for(int i=0;i<n;i++){
		if(V[i] == x){
			return i;
		}
	}
	return -1;        // if false then it will return -1
}


void sort(float V[], int n){
	float s;
	for(int i = 0; i<n; i++){
		for(int j=i;j<n;j++){
			if(V[i]>V[j]){
				s = V[j];
				V[j] = V[i];
				V[i] = s;
			}
		}
	}
}

int middle(int a, int b){
	return (a+b)/2;
}

int bin_pret(float V[], int n, float x){
	int dg = 0;
	int gg = n;
	int mid = middle(dg, gg);
	while(1){
		printf("%d", mid);
		if(gg>dg){
			if(V[mid] == x){
				while(V[mid] == x && mid>0){
					mid--;
				}
				return mid+2;
			}
			else if(V[mid] < x){
				dg=mid+1;
				mid = middle(mid+1, gg);
			}
			else{
				gg = mid-1;
				mid = middle(dg, mid-1);
			}		
		}
		else if(gg <= dg){
			if( V[gg] == x ){
				return gg+1;
			}
			else{
				return -1;
			}
		}
	}
}

int main(){
  //ovo nije slozeno kak treba, samo sam testao
	float V[] = {0, 5, 4, 3, 7, 8, 3, 1};
	float d=0;
	float g=200.0;
	
	//gen_arr(V, 5, d, g);
	for(int i=0;i<5;i++){
		printf("%.2f\n", V[i]);
	}
	printf("sortirano");
	sort(V, 8);
	for(int i=0;i<5;i++){
		printf("%.2f\n", V[i]);
	}
	
	printf("\n%d", bin_pret(V, 8, 9));
	return 0;
	
	
}
