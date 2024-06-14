//Eric Akio Uchiyamada    TIA: 42107865

#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include "canvas.h"

void ClearScreen();//limpar a tela
void Pause(const std::string& message = "Pressione ENTER para continuar...");//pausar o programa

bool WriteStringToFile(const std::string& filename, Queue& queue);//escrever no arquivo a fila
std::string ReadFileAsString(const std::string& filename, bool& isOK);//ler o programa

#endif
