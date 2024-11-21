#include <iostream>
using namespace std;

void Merge(int *v, int inicio, int fim);
void Intercala(int *v, int inicio, int meio, int fim);
void BuscaSoma(int *v, int x, int tamanho);

int main(){
    int *v, x, n;
    cout << "Tamanho do vetor" << endl;
    cin >> n;
    if(!(v = new(nothrow) int[n])){
        cout << "Droga" << endl;
        return -1;
    }
    cout << "Preencha o vetor" << endl;
    for(int i=0;i<n;i++)
        cin >> v[i];
    Merge(v,0,n);
    cout << "Vetor ordenado" << endl;
    for(int i=0;i<n;i++)
        cout << v[i] << endl;
    cout << "Digite o numero para a busca" << endl;
    cin >> x;
    BuscaSoma(v,x,n);
    return 0;
}

void BuscaSoma(int *v, int x, int tamanho){
    int *i;
    int *j;
    int soma;
    i = &v[0];
    j = &v[tamanho-1];
    soma = *i + *j;
    while(soma != x || *i != *j){
        soma = *i + *j;
        if(*i == *j){
            cout << x << " nao encontrado somando dois numeros diferentes do vetor" << endl;
            return;
        }
        if(soma == x){
            cout << x << " econtrado somando " << *i << " e " << *j << endl;
            return;
        }
        if(soma < x)
            i++;
        if(soma > x)
            j--;
        
    }
}

void Merge(int *v, int inicio, int fim){
    if(inicio < (fim-1)){
        int meio = (inicio + fim)/2;
        Merge(v,inicio, meio);
        Merge(v,meio,fim);
        Intercala(v,inicio,meio,fim);
    }
}

void Intercala(int *v, int inicio, int meio, int fim){
    int *w, i = inicio, j = meio, k = 0;
    w = new(nothrow) int[fim];
    while(i < meio && j < fim){
        if(v[i] < v[j]){
            w[k] = v[i];
            i++;
        }
        else{
            w[k] = v[j];
            j++;
        }
        k++;
    }
    while(i < meio){
        w[k] = v[i];
        i++;
        k++;
    }
    while(j < fim){
        w[k] = v[j];
        j++;
        k++;
    }
    for(k = 0; k < fim - inicio; k++)
        v[inicio + k] = w[k];
    delete[] w;
    w = NULL;
}