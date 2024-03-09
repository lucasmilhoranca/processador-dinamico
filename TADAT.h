struct TpDado //Dados do arquivo txt
{
	int Processador,ut;
	char Nome[40],Tipo[40];
};

struct TpFila //caixa da fila 
{										  
	TpDado Id;                              
	TpFila *ant,*prox;                     
};	

struct TpProcessador//descritor de cada processador
{
	TpFila *Inicio, *Fim;
	TpProcessador *prox;
	int Qtde, IdProcessador;
	int contGI, contGE, contDel, contLer, contImp;
};

struct TpDescritor//descritor geral
{
	TpProcessador *Inicio, *Fim;
};

/*void Inicializar(TpDescritor &Descr);//finalizada || falta conferir
int Prioridade(TpFila F);//finalizada
void Inserir(TpDescritor &Descr, TpDado Elem);//finalizada
TpDado Remover(TpDescritor &Descr,int Id);//pendente
int Vazia(TpDescritor Descr);//finalizada
TpDado ElementoInicio(TpDescritor Descr);//finalizada
TpDado ElementoFim(TpDescritor Descr);//finalizada*/

void Inicializar(TpDescritor &Descr)
{
	TpProcessador *P1 = new TpProcessador;
	TpProcessador *P2 = new TpProcessador;
	TpProcessador *P3 = new TpProcessador;
	TpProcessador *P4 = new TpProcessador;
	
	P1->Inicio = P1->Fim = NULL;
	P2->Inicio = P2->Fim = NULL;
	P3->Inicio = P3->Fim = NULL;
	P4->Inicio = P4->Fim = NULL;
	
	P1->IdProcessador=1; P2->IdProcessador=2;
	P3->IdProcessador=3; P4->IdProcessador=4;
	P1->Qtde = P2->Qtde = P3->Qtde = P4->Qtde = 0;
	
	P1->contGI = P1->contGE = P1->contDel = P1->contLer = P1->contImp = 0;
	P2->contGI = P2->contGE = P2->contDel = P2->contLer = P2->contImp = 0;
	P3->contGI = P3->contGE = P3->contDel = P3->contLer = P3->contImp = 0;
	P4->contGI = P4->contGE = P4->contDel = P4->contLer = P4->contImp = 0;

	P4->prox = NULL; P3->prox = P4;
	P2->prox = P3; P1->prox = P2;
	
	Descr.Inicio = P1; Descr.Fim = 	P4;
	/*Inicio recebe P1 e Fim recebe P4, revisar para ver se da pra simplificar
	a funcao*/
}

int Prioridade(TpFila *F)
{
	if(strcmp(F->Id.Tipo,"Gravar Dispositivo Interno") == 0)
		return 1;
	if(strcmp(F->Id.Tipo,"Gravar Dispositivo Externo") == 0)
		return 2;
	if(strcmp(F->Id.Tipo,"Deletar") == 0)
		return 3;
	if(strcmp(F->Id.Tipo,"Ler") == 0)
		return 4;
	if(strcmp(F->Id.Tipo,"Imprimir") == 0)
		return 5;
}

int PrioridadeRemover(TpDado R)
{
	if(strcmp(R.Tipo,"Gravar Dispositivo Interno") == 0)
		return 1;
	if(strcmp(R.Tipo,"Gravar Dispositivo Externo") == 0)
		return 2;
	if(strcmp(R.Tipo,"Deletar") == 0)
		return 3;
	if(strcmp(R.Tipo,"Ler") == 0)
		return 4;
	if(strcmp(R.Tipo,"Imprimir") == 0)
		return 5;
}

void Inserir(TpDescritor &Descr, TpDado Elem, int &ut1, int &ut2, int &ut3, int &ut4)
{
	TpFila *Caixa = new TpFila;
	Caixa->ant = NULL;
	Caixa->prox = NULL;
	Caixa->Id = Elem;
	
	TpProcessador *P = Descr.Inicio;//acessando apenas o processador diretamente
	int AuxProc = Caixa->Id.Processador;
	
	while(P->IdProcessador != AuxProc)//procurando o processador certo
		P = P->prox;
	
		
	if(P->Inicio == NULL)//inserir no inicio
	{
		P->Inicio = P->Fim = Caixa;
		if(AuxProc==1)
			ut1 = Caixa->Id.ut;
		if(AuxProc==2)
			ut2 = Caixa->Id.ut;
		if(AuxProc==3)
			ut3 = Caixa->Id.ut;
		if(AuxProc==4)
			ut4 = Caixa->Id.ut;
	}
	else //inserir no final
	{
		Caixa->ant = P->Fim;
		P->Fim->prox = Caixa;
		P->Fim = Caixa;
		
		
		// ordenação
		TpDado Aux;
		TpFila *Atual,*Ant;
		
		
		Atual = P->Fim;
		Ant = Atual->ant;
		while(Ant->ant != NULL && Prioridade(Atual) < Prioridade(Ant))
		{
			Aux = Atual->Id;
			Atual->Id = Ant->Id;
			Ant->Id = Aux;
			
			Atual = Ant;
			Ant = Atual->ant;
		}
	}
	
}

