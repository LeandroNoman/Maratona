#include <iostream>


using namespace std;

int matriz[101][101];

int maximo(int a , int b){
    if(a>b) return a;
    return b;
}

void lcs( string s1 , string s2){
    int n1 = s1.size();
	int n2 = s2.size();

    for(int i = 0 ; i < n1 ; i++){
        matriz[i][0] = 0;
    }
    for(int i = 0 ; i < n2 ; i++){
        matriz[0][i] = 0;
    }


	for (int i=1; i<=n1; i++){
		for (int j=1; j<=n2; j++){
                if (s1[i-1] == s2[j-1]){
                    matriz[i][j] = 1 + matriz[i-1][j-1];
                }
                else{
                    matriz[i][j] = maximo (matriz[i-1][j], matriz[i][j-1]);
                }
		}
	}

}

string resultado(string s1 , string s2){
    string s = "";

    int n1 = s1.size();
    int n2 = s2.size();

    while(n1!= 0 and n2!=0){
            if(s1[n1-1] == s2[n2-1]){
                s+= s2[n2-1];
                n1 -- ;
                n2 -- ;
            }else{
                if(matriz[n1][n2] == matriz[n1-1][n2]){
                    s+= s1[n1-1];
                    n1 -- ;
                }else{
                    s+= s2[n2-1];
                    n2--;
                }
            }
    }
    while(n1 > 0){
        s+= s1[n1-1];
        n1--;
    }
    while(n2 > 0){
        s+= s2[n2-1];
        n2--;
    }
    return s;
}


int main(){
    string  s1 , s2 , s3;
    int teste = 1;
    while(true){
        cin >> s1;
        if(s1 == "#"){break;}
        cin >> s2;
        lcs(s1,s2);
        s3 = resultado(s1,s2);

        cout << "Teste " << teste << endl;
        for(int i = s3.size()  ; i > 0 ; i--){
            cout << s3[i-1];
        }
        teste++;
        cout << "\n\n";

    }

}
