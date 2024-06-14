//Eric Akio Uchiyamada    TIA: 42107865

#ifndef __CANVAS_H__
#define __CANVAS_H__

const int CANVAS_ROWS = 8;
const int CANVAS_COLS = 8;
const int TAMANHO_MAXIMO = 64;
struct Canvas//struct canvas
{
	bool data[CANVAS_ROWS][CANVAS_COLS];
	char on;
	char off;
};
struct Coord{//coordenada
  int x;
  int y;
};
struct Queue//fila
{
  Coord coor[TAMANHO_MAXIMO];
  int start;
  int end;
  int count;
};
struct Return//Retorno para funções Dequeue e Front
{
  Coord valor;
  int code;
};

void SetupCanvas(Canvas& canvas, 
#if _WIN32
	char on = (char)219,
	char off = (char)176
#else
	char on = '#',
	char off = '.'
#endif
);//canvas terá '#' como valor true e '.' como valor false
Queue Create();//criar fila
bool Enqueue(Queue& queue, Coord coor);//inserir elemento na fila
Return Dequeue(Queue& queue);//remover elemento na fila
Return Front(const Queue& queue);//apresentar o primeiro elemento da fila sem removê-lo
bool Full(const Queue& queue);//verificador se a fila está cheia
bool Empty(const Queue& queue);//verificador se a fila está vazia
void PrintQueue(Queue& queue);//imprimir a fila

void ClearCanvas(Canvas& canvas);//reiniciar o canvas como vazio
void ToggleCanvas(Canvas& canvas, Coord coor);//alterar coordenada no canvas
void PrintCanvas(const Canvas& canvas);//imprimir o canvas

std::ostream& operator<<(std::ostream& os, const Canvas& canvas);

#endif
