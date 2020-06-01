#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

double dist(pair<double, double> a, pair<double, double> b)
{
    return (double) sqrt((a.first - b.first)*(a.first - b.first) +  (a.second - b.second)*(a.second - b.second)) ;
}

double programa(int n)
{
    pair<double, double> pares[n];
    std::vector<int> dentro;
    std::vector<int> fora;
    double menor =  0;
    int f = 0;
    double maior = 0;

    for(int i = 0 ; i < n ; i ++)
    {
        double a, b;
        scanf("%lf %lf" , &a , &b);
        pares[i] = make_pair(a, b);
    }

    /*for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            printf("%d %d %.4lf\n", i, j, dist(pares[i], pares[j]));
        }
    }*/

    for(int i = 1 ; i < n ; i++)
    {
        dentro.push_back(i);
    }
    fora.push_back(0);
    while(dentro.size() >0)
    {
        int id1 = 0, id2 = 0;
        double menor = dist(pares[fora[0]], pares[dentro[0]]);

        for(int i = 0 ; i < fora.size() ; i++)
        {
            for(int j = 0 ; j < dentro.size() ; j++)
            {
                double aux = dist(pares[fora[i]], pares[dentro[j]]);
                if(menor > aux)
                {
                    id1 = i;
                    id2 = j;
                    menor = aux;
                }
            }
        }
        fora.push_back(dentro[id2]);
        dentro.erase(dentro.begin() + id2);
        if(maior < menor){
            maior = menor;
        }

    }
    return maior;

}

int main()
{
    int n;

    scanf("%d" ,&n);
    while(n!=0){
        printf("%.4lf\n" , programa(n));
          scanf("%d" ,&n);
    }
    return 0;
}
