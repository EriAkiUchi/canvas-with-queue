# Canvas com Fila
Trabalho de Estruturas de Dados utilizando **Fila**.  
Este trabalho consiste em preencher uma dada coordenada do Canvas a partir da coordenada oferecida pelo usuário ou por um arquivo.  
O Canvas é organizado em uma estrutura 2D com coordenadas de 0 a 7.  
O _main.exe_ possui o menu do programa.
# Operações do programa
### Alterar uma coordenada
Esta operação consiste em **preencher** uma coordenada ou **descolorir** uma coordenada já preenchida.  
Só são aceitos dígitos de 0 até 7.  
Cada coordenada inserida é armazenada em uma Fila para as outras operações do programa.  
***
### Executar sequência da comandos
Esta opção realiza todas as mundaças feitas no Canvas utilizando a Fila com as coordenadas que foram inseridas.  
O programa reinicia o canvas e muda uma coordenada por vez. Cada vez que uma coordenada é alterada, a Fila diminui de tamanho. Portanto, esta operação **esvazia** a Fila.  
***
### Salvar comandos em um arquivo
Esta operação consiste em salvar as coordenadas da Fila em um arquivo _txt_.  
O canvas é reiniciado quando esta operação termina.  
Selecionar esta operação mais de uma vez **sobrescreve** qualquer conteúdo do arquivo que já estava armazenado.  
***
### Carregar comandos de um arquivo
Esta operação consiste em realizar a leitura do arquivo com as coordenadas.  
Após ler o arquivo, o canvas é preenchido com as coordenadas alteradas e a elas são inseridas na Fila.  
# Execução
1. Tenha um compilador de C++ instalado. Caso não tenha, siga as instruções da página do VS Code: [Using GCC with MinGW](https://code.visualstudio.com/docs/cpp/config-mingw).
2. Clone o repositório.
3. Execute o programa com o comando: _.\main.exe_.
4. Caso o executável não esteja disponível, basta compilar os arquivos. Comando: _g++ main.cpp utils.cpp canvas.cpp -o main.exe_.
