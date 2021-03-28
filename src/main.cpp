#include <iostream>
#include <fstream>
#include <vector>
#include "BackPackFactory.hpp"
#include "BackPackBTFactory.hpp"
#include "BackPackBBFactory.hpp"
#include "Item.hpp"
#include <chrono>

int main(int argc, char *argv[]){

	if(argc > 1){
		std::string entrada = "";
		std::ofstream arquivoSaidaBT;
		arquivoSaidaBT.open("saidaBackTracking.csv", std::ios::app);
		std::ofstream arquivoSaidaBB;
		arquivoSaidaBB.open("saidaBranchAndBound.csv", std::ios::app);

			for(int i=1;i<argc;i++){
				entrada = argv[i];
				std::ifstream arquivoEntrada;
				arquivoEntrada.open(entrada, std::ios::in);

				if(arquivoEntrada.is_open() && arquivoSaidaBB.is_open() && arquivoSaidaBT.is_open()){
					std::vector<BackPackProblem::Item> items;
					int n = 0;
					float wMax = 0.0;
					arquivoEntrada >> n >> wMax;
					for(int i = 0; i<n;i++){
						float valor = 0.0;
						float peso = 0.0;
						arquivoEntrada >> valor >> peso;
						BackPackProblem::Item novoItem(peso,valor);
						items.push_back(novoItem);
					}

					for(int i = 0; i<2;i++){
						BackPackProblem::BackPackFactory* fabricaMochila = nullptr;
						BackPackProblem::BackPack* mochila = nullptr;

						auto start = std::chrono::high_resolution_clock::now();
				
						if(i==0){
							fabricaMochila = new BackPackProblem::BackPackBTFactory();
							mochila = fabricaMochila->createBackPack();
							mochila->setMaxWeigth(wMax);
						}else{
							fabricaMochila = new BackPackProblem::BackPackBBFactory();
							mochila = fabricaMochila->createBackPack();
							mochila->setMaxWeigth(wMax);
						}
						auto stop = std::chrono::high_resolution_clock::now();
						std::chrono::duration<float> duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

						mochila->setItems(items);
						float resultado = mochila->solve();
						if(i==0){
							arquivoSaidaBT<<entrada<<";DanielSouzaDeCampos;"<<duration.count()<<";"<<resultado<<std::endl;
						}else{
							arquivoSaidaBB<<entrada<<";DanielSouzaDeCampos;"<<duration.count()<<";"<<resultado<<std::endl;
						}
						delete mochila;
						delete fabricaMochila;
						
					}

				}else{
					std::cout<<"Nao foi possivel abrir o arquivo. Confira o endereco e nome do arquivo!";
					return -1;
				}	
			arquivoEntrada.close();
		}
		arquivoSaidaBT.close();
		arquivoSaidaBB.close();
	}else{
		std::cout<<"Informe o endereco do arquivo de teste!";
		return -1;
	}
	std::cout<<"Foram gerados dois arquivos com as respostas para cada algoritmo!"<<std::endl;
	return 0;
}