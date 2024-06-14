//Eric Akio Uchiyamada    TIA: 42107865

#include <iostream>
#include <sstream>
#include <string>

#include "canvas.h"
#include "utils.h"

int GetIntFromString(const std::string &str);
void UpdateCanvas(const Canvas &canvas);

int GetIntFromString(const std::string &str) { //transformar string em inteiro
  try {
    return std::stoi(str);
  } catch (...) {
    return -1;
  }
}

void UpdateCanvas(const Canvas &canvas) {
  ClearScreen();
  std::cout << canvas; // PrintCanvas(canvas);
}

int main() 
{
  Canvas canvas;
  SetupCanvas(canvas);
  ClearCanvas(canvas);
  Queue queue = Create(); //criar a fila
  Coord coor; //coordenada
  int x,y,numero;
  std::string string_x,string_y,string_coor,saida;
  Return retorno;

  std::string input = "";
  int option = -1;

  do {
    UpdateCanvas(canvas);

    std::cout << "\n\n*** OPCOES ***\n"//menu de opções
              << "1 - Alterar uma coordenada.\n"
              << "2 - Executar sequencia de comandos.\n"
              << "3 - Salvar comandos em um arquivo.\n"
              << "4 - Carregar comandos de um arquivo.\n"
              << "5 - Encerrar programa.\n"
              << "Opcao: ";

    std::getline(std::cin, input);

    option = GetIntFromString(input);
    switch (option) {
    case 1: //"Alternar uma coordenada"
      std::cout << "Digite uma coordenada X para alterar: " << std::endl;
      std::cin >> x; //receber a coordenada x
      coor.x = x;

      std::cout << "Digite uma coordenada Y para alterar: " << std::endl;
      std::cin >> y;//receber a coordenada y
      coor.y = y;

      if(!Enqueue(queue,coor)) //inserir na fila
      {
        std::cout << "*** ERRO: canvas está cheio!\n\n";
        Pause();//encerrar se a fila estiver cheia
        break;
      }
      else
      {
        ToggleCanvas(canvas, coor);//alterar a coordenada no canvas
        Pause();
        break;
      }    
    case 2://"Executar sequência de comandos"
      ClearScreen();//reiniciar o canvas vazio
      ClearCanvas(canvas);
      PrintCanvas(canvas);
      Pause();
      while(queue.count != 0)//imprimir cada alteração do canvas 
      {
        ClearScreen();
        Return coordenadas;
        coordenadas = Front(queue);//receber a coordenada na fila
        ToggleCanvas(canvas, coordenadas.valor);//alterar o canvas
        Dequeue(queue);//retirar a coordenada da fila
        PrintCanvas(canvas);
        Pause();
      }     
      break;

    case 3://"Salvar comandos em um arquivo"
      WriteStringToFile("arquivo.txt", queue);//função para escrever a fila no arquivo
      ClearScreen();  //reiniciar o canvas vazio
      ClearCanvas(canvas);
      PrintCanvas(canvas);
      Pause();
      break;

    case 4://"Carregar comandos de um arquivo"
      bool is_ok;
      saida = ReadFileAsString("arquivo.txt", is_ok);//ler o arquivo
      if(is_ok)
      { 
        ClearScreen();//reiniciar o canvas
        ClearCanvas(canvas);
        Pause();
        for(int j = 0;j < saida.length();j++)//ler 2 caracteres a convertê-los em inteiros
        {
          std::string aux1,aux2;
          if(saida[j] == '\n') 
            break;
          aux1 = saida[j];//primeiro caractere
          coor.x = GetIntFromString(aux1);
          j += 1;
          aux2 = saida[j];//segundo caractere
          coor.y = GetIntFromString(aux2);
          Enqueue(queue,coor);//inserir a coordenada na fila
          ToggleCanvas(canvas, coor);//alterar a coordenada no canvas
        }        
        PrintCanvas(canvas);
      }
      Pause();
      break;

    case 5://encerrar o programa
      std::cout << "Fim.\n\n";
      break;

    default:
      std::cout << "*** ERRO: Opcao invalida!\n\n";
      Pause();
    }
    

  } while (option != 5);
}
