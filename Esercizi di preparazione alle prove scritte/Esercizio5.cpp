/*
 Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensioni n×m di elementi
distinti ed un array B di double di dimensioni k × n, e restituisca un array di n interi nel quale lo i-esimo elemento sia uguale
alla media aritmetica degli elementi presenti sia nella riga i-esima di A che nella colonna i-esima di B. NB: per decidere se un
elemento int della matrice A `e uguale ad un elemento double della matrice B si calcoli l’approssimazione all’intero pi`u vicino di
quest’ultimo.
*/

#include<iostream>
#include<cmath>

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

//Funzione richiesta dall'esercizio
int* Esercizio5(int** A, double** B, int n, int m, int k){
    int* C= new int [n]; //Creo dinamicamente l'array che ritornerò alla fine
    for(int i=0; i<n; i++){
        int sum_elements=0; // Creo la variabile che conterrà la somma degli elementi uguali
        int count=0; // Creo la variabile che servirà da contatore degli elementi 
        for(int j=0; j<m; j++){ 
            for(int z=0; z<k; z++){ //Per ogni elemento della riga di A, controllo tutta la colonna di B
                if(A[i][j]==round(B[z][i])){ // Stabilisco gli elementi uguali
                    sum_elements+=A[i][j];
                    count++;
                    break;
                }
            }
        }
        C[i] = sum_elements/(double)count;
    }
    return C;
}



//Esempio nel main
int main(){
    int n,m,k;
    cout << "Dammi le dimensioni n,m,k per la matrice A(nxm) di interi e la matrice B(kxn) di double (lascia uno spazio per ognuna): ";
    cin >> n;
    cin >> m;
    cin >> k;
    cout << endl;
    cout << "Costruiamo la matrice A: " << endl;
    int** A= new int*[n];
    for(int i=0; i<n; i++){
        A[i]= new int[m];
        for(int j=0; j<m; j++){
            cout << "Inserisci l'intero in posizione [" << i << "][" << j << "]: ";
            int utente;
            cin >> utente;
            A[i][j]=utente;
            cout << endl;
        }
    }

    cout << "Costruiamo la matrice B: " << endl;
    double** B= new double*[k];
    for(int i=0; i<k; i++){
        B[i]= new double [n];
        for(int j=0; j<n; j++){
            cout << "Inserisci il double in posizione [" << i << "][" << j << "]: ";
            double utente;
            cin >> utente;
            B[i][j]=utente;
            cout << endl;
        }
    }

    cout << "Le matrici create sono: " << endl;

    cout << "-Matrice A:" << endl;
    PrintMatrix(A, n, m);

    cout << "-Matrice B:" << endl;
    PrintMatrix(B, k, n);


    cout << "L'array C risulta essere:" << endl;
    int*C= Esercizio5(A,B,n,m,k);
    PrintArray(C, n);


}