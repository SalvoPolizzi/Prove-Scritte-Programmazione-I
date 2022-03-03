/*
Scrivere un metodo che prenda in input un parametro formale matrice quadrata Q di interi ed un double w, 
e restituisca un valore booleano true se esiste almeno una colonna della matrice Q tale che 
il rapporto tra la somma degli elementi della colonna stessa e la somma degli elementi della diagonale secondaria di Q 
sia maggiore di w.
*/

#include<iostream>


using namespace std;


//Funzione richiesta dall'esercizio
bool Esercizio1(int** Q, int n, double w){
    int sum_diag_sec=0;
    for(int i=0; i<n; i++){//Scorro la diagonale secondaria sommando i suoi elementi
        sum_diag_sec+=Q[i][n-1-i];
    }
    for(int j=0; j<n; j++){//Fisso le colonne
        int sum_cols=0;
        for(int i=0; i<n; i++){//Scorro le colonne sommando i rispettivi elementi
            sum_cols+=Q[i][j];
        }
        if((sum_cols/(double)sum_diag_sec)>w)//Verifico se la condizione viene soddisfatta
            return true;
    }
    return false;
}


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


//Esempio nel main
int main(){
    int n;
    double w;
    cout << "Dammi la dimensione n della matrice quadrata di interi e un double w: ";
    cin >> n >> w;
    cout << "Costruiamo la matrice: " << endl;
    int** Q= new int*[n];
    for(int i=0; i<n; i++){
        Q[i] = new int [n];
        for(int j=0; j<n; j++){
            int utente;
            cout << "Inserisci l'intero in posizione [" << i << "][" << j << "]: ";
            cin >> utente;
            Q[i][j]=utente;
        }
    }
    PrintMatrix(Q, n, n);
    cout << "Verifichiamo se la condizione richiesta dall'esercizio viene soddisfatta...." << endl;
    if(Esercizio1(Q, n, w))
        cout << "LA CONDIZIONE E' SODDISFATTA" << endl;
    else
        cout << "LA CONDIZIONE NON E' SODDISFATTA" << endl;
}