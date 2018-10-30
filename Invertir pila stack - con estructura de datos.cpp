#include <iostream>

using namespace std;

struct pila{
	int valor;
	struct pila * sgtPTR;
};

//el typedef define un tipo de dato en este caso define struct pila como PILA
//Y PILA* (que sería lo mismo que struct pila *) por PILAPTR
//Esto se usa para hacer más facil la declaracion de estructuras 
typedef struct pila PILA;
typedef PILA * PILAPTR;

//Funciones Básicas de una pila
	void imprimirPila (PILAPTR);
	void insertar (PILAPTR*, int);
	int sacarValor(PILAPTR *);
	void pedirDatos (PILAPTR*,int*);
	void invertirPila (PILAPTR*, PILAPTR);

int main(int argc, char** argv) {
	PILAPTR pila1 = NULL;
	PILAPTR pila2 = NULL;
	int numero;
	
	pedirDatos(&pila1,&numero);
	cout<<"\n-------RESULTADOS FINALES-------\n";
	cout<<"\nLa pila 1 es:\n"<<endl;
	imprimirPila (pila1);
	
	cout<<"\nLa pila invertida es:\n"<<endl;
	invertirPila (&pila2, pila1);
	imprimirPila (pila2);
	return 0;
}

int sacarValor(PILAPTR*topPTR){
	PILAPTR tempPTR;
	int valor;
	tempPTR = *topPTR;
	valor = (*topPTR)->valor;
	*topPTR= (*topPTR)->sgtPTR;
	delete(tempPTR);
	return valor;
}


void insertar (PILAPTR*topPTR, int v){
	PILAPTR nuevoPTR;
	nuevoPTR = new (PILA);
	
	if (nuevoPTR != NULL){
		nuevoPTR->valor = v;
		nuevoPTR->sgtPTR = *topPTR;
		*topPTR = nuevoPTR;
	}else{
		cout<<"No hay espacio en su corazon para ti :'v\n";
	}
}


void imprimirPila (PILAPTR pila){
	if (pila == NULL){
		cout<<"Pila vacia\n";
	}else{
		while(pila!=NULL){
			cout<<pila->valor<<endl;
			pila = pila->sgtPTR;
		}
	}
}


void pedirDatos(PILAPTR*pila1,int *numero){
	cout<<"Ingrese valor (-1 fin): ";
	cin>>*numero;
	
	while(*numero!=-1){
		insertar(pila1,*numero);
		cout<<"Ingrese valor (-1 fin): ";
		cin>>*numero;
	}
}


void invertirPila (PILAPTR *pila2, PILAPTR pila1){
	int v;
	
	while(pila1 != NULL){
		v = sacarValor(&pila1);
		insertar (pila2, v);
	}
}



