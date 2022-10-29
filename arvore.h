struct No{
	/*parte de informa��o
	 a ser armazenada*/
	int valor;

	struct No* esq;
	struct No* dir;
};

struct No* raiz = NULL;

//percurso em pr�- ordem :
//1-imprime Raiz-
//2-Navega para esq-
//3-Navega para direita
void preOrdem(struct No* raiz){

	//Passo 1
	if(raiz!=NULL){

		printf("%d\n", raiz->valor);

		//Passo 2
		preOrdem(raiz->esq);

		//Passo 3
		preOrdem(raiz->dir);
	}
}

//percurso em in- ordem :
//1-Navega para esq-
//2-imprime Raiz-
//3-Navega para direita
void inOrdem(struct No* raiz){

	//Passo 1
	if(raiz!=NULL){

		//Passo 1
		if(raiz->esq != NULL)
			inOrdem(raiz->esq);

		//Passo 2
		printf("%d\n", raiz->valor);

		//Passo 3
		if (raiz->dir != NULL)
			inOrdem(raiz->dir);
	}
}

//percurso em pos- ordem :
//1-Navega para esq-
//2-Navega para direita
//3-imprime Raiz
void posOrdem(struct No* raiz){

	//Passo 1
	if(raiz!=NULL){

		//Passo 1
		posOrdem(raiz->esq);

		//Passo 2
		inOrdem(raiz->dir);

		//Passo 3
		printf("%d\n", raiz->valor);
	}
}

 void insereArvoreDeBusca(int valor, struct No** raiz) {
 	//novo ter que ser raiz, se a arvore estiver vazia
 	if((*raiz) == NULL){

	 	//alocar o no para o valor
 		struct No* novo = (struct No*) malloc(sizeof(struct No));
 		novo->valor=valor;
 		novo->esq=NULL;
 		novo->dir=NULL;

 		(*raiz)=novo;
	}
	//sen�o, deve chamar a fun��o recursivamente para a direita
    //ou para a esquerda, comparando o valor com o que
    //estiver guardado na raiz.
    else if(valor > (*raiz)->valor){
    	insereArvoreDeBusca(valor, &((*raiz)->dir));
	}
	else{
		insereArvoreDeBusca(valor, &((*raiz)->esq));
	}
 }

 void buscaArvoreBusca(int valor, struct No* raiz){

 	if(raiz != NULL){
 		if(valor < raiz->valor){
 			buscaArvoreBusca(valor,raiz->esq);
		}
		if(valor > raiz->valor){
			buscaArvoreBusca(valor,raiz->dir);
		}
		if(valor == raiz->valor){
		 	printf("O valor %d se encontra na arvore!", raiz->valor);
		}
	}else{
		printf("Raiz n�o encontrada!");
	}
 }

 void imprimeDecrescente(struct No* raiz){

	//Passo 1
	if(raiz!=NULL){

		//Passo 1
		imprimeDecrescente(raiz->dir);

		//Passo 2
		printf("%d\n", raiz->valor);

		//Passo 3
		imprimeDecrescente(raiz->esq);
	}
}

int somaArvore(struct No* raiz){
	int resultado = 0;

	if(raiz!=NULL){

		resultado = resultado + somaArvore(raiz->esq);

		resultado = resultado + raiz->valor;

		resultado = resultado + somaArvore(raiz->dir);

	}
	return resultado;

}

int contaArvore(struct No* raiz){
	int cont = 0;

		if(raiz!=NULL){
		cont = cont + contaArvore(raiz->esq);

		cont = cont + 1;

		cont = cont + contaArvore(raiz->dir);
	}
	return cont;
}

void maiorElemento(struct No* raiz){
	if(raiz!=NULL){
		if(raiz->dir == NULL){
			printf("O maior elemento �: %d\n", raiz->valor);
		}else // continuar a busca pelo mauir, se a raiz tiver filho
			maiorElemento(raiz->dir);

	}


}

void menorElemento(struct No* raiz){
	if(raiz!=NULL){
		if(raiz->esq == NULL){
			printf("O menor elemento �: %d\n", raiz->valor);
		}else // continuar a busca pelo mauir, se a raiz tiver filho
			maiorElemento(raiz->esq);

	}
}

/*@input raiz da arvore ou da sub�rvore / @output: null, caso n�o haja antecessor
	ou n� que aponta para o npo que armazena
	o valor que antecede o valor de armazenamento na raiz*/

