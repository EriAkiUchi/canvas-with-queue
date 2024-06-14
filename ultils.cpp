//Eric Akio Uchiyamada    TIA: 42107865

#include <iostream>
#include <fstream>
#include <sstream>
#include "utils.h"
#include "canvas.h"

void ClearScreen()//limpar a tela
{
#if _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

std::string __pause_hack__;
void Pause(const std::string& message)//pausar o programa
{
	std::cout << message;
	std::getline(std::cin, __pause_hack__);
}

// WriteStringToFile()
// Tenta abrir o arquivo indicado no parâmetro filename e, em caso positivo,
// salva o conteúdo da string contents no arquivo.
// 
// Retorno:
// - true, se foi possível salvar a string no arquivo.
// - false, caso contrário.
//
// Exemplo de uso:
// bool isOK = WriteStringToFile("arquivo.txt", "Hello, World!");
// if (isOK) std::cout << "String gravada no arquivo.";
// else std::cout << "Erro ao gravar string no arquivo.";
bool WriteStringToFile(const std::string& filename, Queue& queue)//escrever a fila no arquivo como string
{
	std::ofstream ofs;
  std::string string_x,string_y,string_coor;
  Coord coor;


	try
	{
		ofs.open(filename);
		if (ofs.is_open())
		{
			// Salva o conteúdo da string contents no arquivo.
       while(queue.count != 0)
      { 
        Return coordenadas;
        coordenadas = Front(queue);
        string_x = std::to_string(coordenadas.valor.x);
        string_y = std::to_string(coordenadas.valor.y);
        Dequeue(queue);
        string_coor = string_x + string_y;
        ofs << string_coor;
        
      }  
			ofs << '\n';
      
        
			ofs.close();
			return true;
		}
	}
	catch (...)
	{
	}

	return false;
}

// ReadFileAsString()
// Tenta abrir o arquivo indicado no parâmetro filename e, em caso positivo,
// monta uma string com todo o conteúdo do arquivo separado por quebra de linha.
//
// Retorno:
// - Caso o arquivo seja lido com sucesso, retorna a string que contém o
// conteúdo do arquivo e o parâmetro de saída out_isOK sai da função com o valor
// true.
// - Caso não seja possível ler o arquivo, retorna uma string vazia e o
// parâmetro de saída out_isOK sai da função com o valor false.
//
// Exemplo de uso:
// bool isOK = false;
// std::string contents = ReadFileAsString("arquivo.txt", isOK);
// if (isOK) std::cout << contents;
std::string ReadFileAsString(const std::string& filename, bool& out_isOK)//ler o arquivo
{
	std::ifstream ifs;

	try
	{
		ifs.open(filename);
		if (ifs.is_open())
		{
			std::ostringstream oss;
			std::string str;

			// Cada string separada por espaço em branco ou quebra de linha
			// é copiada na string str.
			while (ifs >> str)
			{
				// Monta uma única string contendo todas as strings
				// separadas por quebra de linha.
				oss << str << '\n';
			}

			ifs.close();

			out_isOK = true;
			return oss.str();
		}
	}
	catch (...)
	{
	}

	out_isOK = false;
	return "";
}
