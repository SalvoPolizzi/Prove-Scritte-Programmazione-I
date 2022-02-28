/*
Scrivere un metodo che prenda in input due parametri formali: una matrice A di dimensioni n × m ed una
matrice B di dimensioni k × n entrambe di interi positivi. 
Il metodo restituisca un array C di double di dimensione n nel quale
lo i-esimo elemento dello array C sia uguale al rapporto tra la somma degli elementi della riga i-esima di A e il prodotto degli
elementi della colonna i-esima di B.
*/


#include<iostream>
#include<cstdlib>


using namespace std;

//Funzione (template) print per la stampa di matrici
template<typename T>
void PrintMatrix(T** Matrix, int n, int m){
    cout << "----MATRICE----" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<< Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------" << endl << endl;
}

//Funzione (template) print per la stampa di array
template<typename T>
void PrintArray(T* Arr, int n){
    cout << "----ARRAY----" << endl;
    for(int i=0; i<n; i++){
        cout << "Arr[" << i << "]=" << Arr[i] << " ";
    }
    cout << endl << "-------------"<< endl;
}

double* esercizio4(int** A, int** B, int n, int m, int k){
    double* C= new double[n]; //Inizializzo dinamicamente C
    for(int i=0; i<n; i++){ // Scorro contemporaneamente le righe di A e le colonne di B
        int sum_rows=0;
        int prod_cols=1;
        for(int j=0; j<m; j++){//sommatoria degli elementi della riga di A  
            sum_rows+=A[i][j];
        }
        for(int j=0; j<k; j++){//produttoria degli elementi della colonna di B
            prod_cols*=B[j][i];
        }
        C[i]=(double)sum_rows/prod_cols; // Elemento i-esimo di C come rapporto della sommatoria e della produttoria
    }
    return C;
}


//Esempio nel main
int main(){
    int n,m,k;
    cout << "Dammi le 3 dimensioni n, m, k (inserisci uno spazio per ogni dimensione): ";
    cin >> n;
    cin >> m;
    cin >> k;
    cout << endl;
    int** A=new int*[n];
    int** B=new int*[k];
    cout << "Creiamo la matrice A di interi di dimensione n x m randomicamente con numeri tra 0 e 100"<< endl;
    for(int i=0; i<n; i++){
        A[i]=new int[m];
        for(int j=0; j<m; j++){
            A[i][j]=rand()%(100);
        }
    }
    PrintMatrix(A,n,m);
    cout<< endl << "Creiamo la matrice B di interi di dimensione k x n randomicamente con numeri tra 0 e 10"<< endl;
    for(int j=0; j<k; j++){
        B[j]=new int[n];
        for(int i=0; i<n; i++){
            B[j][i]=rand()%(10);
        }
    }
    PrintMatrix(B,k,n);
    
    double* C = esercizio4(A, B, n, m, k);
    PrintArray(C, n);
}