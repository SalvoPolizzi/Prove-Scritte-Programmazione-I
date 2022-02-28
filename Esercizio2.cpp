/*
Scrivere un metodo che prenda in input un parametro formale matrice M di dimensioni n × m di puntatori
a stringhe, e che restituisca true se esiste almeno una colonna in M che abbia un egual numero di stringhe palindrome di una
delle righe di M.
*/

#include<string>
#include<iostream>

using namespace std;

//Metodo che controlla se una stringa è palindroma
bool checkPalindroma(string s){
    string pal;
    for(int i=s.length()-1; i>=0; i--){
        pal+=s[i];
    }
    if(pal==s)
        return true;
    return false;
}

//Funzione print che mi stampa le matrici di puntatori
template<typename T>
void PrintMatrix(T*** Matrix, int n, int m){
    cout << "---MATRICE---" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(Matrix[i][j])
                cout << *Matrix[i][j] << " ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    cout << "------------" << endl;
}


bool esercizio2(string*** M, int n, int m){
    for(int i=0; i<m; i++){ //Fisso le colonne
        int pal_cols=0;
        for(int j=0; j<n; j++){ //Conto tutte le palindrome della colonna
            if(M[j][i] && checkPalindroma(*M[j][i])){
                pal_cols++;
            }
        }
        for (int z = 0; z < n; z++){ //Scorro le righe 
            int pal_rows = 0;
            for (int d = 0; d < m; d++){
                if (M[z][d] && checkPalindroma(*M[z][d])){ // Controllo le palindrome di tutta la riga
                    pal_rows++;
                }
            }
            if(pal_rows==pal_cols) // Se il numero di palindrome è uguale ritorno true
                return true;
        }
    }
    return false;
}





// Esempio nel main

int main(){
    cout << "Matrice di puntatori a stringhe (*=nullptr)" << endl;
    string*** M= new string**[2];
    for(int i=0; i<2; i++){
        M[i] = new string*[3];
        for(int j=0; j<3; j++){//Facciamo immettere le stringhe all'utente
            string utente;
            cout << "Inserisci la stringa della matrice in posizione [" << i << "][" << j << "]: ";
            cin >> utente;
            cout << endl;
            if(utente!="*")
                M[i][j] = new string (utente);
            else
                M[i][j] = nullptr;
        }
    }
    PrintMatrix(M, 2, 3);

    if(esercizio2(M,2,3)){
        cout << "Esiste una riga contenente lo stesso numero di palindrome di una colonna";
    }else{
        cout << "Non esiste una riga contenente lo stesso numero di palindrome di una colonna";
    }
}

//FINE ESERCIZIO