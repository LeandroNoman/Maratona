#include <stdio.h>
#include <string.h>

#define MAXTIMES 50

int pontos[MAXTIMES];
int jogosFeitos[MAXTIMES][MAXTIMES];

//Retorna quantos jogos foram realizados para aumentar os pontos do time 0
int maximizaPontosTimeZero(int numTimes, int numEnfrentamentos) {
	int i, enfrentamentosNecessarios, jogosRealizados;

	jogosRealizados = 0;
	for(i = 1; i < numTimes; i++) {
		//Se o time 0 nao jogou com alguem, coloca vitoria pro 0
		if(jogosFeitos[0][i] < numEnfrentamentos) {
			//printf("Enfrentamentos entre 0 e %d necessarios = %d\n", i, numEnfrentamentos - jogosFeitos[0][i]);
			enfrentamentosNecessarios = numEnfrentamentos - jogosFeitos[0][i];
			pontos[0] += (enfrentamentosNecessarios) * 2;
			jogosFeitos[0][i] = numEnfrentamentos;
			jogosFeitos[i][0] = numEnfrentamentos;
			jogosRealizados += enfrentamentosNecessarios * 2;
		}
	}

	return jogosRealizados;
}

void lerEntrada(int numTimes, int numEnfrentamentos, int numJogosDisputados) {
	int i, time1, time2;
	char resultadoPartida;

	for(i = 0; i < numJogosDisputados; i++) {
		//Realiza a leitura da entrada
		scanf("%d", &time1);
		resultadoPartida = ' ';
		while(resultadoPartida == ' ') {
			scanf("%c", &resultadoPartida);
		}
		scanf("%d", &time2);

		//Preenche os jogos feitos e os pontos obtidos
		jogosFeitos[time1][time2]++;
		jogosFeitos[time2][time1]++;
		if(resultadoPartida == '=') {
			pontos[time1]++;
			pontos[time2]++;
		}
		else {
			pontos[time2] += 2;
		}
	}
}

int min(int i, int j) {
	if(i > j) {
		return j;
	}
	else {
		return i;
	}
}

int resolveProblema(int numTimes, int numEnfrentamentos) {
	int i, j, timeMenosPontos, timeMaisPontos, jogosFaltantes;

	jogosFaltantes = 0;

	for(i = 1; i < numTimes; i++) {
		for(j = i + 1; j < numTimes; j++) {
			if(jogosFeitos[i][j] < numEnfrentamentos) {
				jogosFaltantes++;
				pontos[i] += (numEnfrentamentos - jogosFeitos[i][j]);
				pontos[j] += (numEnfrentamentos - jogosFeitos[i][j]);
			}
		}
	}

	while(1) {
		timeMaisPontos = 0;
		timeMenosPontos = 0;

		for(i = 1; i < numTimes; i++) {
			if(pontos[i] >= pontos[timeMaisPontos]) {
				timeMaisPontos = i;
			}
		}

		//printf("Time mais pontos %d com %d pontos\n", timeMaisPontos, pontos[timeMaisPontos]);

		if(timeMaisPontos == 0) {
			printf("Y\n");
			return;
		}
		else if(jogosFaltantes <= 0) {
			printf("N\n");
			return;
		}

		//Descobre o time com menos pontos que pode perder para o com mais
		for(i = 1; i < numTimes; i++) {
			if(i == timeMaisPontos) {
				continue;
			}
			if(jogosFeitos[timeMaisPontos][i] < numEnfrentamentos) {
				timeMenosPontos = i;
				break;
			}
		}
		for(i = 1; i < numTimes; i++) {
			if(i == timeMaisPontos) {
				continue;
			}
			if(jogosFeitos[timeMaisPontos][i] < numEnfrentamentos) {
				if(pontos[i] < pontos[timeMenosPontos]) {
					timeMenosPontos = i;
				}
			}
		}
		//printf("Time menos pontos %d com %d pontos\n", timeMenosPontos, pontos[timeMenosPontos]);
		//printf("Jogos entre %d e %d = %d\n", timeMaisPontos, timeMenosPontos, jogosFeitos[timeMaisPontos][timeMenosPontos]);
		//Se o time com mais nao pode perder para ninguem, acabou
		if(timeMenosPontos == 0) {
			printf("N\n");
			return;
		}
		else {
			jogosFeitos[timeMaisPontos][timeMenosPontos]++;
			jogosFeitos[timeMenosPontos][timeMaisPontos]++;
			jogosFaltantes--;
			pontos[timeMaisPontos]--;
			pontos[timeMenosPontos]++;
		}
	}
}

int main() {
	int numTimes, numEnfrentamentos, numJogosDisputados, jogosFaltantes, i, impossivel;

	scanf("%d %d %d", &numTimes, &numEnfrentamentos, &numJogosDisputados);
	
	while(numTimes != 0 || numEnfrentamentos != 0 || numJogosDisputados != 0) {
		memset(pontos, 0, sizeof(int) * MAXTIMES);
		memset(jogosFeitos, 0, sizeof(int) * MAXTIMES * MAXTIMES);

		impossivel = 0;
		jogosFaltantes = (((numTimes - 1) * numEnfrentamentos) * numTimes) - (numJogosDisputados * 2);

		//printf("Jogos Faltantes antes do 0: %d\n", jogosFaltantes);

		lerEntrada(numTimes, numEnfrentamentos, numJogosDisputados);
		jogosFaltantes -= maximizaPontosTimeZero(numTimes, numEnfrentamentos);
		for(i = 1; i < numTimes; i++) {
			if(pontos[i] >= pontos[0]) {
				impossivel = 1;
				break;
			}
		}
		if(impossivel == 1) {
			printf("N\n");
			scanf("%d %d %d", &numTimes, &numEnfrentamentos, &numJogosDisputados);
			continue;
		}
		//printf("Jogos Faltantes: %d\n", jogosFaltantes);
		resolveProblema(numTimes, numEnfrentamentos);

		scanf("%d %d %d", &numTimes, &numEnfrentamentos, &numJogosDisputados);
	}

	return 0;
}