//Eric Akio Uchiyamada    TIA: 42107865

#include <iostream>
#include "canvas.h"

Queue Create()//criar fila vazia
{
  Queue queue;
  queue.start = queue.end = queue.count = 0;
  for(int i = 0;i < TAMANHO_MAXIMO;i++)
    queue.coor[i] = {-1,-1};
  return queue;
}
bool Enqueue(Queue& queue,Coord coor)//inserir elemento na fila
{
  if(Full(queue))
    return false;
  queue.coor[queue.end] = coor;
  queue.end = (queue.end + 1) % TAMANHO_MAXIMO;
  queue.count++;
  return true;
}

Return Dequeue(Queue& queue)//remover elemento da fila
{
  Coord coordenada;
  Return retorno;
  if(Empty(queue))
  { 
    retorno.valor = {-1,-1};
    retorno.code = -1;
  }
  else
  {  
    retorno.code = 0;
    retorno.valor = queue.coor[queue.start];

    queue.coor[queue.start] = coordenada;
    queue.start = (queue.start + 1) % TAMANHO_MAXIMO;
    queue.count--;
  }
  return retorno;
}
Return Front(const Queue& queue)//apresentar o primeiro elemento sem retirá-lo
{
  Return retorno = {0,-1};
  if(!Empty(queue))
  {
    retorno.code = 0;
    retorno.valor = queue.coor[queue.start];
  }
  return retorno;
}
bool Full(const Queue& queue)//verificador se a fila está cheia
{
  return queue.count == TAMANHO_MAXIMO;
}
bool Empty(const Queue& queue)//verificador se a fila está vazia
{
  return queue.count == 0;
}

void PrintQueue(Queue& queue)//imprimir a fila
{  
  Coord coor;
  for(int i = 0;i < queue.count;i++)
    std::cout << '(' << coor.x << ',' << coor.y << ')' << std::endl;
}
void SetupCanvas(Canvas& canvas, char on, char off)//caractere para true será '#' e para false será '.'
{
    canvas.on = on;
    canvas.off = off;
}

void ClearCanvas(Canvas& canvas)//reiniciar o canvas para vazio
{
    for (int row = 0; row < CANVAS_ROWS; ++row)
        for (int col = 0; col < CANVAS_COLS; ++col)
            canvas.data[row][col] = false;
}

void ToggleCanvas(Canvas& canvas, Coord coor)//alterar a coordenada no canvas
{
    canvas.data[coor.x][coor.y] = !canvas.data[coor.x][coor.y];
}

void PrintCanvas(const Canvas& canvas)//imprimir o canvas
{
    std::cout << "  ";
    for (int col = 0; col < CANVAS_COLS; ++col)
        std::cout << col;
    std::cout << '\n';

    for (int row = 0; row < CANVAS_ROWS; ++row)
    {
        std::cout << row << ' ';
        for (int col = 0; col < CANVAS_COLS; ++col)
            std::cout << (canvas.data[row][col] ? canvas.on : canvas.off);
        std::cout << ' ' << row << '\n';
    }

    std::cout << "  ";
    for (int col = 0; col < CANVAS_COLS; ++col)
        std::cout << col;
    std::cout << '\n';
}

// Essa funÃ§Ã£o sobrecarrega (overload) o operador << que Ã© usado em instruÃ§Ãµes
// como std::cout, std::ofstream e std::ostringstream.
// Observe que, diferente da PrintCanvas(), essa funÃ§Ã£o nÃ£o faz nenhuma
// referÃªncia a std::cout.
// O cÃ³digo dessa funÃ§Ã£o Ã© executado, por exemplo, se uma variÃ¡vel do tipo
// Canvas Ã© passada para std::cout, sendo que o parÃ¢metro std::ostream& os se
// torna std::cout, nesse caso.
std::ostream& operator<<(std::ostream& os, const Canvas& canvas)
{
    os << "  ";
    for (int col = 0; col < CANVAS_COLS; ++col)
        os << col;
    os << '\n';

    for (int row = 0; row < CANVAS_ROWS; ++row)
    {
        os << row << ' ';
        for (int col = 0; col < CANVAS_COLS; ++col)
            os << (canvas.data[row][col] ? canvas.on : canvas.off);
        os << ' ' << row << '\n';
    }

    os << "  ";
    for (int col = 0; col < CANVAS_COLS; ++col)
        os << col;
    os << '\n';

    return os;
}
