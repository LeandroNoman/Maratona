# include <iostream>

using namespace std;

int mod(int x){
    if(x<0) return -x;
    return x;
}

int problema(int n ){
    int vetor[n];
    int cot = 0;
    int swa;
    int aux;
    int xx;
    for(int i = 0 ; i < n ; i++){
        cin >> vetor[i];
    }
    for(int i = 1 ; i < n ; i ++){

        if(!(vetor[i-1] == i)){
            aux = mod(vetor[i-1] - i);
            if(aux > 0){
                cot += (2*aux -1);
                swa = vetor[i-1];
                int u = vetor[i-1]-1;
                vetor[i-1] = vetor[u];
                vetor[u] = swa;
                i--;
            }
        }
    }
    return cot;
}

int main(){
    int n;
    cin >> n;
    while(n!=0){
        int c = problema(n);
        if(c%2 == 0){
            cout  <<"Carlos\n";
        }else
        {
            cout  <<"Marcelo\n";
        }
        cin >> n;
    }

}
