#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaUni.h"

struct elemento{
	aluno elemento;
	struct elemento * proximo;
};
struct lista {
	struct elemento * cabeca;
	int tamanho;
};

Lista * lista_cria () {
	Lista * q = (Lista *) malloc(sizeof(Lista));
	if (q!=NULL) {
		q->cabeca = NULL;
		q->tamanho = 0;
	}
	return q;
}

void lista_libera (Lista * p) {
	struct elemento * q = p->cabeca;
	while (q != NULL) {
		struct elemento * aux = q->proximo;
		free(q);
		q = aux;
	}
	free(p);
}

int lista_insere_inicio (Lista * p,aluno elemento) {
	struct elemento * q = malloc(sizeof(struct elemento));
	if (q!=NULL) {
		strcpy(q->elemento.nome, elemento.nome);
		q->elemento.matricula = elemento.matricula;
		q->proximo  = p->cabeca;
		p->cabeca   = q;
		p->tamanho  = p->tamanho + 1;
		return 1; // insercao com sucesso
	}
	return 0; // erro na insercao
}

int lista_insere_final (Lista * p, aluno elemento){
	struct elemento * q = malloc(sizeof(elemento));
	strcpy(q->elemento.nome, elemento.nome);
	q->elemento.matricula = elemento.matricula;
	q->proximo = NULL;
	if (p->tamanho == 0)
		p->cabeca = q;
	else {
		struct elemento * aux = p->cabeca;
		while (aux->proximo != NULL)
			aux = aux->proximo;
		aux->proximo = q;
	}
	p->tamanho = p->tamanho+1;	
	return 1; // insercao com sucesso	
}

int lista_insere_posicao (Lista * p, aluno elemento, int posicao) {
	if (posicao < 1)
		return 0; // insercao sem sucesso, alem do inicio da lista
	if (posicao > p->tamanho+1)
		return 0; // insercao sem sucesso, alem do final da lista
	struct elemento * q = malloc(sizeof(struct elemento));
	strcpy(q->elemento.nome, elemento.nome);
	q->elemento.matricula = elemento.matricula;
	if (posicao == 1) {
		if (p->tamanho == 0)
			q->proximo = NULL;
		else
			q->proximo = p->cabeca;
			p->cabeca = q;
	} else {
		struct elemento * aux = p->cabeca;
		while (posicao>2) {
			aux = aux->proximo;
			posicao--;
		}
		q->proximo = aux->proximo;
		aux->proximo = q;
	}
	p->tamanho = p->tamanho+1;	
	return 1; // inserção com sucesso
}

int lista_remove_inicio (Lista * p) {
	struct elemento * q = p->cabeca;
	p->cabeca = p->cabeca->proximo;
	free(q);
	p->tamanho = p->tamanho-1;
	return 0;
}

int lista_remove_final  (Lista * p) {
	int i;
	struct elemento * q = p->cabeca->proximo;
	struct elemento * aux;
	for(i=1;i<p->tamanho-1;i++){
		q=q->proximo;
	}
	aux = q->proximo;
	q->proximo = NULL;
	free(aux);
	p->tamanho = p->tamanho-1;
	return 0;
}

int lista_remove_posicao (Lista * p, int posicao) {
	struct elemento * aux = p->cabeca;
	struct elemento * temp;
	for(int i = 1; i<posicao-1;i++)
		aux = aux->proximo;
	temp = aux->proximo;
	aux->proximo = temp->proximo;
	free(temp);
	p->tamanho=p->tamanho-1;
	return 0;
}

aluno lista_obtem_elemento  (Lista * p, int posicao) {
	aluno a;
	a.matricula = 0;
	if ((posicao<1)||(posicao>p->tamanho))
		return a;
	struct elemento * q = p->cabeca;
	int i;
	for (i=0; i<posicao-1; i++)
		q = q->proximo;
	return q->elemento;
}

int lista_se_presente  (Lista * p, aluno elemento) {
	int i;
	aluno aux;
	for(i=0;i<p->tamanho+1;i++){
		aux = lista_obtem_elemento(p,i);
		if(aux.matricula == elemento.matricula){
			return i;
		}
	}
	return 0; // elemento ausente
}

int lista_obtem_tamanho  (Lista * p) {
	return p->tamanho;
}

void lista_imprime  (Lista * p){
	struct elemento * q = p->cabeca;
	int i;
	for (i=0; i < p->tamanho; i++) {
		printf("Matricula:%d Aluno(a):%s\n", q->elemento.matricula, q->elemento.nome);
		q = q->proximo;
	}
}

int main(){

	return 0;
}