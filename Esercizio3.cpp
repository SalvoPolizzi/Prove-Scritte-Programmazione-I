/*
Scrivere un metodo che prenda in input tre parametri formali: una matrice di stringhe S di dimensioni n×m,
un array di caratteri C che contiene elementi distinti, ed un float w. Il metodo restituisca true se esiste 
almeno una riga o una colonna della matrice tale che la percentuale di caratteri di C presenti in essa `e maggiore di w.
*/


#include<iostream>
#include<string>

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

bool Esercizio3(string** S, int n, int m, char* C, int k, float w){
    for(int i=0; i<n; i++){ // Scorro S per riga
        string string_rows; // creo un unica stringa contenente tutte le stringhe (concatenate) della riga
        for(int j=0; j<m; j++){ 
            string_rows+=S[i][j];
        }
        int count_char=0;
        for(int j=0; j<k; j++){ // scorro l'array C per vedere quanti caratteri sono presenti nella riga di S
            if(string_rows.find(C[j])!=string::npos){
                count_char++;
            }
        }
        double perc=((double)count_char/string_rows.length())*100; // calcolo percentuale
        if(perc>w)
            return true;
    }
    for(int j=0; j<m; j++){ // Scorro S per colonna
        string string_cols; // creo un unica stringa contenente tutte le stringhe (concatenate) della colonna
        for(int i=0; i<n; i++){
            string_cols+=S[i][j];
        }
        int count_char=0;
        for(int j=0; j<k; j++){ // scorro l'array C per vedere quanti caratteri sono presenti nella riga di S
            if(string_cols.find(C[j])!=string::npos){
                count_char++;
            }
        }
        double perc=((double)count_char/string_cols.length())*100; // calcolo percentuale
        if(perc>w)
            return true;
    }
    return false;
}


// Esempio nel main
int main(){
    int n,m,k;
    cout << "Inserisci le 3 dimensioni n,m,k (inserisci uno spazio per ognuna): ";
    cin >> n;
    cin >> m; 
    cin >> k;
    cout << "Creiamo la matrice S di stringhe nxm:"<< endl;
    string** S= new string*[n];
    for(int i=0; i<n; i++){
        S[i]=new string [m];
        for(int j=0; j<m; j++){
            string utente;
            cout << "Inserisci la stringa in posizione [" << i << "][" << j << "]: ";
            cin >> utente;
            S[i][j] = utente;
        }
    }
    cout << "Creiamo l'array di caratteri C di dimensione k:" << endl;
    char* C= new char[k];
    for(int i=0; i<k; i++){
        char utente;
        cout << "Inserisci il carattere in posizione [" << i << "]: ";
        cin >> utente;
        C[i] = utente;
    }

    cout << endl;

    PrintMatrix(S, n, m);
    PrintArray(C, k);

    if(Esercizio3(S,n,m,C,k,25.3))
        cout << "Esiste almeno una riga o una colonna della matrice tale che la percentuale di caratteri di C presenti in essa è maggiore di w" << endl;
    else
        cout << "Non esiste almeno una riga o una colonna della matrice tale che la percentuale di caratteri di C presenti in essa è maggiore di w" << endl;
}