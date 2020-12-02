typedef struct lista Lista;
typedef struct aluno{
	char nome[30];
	int matricula;
}aluno;

Lista * lista_cria ();
void lista_libera (Lista * p);
int lista_insere_inicio (Lista * p, aluno elemento);
int lista_insere_final (Lista * p, aluno elemento);
int lista_insere_posicao (Lista * p, aluno elemento, int posicao);
int lista_remove_inicio (Lista * p);
int lista_remove_final  (Lista * p);
int lista_remove_posicao (Lista * p, int posicao);
aluno lista_obtem_elemento  (Lista * p, int posicao); /* retorna elemento em uma posicao */
int lista_se_presente  (Lista * p, aluno elemento); /* retorna posicao do elemento, ou zero se ausente */
int lista_obtem_tamanho  (Lista * p);
void lista_imprime  (Lista * p);
void lista_ordena (Lista * p);