void DescarregarFila(TpProcessador *P, FILE *PtrNovo)
{
    TpDado Aux;
    TpFila *F = P->Inicio;

    while (F != NULL)
    {
        Aux = F->Id;
        fprintf(PtrNovo, "%d;%s;%s;%d\n", Aux.Processador, Aux.Nome, Aux.Tipo, Aux.ut);
        F = F->prox;
    }
}

void Recuperacao(TpDescritor &Descr, FILE *PtrArq, int UT, int ut1, int ut2, int ut3, int ut4, int contGravarInt, int contGravarExt, int contDel, int contLer, int contImp, int qtde1, int qtde2, int qtde3, int qtde4)
{
    FILE *PtrNovo = fopen("novo.txt", "w+");
    FILE *PtrRec = fopen("recuperar.txt", "w+");
    fprintf(PtrRec, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    fprintf(PtrNovo, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", UT, ut1, ut2, ut3, ut4, contGravarInt, contGravarExt, contDel, contLer, contImp, qtde1, qtde2, qtde3, qtde4);
	fprintf(PtrNovo, "%d %d %d %d %d\n", Descr.Inicio->contGI, Descr.Inicio->contGE, Descr.Inicio->contDel, Descr.Inicio->contLer, Descr.Inicio->contImp);
	fprintf(PtrNovo, "%d %d %d %d %d\n", Descr.Inicio->prox->contGI, Descr.Inicio->prox->contGE, Descr.Inicio->prox->contDel, Descr.Inicio->prox->contLer, Descr.Inicio->prox->contImp);
	fprintf(PtrNovo, "%d %d %d %d %d\n", Descr.Inicio->prox->prox->contGI, Descr.Inicio->prox->prox->contGE, Descr.Inicio->prox->prox->contDel, Descr.Inicio->prox->prox->contLer, Descr.Inicio->prox->prox->contImp);
	fprintf(PtrNovo, "%d %d %d %d %d\n", Descr.Fim->contGI, Descr.Fim->contGE, Descr.Fim->contDel, Descr.Fim->contLer, Descr.Fim->contImp);
    TpProcessador *P = Descr.Inicio;
    DescarregarFila(P, PtrNovo); // DescarregarFila1

    P = P->prox;
    DescarregarFila(P, PtrNovo); // DescarregarFila2

    P = P->prox;
    DescarregarFila(P, PtrNovo); // DescarregarFila3

    P = P->prox;
    DescarregarFila(P, PtrNovo); // DescarregarFila4
    TpDado Aux;
    fscanf(PtrArq, "%d;%[^;];%[^;];%d\n", &Aux.Processador, &Aux.Nome, &Aux.Tipo, &Aux.ut);
    while (!feof(PtrArq))
    {
        fprintf(PtrNovo, "%d;%s;%s;%d\n", Aux.Processador, Aux.Nome, Aux.Tipo, Aux.ut);
        fscanf(PtrArq, "%d;%[^;];%[^;];%d\n", &Aux.Processador, &Aux.Nome, &Aux.Tipo, &Aux.ut);
    }
    fclose(PtrArq);
    fclose(PtrNovo);
    fclose(PtrRec);
    remove("Trabalho.txt");
    rename("novo.txt", "Trabalho.txt");
}

TpDado Remover (TpDescritor &Descr,int Id)
{
	TpFila *Atual;
	TpDado Aux;
	TpProcessador *P = Descr.Inicio;//acessando apenas o processador diretamente
	
	while(P->IdProcessador != Id) //procurando o processador certo
		P = P->prox;
		
	if(P->Inicio->prox == NULL && P->Fim->ant == NULL) //apenas um elemento na fila
	{
		Atual = P->Inicio;
		P->Inicio = P->Fim = NULL;
		Aux = Atual->Id;
	}
	else
	{
		Atual = P->Inicio;
		P->Inicio = Atual->prox;
		P->Inicio->ant = NULL;
		Aux = Atual->Id;
	}
	delete(Atual);
		
	return Aux;
}

void RelatorioGeral()
{
	
}

int Vazia(TpDescritor Descr)
{
	if(Descr.Inicio==NULL && Descr.Fim==NULL)
		return 1;
	else
		return 0;
}

TpDado ElementoInicio(TpDescritor Descr)//fazer validacoes no main()
{
	return Descr.Inicio->Inicio->Id;//escolher se quer retornar so nome
}

TpDado ElementoFim(TpDescritor Descr)
{
	return Descr.Fim->Fim->Id;
}
