#include <iostream>
#include <fstream>
#include <list>
#include "BackPackFactory.hpp"
#include "BackPackBTFactory.hpp"
#include "BackPackBBFactory.hpp"
#include "Item.hpp"

int main(int argc, char *argv[]){

	if(argc > 1){
		std::string entrada = argv[1];
		std::ifstream arquivoEntrada;
		arquivoEntrada.open(entrada, std::ios::in);

		if(arquivoEntrada.is_open()){
			std::list<BackPackProblem::Item> items;
			int n = 0;
			float wMax = 0.0;
			arquivoEntrada >> n >> wMax;
			for(int i = 0; i<n;i++){
				float valor = 0.0;
				float peso = 0.0;
				arquivoEntrada >> valor >> peso;
				BackPackProblem::Item novoItem(valor,peso);
				items.push_back(novoItem);
			}

			for(int i = 0; i<2;i++){
				BackPackProblem::BackPackFactory* fabricaMochila = nullptr;
				BackPackProblem::BackPack* mochila = nullptr;
				std::string saida = "";
				std::ofstream arquivoSaida;

				if(i==0){
					fabricaMochila = new BackPackProblem::BackPackBTFactory();
					mochila = fabricaMochila->createBackPack();
					mochila->setMaxWeigth(wMax);
					saida = "saidaBackTracking.txt";
				}else{
					fabricaMochila = new BackPackProblem::BackPackBBFactory();
					mochila = fabricaMochila->createBackPack();
					mochila->setMaxWeigth(wMax);
					saida = "saidaBranchAndBound.txt";
				}

				arquivoSaida.open(saida, std::ios::app);
				if(arquivoSaida.is_open()){
					mochila->setItems(items);
					float resultado = mochila->solve();

					arquivoSaida<<entrada<<";"<<"DanielSouzaDeCampos;tempo;"<<resultado<<"\n"<<std::endl;

					arquivoSaida.close();
					delete mochila;
					delete fabricaMochila;
				}else{
					std::cout<<"Nao foi possivel abrir o arquivo de saida!";
					return -1;
				}
			}
			arquivoEntrada.close();
		}else{
			std::cout<<"Nao foi possivel abrir o arquivo. Confira o endereco e nome do arquivo!";
			return -1;
		}	
	}else{
		std::cout<<"Informe o endereco do arquivo de teste!";
		return -1;
	}
	return 0;
}