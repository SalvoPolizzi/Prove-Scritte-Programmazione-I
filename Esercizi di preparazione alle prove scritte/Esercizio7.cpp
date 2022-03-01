/*
Scrivere un metodo che prenda in input un parametro formale matrice S di puntatori a carattere di dimensione
n × m, uno short w ed uno short k, e restituisca il valore booleano true se in S sono presenti almeno una riga ed almeno una
colonna che presentano ciascuna almeno w stringhe di lunghezza minore di k.
*/

#include<iostream>
#include<string>
#include<cstring>

using namespace std;


//Funzione print che mi stampa le matrici di puntatori
template<typename T>
void PrintPointerMatrix(T*** Matrix, int n, int m){
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

//Funzione richiesta dall'esercizio
bool Esercizio7(char*** S, int n, int m, short w, short k){
    bool found_rows= false;//Imposto le 2 variabili booleane che mi serviranno per la condizione finale
    bool found_cols= false;
    for(int i=0; i<n; i++){//Fisso le righe della matrice
        int count=0;
        for(int j=0; j<m; j++){//Scorro la riga
            string rows = "";
            if(S[i][j]){
                rows+=*S[i][j];
                if(rows.length()<k)//Se la stringa ha lunghezza minore di k allora aumento il count di 1
                    count++;
            }
        }
        if(count>=w){//Se il count delle stringhe che verificano la condizione è >= w, allora esisterà la riga richiesta
            found_rows=true;
            break;
        }
    }
    for(int j=0; j<m; j++){//Fisso le colonne della matrice
        int count=0;
        for(int i=0; i<n; i++){//Scorro la colonna
            string cols="";
            if(S[i][j]){
                cols+=*S[i][j];
                if(cols.length()<k)//Se la stringa ha lunghezza minore di k allora aumento il count di 1
                    count++;
            }
        }
        if(count>=w){//Se il count delle stringhe che verificano la condizione è >= w, allora esisterà la colonna richiesta
            found_cols=true;
            break;
        }
    }
    if(found_rows && found_cols) //Se la condizione è soddisfatta per almeno una riga ed una colonna ritorniamo true
        return true;
    return false;
}



//Esempio nel main
int main(){
    cout << "Dammi le dimensioni n,m della matrice di puntatori a char S, e dammi i rispettivi short w,k (lascia uno spazio per ognuno): ";
    int n,m;
    short w,k;
    cin >> n >> m >> w >> k;
    cout << "Costruiamo la matrice di puntatori (per nullptr inserisci il carattere '*'): "<< endl;
    char*** S= new char**[n];
    for(int i=0; i<n; i++){
        S[i]= new char*[m];
        for(int j=0; j<m; j++){
            char utente;
            cout << "Dammi il puntatore a carattere in posizione [" << i << "][" << j << "]: ";
            cin >> utente;
            if(utente!='*')
                S[i][j]= new char(utente);
            else
                S[i][j]= nullptr;
        }
    }
    PrintPointerMatrix(S, n, m);
    cout << endl << "Verifico se la condizione richiesta dalla funzione è soddisfatta..." << endl;
    if(Esercizio7(S,n,m,w,k))
        cout << "LA CONDIZIONE E' VERIFICATA" << endl;
    else    
        cout << "LA CONDIZIONE NON E' VERIFICATA"<< endl;

}