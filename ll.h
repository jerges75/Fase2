typedef struct sListElem {
	void* data;
	struct sListElem* next;
} *ListElem, SListElem;

typedef struct meio
{

	char tipo[50]; 
	char geo[50]; 
	int identificador; 
	int bateria; 
	int aluguer;
	int vertice;
	float autonomia;
	float custo;
	struct meio* seguinte;

}*Mobilidade;

typedef struct clientes
{

	char nome[50]; 
	char passe[10];
	char nif[10];
	char morada[50]; 
	char email[50]; 
	int id;
	float saldo; 

}*Dados;

typedef struct gestor
{

	char nome[50]; 
	char passe[10];
	char nif[10];
	char morada[50]; 
	char email[50]; 
	int validacoes;
	int estatísticas;
	int id;
	int historico; 	float saldo; 

}*Dados1;

typedef struct registo
{

	char geocodigo[50];
	int id; 
	float peso; 
	struct registo* seguinte;

} Lista, * Adjacentes;


ListElem addItemHead(ListElem head, void* data);

void showListIterative(ListElem head, void (*show)(void* data));

ListElem addItemLastIterative(ListElem head, void* data);

ListElem addItemOrderedIterative(ListElem head, void* data, int (*compare)(void* data1, void* data2));

ListElem removeItemIterative(ListElem head, void* data, int (*compare)(void* data1, void* data2));

int listLength(ListElem head);

ListElem deleteList(ListElem head);

ListElem obtainElementPosition(ListElem head, int pos);

ListElem obtainElement(ListElem head, void* data, int (*compare)(void* data1, void* data2));