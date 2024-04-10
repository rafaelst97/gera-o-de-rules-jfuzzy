#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <omp.h>

using namespace std;

int main()
{
	string porcentagem_assistida[3] = {"pequena", "media", "alta"};
	string avaliacao [3] = { "ruim", "regular", "boa" };
	string comentarios [3] = { "poucos", "alguns", "muitos" };
	string tempo_de_video [3] = { "curto", "medio", "longo" };
	string visualizacoes [3] = { "poucas", "algumas", "muitas" };
	int rule = 1;

	ofstream arquivo("rules.txt");

	if (arquivo.is_open()) {
		#pragma omp parallel for
		for (int a = 0; a < 3; a++) {
			//string texto_porcentagem = "RULE " + to_string(rule) + " : IF porcentagem_assistida IS " + porcentagem_assistida[a];
			for (int b = 0; b < 3; b++) {
				//string texto_avaliacao = " AND avaliacao IS " + avaliacao[b];
				for (int c = 0; c < 3; c++) {
					//string texto_comentarios = " AND comentarios IS " + comentarios[c];
					for (int d = 0; d < 3; d++) {
						//string texto_tempo_de_video = " AND tempo_de_video IS " + tempo_de_video[d];
						for (int e = 0; e < 3; e++) {
							string texto = "RULE " + to_string(rule) + " : IF porcentagem_assistida IS " + porcentagem_assistida[a]
								+ " AND avaliacao IS " + avaliacao[b]
								+ " AND comentarios IS " + comentarios[c]
								+ " AND tempo_de_video IS " + tempo_de_video[d]
								+ " AND visualizacoes IS " + visualizacoes[e]
								+ " THEN recomendacao IS \n";
							arquivo << texto;
							rule++;
						}
					}
				}
			}
		}
		arquivo.close();
		cout << "Escrita finalizada";
		return 0;
	}
	else {
		cerr << "Erro ao abrir o arquivo." << endl;
		return 1;
	}
}