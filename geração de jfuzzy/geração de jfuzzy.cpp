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
			for (int b = 0; b < 3; b++) {
				for (int c = 0; c < 3; c++) {
					for (int d = 0; d < 3; d++) {
						for (int e = 0; e < 3; e++) {

							//Pesos para cada variavel
							int peso_porcentagem_assistida = 2;
							int peso_avaliacao = 3;
							int peso_comentarios = 2;
							int peso_tempo_de_video = 1;
							int peso_visualizacoes = 2;
							float a_convertido = 0;
							float b_convertido = 0;
							float c_convertido = 0;
							float d_convertido = 0;
							float e_convertido = 0;

							//Conversao de variaveis
							if (a == 0) {
								a_convertido = 0;
							}
							else if (a == 1) {
								a_convertido = 5;
							}
							else if (a == 2) {
								a_convertido = 10;
							}

							if (b == 0) {
								b_convertido = 0;
							}
							else if (b == 1) {
								b_convertido = 5;
							}
							else if (b == 2) {
								b_convertido = 10;
							}

							if (c == 0) {
								c_convertido = 0;
							}
							else if (c == 1) {
								c_convertido = 5;
							}
							else if (c == 2) {
								c_convertido = 10;
							}

							if (d == 0) {
								d_convertido = 0;
							}
							else if (d == 1) {
								d_convertido = 5;
							}
							else if (d == 2) {
								d_convertido = 10;
							}

							if (e == 0) {
								e_convertido = 0;
							}
							else if (e == 1) {
								e_convertido = 5;
							}
							else if (e == 2) {
								e_convertido = 10;
							}
							
							//Calculo da recomendacao
							float recomendacao = ((peso_porcentagem_assistida * a_convertido) + (peso_avaliacao * b_convertido) + (peso_comentarios * c_convertido) + (peso_tempo_de_video * d_convertido) + (peso_visualizacoes * e_convertido)) / 10;
							string recomendacao_final = "";

							cout << to_string(recomendacao) + "\n";

							if (recomendacao < 2) {
								recomendacao_final = "pessima";
							}
							else if (recomendacao >= 2 && recomendacao < 4) {
								recomendacao_final = "ruim";
							}
							else if (recomendacao >= 4 && recomendacao < 6) {
								recomendacao_final = "media";
							}
							else if (recomendacao >= 6 && recomendacao < 8) {
								recomendacao_final = "boa";
							}
							else if (recomendacao >= 8) {
								recomendacao_final = "otima";
							}

							string texto = "RULE " + to_string(rule) + " : IF porcentagem_assistida IS " + porcentagem_assistida[a]
								+ " AND avaliacao IS " + avaliacao[b]
								+ " AND comentarios IS " + comentarios[c]
								+ " AND tempo_de_video IS " + tempo_de_video[d]
								+ " AND visualizacoes IS " + visualizacoes[e]
								+ " THEN recomendacao IS " + recomendacao_final + ";\n";
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