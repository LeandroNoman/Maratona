#include <iostream>

int main(int argc, char *argv[]){

    int jogador_1, jogador_2, a, b, x, y, contador;
    contador = 0;

    std::cin >> x >> y >> a >> b;
    
    for(jogador_1 = a; jogador_1 <= x; jogador_1++){

        int final = std::min(jogador_1-1, y);

        if(b <= final){
            contador = contador + (final - b + 1);
        }
    }

    std::cout << contador << std::endl;

    for(jogador_1 = a; jogador_1 <= x; jogador_1++){

        int final = std::min(jogador_1-1, y);

        for(jogador_2 = b; jogador_2 <= final; jogador_2++){

            std::cout << jogador_1 << " " << jogador_2 << std::endl;
        }
    }
    return 0;
}
