/*
Due stringhe si dicono sorelle se hanno lo stesso numero di vocali. 
Scrivere un metodo che prenda in input una matrice A di puntatori a stringhe, 
e restituisca un boolean che indichi se esiste una colonna di A in cui sono puntate almeno due stringhe sorelle.
N.B.: Attenzione alle eventuali stringhe mancanti.
*/


#include<iostream>
#include<string>

using namespace std;

//Metodo che conta il numero di vocali di una stringa
int countVocali(string s){
    string vocali= "aeiou";
    int count = 0;
    for(int i=0; i<s.length(); i++){
        if(vocali.find(s[i])!=string::npos)
            count++;
    }
    return count;
}

//Funzione richiesta
bool Esercizio2(string*** A, int n, int m){
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(A[i][j]){
                string col = *A[i][j];
                for(int z=i+1; z<n; z++){
                    if(A[z][j]){
                        string col_1 = *A[z][j];
                        if(countVocali(col)==countVocali(col_1))
                            return true;
                    }
                }
            }
        }
    }
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

//Esempio nel main
int main(){
    cout << "Dammi le dimensioni n,m della matrice di puntatori a stringhe: ";
    int n,m;
    cin >> n >> m;
    cout << "Costruiamo la matrice di puntatori a stringhe (per nullptr inserire il carattere '*'): " << endl;
    string*** S = new string**[n];
    for(int i=0; i<n ; i++){
        S[i]=new string*[m];
        for(int j=0; j<m ; j++){
            string utente;
            cout << "Inserisci la stringa in posizione [" << i << "][" << j << "]: ";
            cin >> utente;
            if(utente!="*")
                S[i][j]= new string(utente);
            else    
                S[i][j]=nullptr;
        }
    }
    PrintMatrix(S, n, m);
    cout << endl;
    if(Esercizio2(S,n,m))
        cout << "Esiste una colonna con 2 stringhe sorelle" << endl;
    else    
        cout << "Non esiste una colonna con 2 stringhe sorelle" << endl;
}