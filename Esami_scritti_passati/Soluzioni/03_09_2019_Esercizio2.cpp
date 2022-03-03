/*
Scrivere un metodo che prenda in input una matrice di puntatori a stringhe P di dimensioni n×m, due short a e b, ed una stringa s. 
Il metodo restituisca il valore booleano true se esiste almeno una colonna in P tale che 
la stringa s sia sottostringa di un numero compreso tra a e b (inclusi) di stringhe della colonna stessa.
PS: Si assuma 0 < a ≤ b < n,
*/


#include<iostream>
#include<string>

using namespace std;

//Funzione richiesta dall'esercizio
bool Esercizio2(string*** P, int n, int m, short a, short b, string s){
    for(int j=0; j<m; j++){
        int count_str_col=0;
        for(int i=0; i<n; i++){
            if(P[i][j]){
                string col = *P[i][j];
                if(col.find(s)!=string::npos)
                    count_str_col++;
            }
        }
        if(count_str_col>=a && count_str_col<=b)
            return true;
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
    int n,m;
    cout << "Dammi le dimensioni n,m della matrice di puntatori a stringhe (lascia uno spazio per ognuna): ";
    cin >> n >> m;
    short a,b;
    cout << endl << "Dammi due short a,b tali che 0<a<=b<n: ";
    cin >> a >> b;
    string sottostringa;
    cout << "Dammi la stringa con cui verificheremo la condizione dell'esercizio: ";
    cin >> sottostringa;
    cout << "Costruiamo la matrice di puntatori a stringhe (per nullptr inserire '*'):" << endl;
    string*** S= new string **[n];
    for(int i=0; i<n; i++){
        S[i]= new string*[m];
        for(int j=0; j<m; j++){
            string utente;
            cout << "Inserisci la stringa puntata in posizione [" << i << "][" << j << "]: ";
            cin >> utente;
            if(utente!="*")
                S[i][j]=new string (utente);
            else
                S[i][j]=nullptr;
        }
    }
    PrintMatrix(S, n, m);
    cout << "Controlliamo se la condizione richiesta dall'esercizio viene soddisfatta..." << endl;
    if(Esercizio2(S,n,m,a,b,sottostringa))
        cout << "LA CONDIZIONE E' SODDISFATTA" << endl;
    else 
        cout << "LA CONDIZIONE NON E' SODDISFATTA"  << endl;
}