/* CORRE��O DA CRIS */
struct No* antecessor(struct No* raiz){

	//o n� antecessor � aqueLe que est� mais � direita do ramo da esquerda
	struct No *antecede = NULL;

	//Passo 1: avaliar se h� antecessor
	if(raiz->esq != NULL){

		//prov�vel antecessor, se n�o tiver filho a direita
		antecede = raiz->esq;

		//Passo 2 procurar o filho mais a direita
		while(antecede->dir != NULL){
			antecede = antecede->dir;
		}
		return antecede;
	}
	return NULL; //caso do if no->esq falhar, ou seja n�o h� antecessor
}


/*@input raiz da arvore ou da sub�rvore / @output: null, caso n�o haja sucessor
	ou n� que aponta para o npo que armazena
	o valor que sucede o valor de armazenamento na raiz*/

/* CORRE��O DA CRIS */
struct No* sucessor(struct No* raiz){

	//o n� sucessor � aqueLe que est� mais � esquerda do ramo da direita
	struct No *sucede = NULL;

	//Passo 1: avaliar se h� antecessor
	if(raiz->dir != NULL){

		//prov�vel sucessor, se n�o tiver filho a direita
		sucede = raiz->dir;

		//Passo 2 procurar o filho mais a esquerda
		while(sucede->esq != NULL){
			sucede = sucede->esq;
		}
		return sucede;
	}
	return NULL; //caso do if no->dir falhar, ou seja n�o h� sucessor
}

/*fun��o que dadi um valor numperico, retorna o n� que o cont�m
@input: numero a ser procurado e a raiz da �rvore ou da sub�rvore
@output: null, se a busca falhar ou o n� aponta para o valor na �rvore*/
struct No *busca(struct No* raiz,int numero){

	struct No* resp = NULL;

	//falha se a �rvore ou sub�rvore for vazia
	if(raiz == NULL)
		return NULL;

	//Procurar na raiz o n�mero
	if(raiz->valor == numero){
		return raiz;
	}

	//Procurar no n� a esquerda
	resp = busca(raiz->esq, numero);

	//se n�o tiver a esquerda, procurar a direita
	if(resp == NULL){
		return busca(raiz->dir, numero);
	}

	return resp;
}

struct No **encontraPai(struct No *r, struct No *filho){
	struct No **pai = calloc(1, sizeof(struct No *));
	*pai = r;
	while((*pai)->dir || (*pai)->esq) {
		if(filho->valor < (*pai)->valor) {
			*pai = (*pai)->esq;
		}
		else if(filho->valor > (*pai)->valor) {
			*pai = (*pai)->dir;
		}
		if((*pai)->esq == filho || (*pai)->dir == filho)
			return pai;
	}
	return NULL;
}

// remove um n� da �rvore bin�ria de busca, priorizando, desde que ele seja folha
void removeFolha(struct No** r){
	//admitindo que o n� seja de fato folha
	free(*r);
	*r = NULL;
}


//remove um n� que n�o seja folha, captando o valor do antecessor
void removePorCopia(struct No** raiz){
	struct No *aux = (struct No *) calloc(1, sizeof(struct No));

	//Passo 1: verificar se a raiz tem antecessor - chamar a antecessor
	aux = antecessor(*raiz);
	if(aux != NULL){
		//Passo 1.1: caso tenha, colocar na raiz, o valor do antecessor
		//trocar o valor da raiz pelo que est� no antecessor
		(*raiz)->valor = aux->valor;
		//Passo 1.1.1: verificar se o antecessor � um n� folha
		if(aux->dir==NULL && aux->esq==NULL){
			//Caso seja, chamar a funcao removeFolha e encerrar a fun��o
			removeFolha(&aux);
		}else{
			//Caso n�o seja, chamar a fun��o removePorCopia recursivamente, passando o n� antecessor
			removePorCopia(&aux);
		}
	}else{
		//Passo 1.2: caso n�o tenha antecessor, chame a fun��o para sucessor da raiz
		aux = sucessor(*raiz);
		//Passo 1.2.1: verificar se o sucessor existe e � folha
		if(aux != NULL){
			int valor = aux->valor;
			if(aux->dir==NULL && aux->esq==NULL){
				//Caso seja, chamar a funcao removeFolha e encerrar a fun��o
				removeFolha(&aux);
			}else{
				//Caso n�o seja, chamar a fun��o remoPorCopia recursivamente, passando o n� sucessor
				removePorCopia(&aux);
			}
		}
	}
	free(aux);
}
