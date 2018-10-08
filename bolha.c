#include <stdio.h>
#include <stdlib.h>

void imprimir(int v[],int tam){
	
	int i;
	
	for(i=0;i<tam;i++){
		printf("%d ",v[i]);
	}	
}

int main(){
	
	int vetor[] = {10,3,5,7,8};
	int i,j;
	int aux;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			
			if(vetor[i]>vetor[i+1]){
				
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}
			
		}
	}
	
	imprimir(vetor,5);
	
	return 0;
}
