#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>
#include<windows.h>

#include "TADAT.h"
#include "moldura.h"

void Tarefas(int &contGravarInt, int &contGravarExt, int &contDel, int &contLer, int &contImp, TpDado Removido)
{
	if(PrioridadeRemover(Removido)==1)
		contGravarInt++;
	if(PrioridadeRemover(Removido)==2)
		contGravarExt++;
	if(PrioridadeRemover(Removido)==3)
		contDel++;
	if(PrioridadeRemover(Removido)==4)
		contLer++;
	if(PrioridadeRemover(Removido)==5)
		contImp++;
}

void TarefasProc(TpProcessador *P,TpDado Removido)
{
	if(PrioridadeRemover(Removido)==1)
		P->contGI++;
	if(PrioridadeRemover(Removido)==2)
		P->contGE++;
	if(PrioridadeRemover(Removido)==3)
		P->contDel++;
	if(PrioridadeRemover(Removido)==4)
		P->contLer++;
	if(PrioridadeRemover(Removido)==5)
		P->contImp++;
}

void TerminarExecucao (TpDescritor &Descr,int &UT,int &ut1,int &ut2, int &ut3, int &ut4,int &contGravarInt,int &contGravarExt,int &contDel,int &contLer,int &contImp,TpDado Removido)
{
	while(Descr.Inicio->Inicio != NULL || Descr.Inicio->prox->Inicio != NULL || Descr.Inicio->prox->prox->Inicio != NULL || Descr.Fim->Inicio != NULL)
	{
		if(ut1>0)
		{
			ExibeP1(Descr.Inicio->Inicio,ut1);
			ut1--;
		}
		if(ut2>0)
		{
			ExibeP2(Descr.Inicio->prox->Inicio,ut2);
			ut2--;
		}
		if(ut3>0)
		{
			ExibeP3(Descr.Inicio->prox->prox->Inicio,ut3);
			ut3--;
		}
		if(ut4>0)
		{
			ExibeP4(Descr.Fim->Inicio,ut4);
			ut4--;
		}
		
		if(ut1==0)
		{
			Removido = Remover(Descr,1);
			if(Descr.Inicio->Inicio == NULL)
				ut1= 999;
			else
				ut1=Descr.Inicio->Inicio->Id.ut;
			Tarefas(contGravarInt,contGravarExt,contDel,contLer,contImp,Removido);
			TarefasProc(Descr.Inicio,Removido);
			Descr.Inicio->Qtde++;
		}
		if(ut2==0)
		{
			Removido = Remover(Descr,2);
			if(Descr.Inicio->prox->Inicio == NULL)
				ut2= 999;
			else
				ut2=Descr.Inicio->prox->Inicio->Id.ut;
			Tarefas(contGravarInt,contGravarExt,contDel,contLer,contImp,Removido);
			TarefasProc(Descr.Inicio->prox,Removido);
			Descr.Inicio->prox->Qtde++;
		}
		if(ut3==0)
		{
			Removido = Remover(Descr,3);
			if(Descr.Inicio->prox->prox->Inicio == NULL)
				ut3 = 999;
			else
				ut3= Descr.Inicio->prox->prox->Inicio->Id.ut;
			Tarefas(contGravarInt,contGravarExt,contDel,contLer,contImp,Removido);
			TarefasProc(Descr.Inicio->prox->prox,Removido);
			Descr.Inicio->prox->prox->Qtde++;
		}
		if(ut4==0)
		{
			Removido = Remover(Descr,4);
			if(Descr.Fim->Inicio == NULL)
				ut4 = 999;
			else
				ut4=Descr.Fim->Inicio->Id.ut;
			Tarefas(contGravarInt,contGravarExt,contDel,contLer,contImp,Removido);
			TarefasProc(Descr.Fim,Removido);
			Descr.Fim->Qtde++;
		}
		
		//tem que colcoar as a funcao tarefas dentro dos if pois pode remover mais de uma tarefa no mesmo laço de repeticao
		
		UT++;
	}
}

void Executa()
{
	Sleep(2000);
	Menu();
	FILE *PtrArq = fopen("Trabalho.txt","r");
	FILE *PtrRec = fopen("recuperar.txt","r");
	TpDescritor Descr;
	Inicializar(Descr);
	TpProcessador *Atual = Descr.Inicio;
	TpDado Aux, Removido;
	int UT, ut1, ut2, ut3, ut4, contGravarInt, contGravarExt, contDel, contLer, contImp, i=0; //contadores de cada tarefa e unidade de tempo
	int controle=1;
	//inicializar
	if(PtrRec != NULL)
	{
		fscanf(PtrArq,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &UT, &ut1, &ut2, &ut3, &ut4, &contGravarInt, &contGravarExt, &contDel, &contLer, &contImp, &Descr.Inicio->Qtde, &Descr.Inicio->prox->Qtde, &Descr.Inicio->prox->prox->Qtde, &Descr.Fim->Qtde);
		fscanf(PtrArq,"%d %d %d %d %d\n", &Descr.Inicio->contGI, &Descr.Inicio->contGE, &Descr.Inicio->contDel, &Descr.Inicio->contLer, &Descr.Inicio->contImp);
		fscanf(PtrArq,"%d %d %d %d %d\n", &Descr.Inicio->prox->contGI, &Descr.Inicio->prox->contGE, &Descr.Inicio->prox->contDel, &Descr.Inicio->prox->contLer, &Descr.Inicio->prox->contImp);
		fscanf(PtrArq,"%d %d %d %d %d\n", &Descr.Inicio->prox->prox->contGI, &Descr.Inicio->prox->prox->contGE, &Descr.Inicio->prox->prox->contDel, &Descr.Inicio->prox->prox->contLer, &Descr.Inicio->prox->prox->contImp);
		fscanf(PtrArq,"%d %d %d %d %d\n", &Descr.Fim->contGI, &Descr.Fim->contGE, &Descr.Fim->contDel, &Descr.Fim->contLer, &Descr.Fim->contImp);	
	}
	else
	{
		//inicializacao padrao
		UT=0; ut1=999; ut2=999; ut3=999; ut4=999; contGravarInt=0; contGravarExt=0; contDel=0; contLer=0; contImp=0; i=0;
	}
			
	fscanf(PtrArq,"%d;%[^;];%[^;];%d\n", &Aux.Processador, &Aux.Nome, &Aux.Tipo, &Aux.ut);
	Inserir(Descr,Aux,ut1,ut2,ut3,ut4);
	
	while(controle != 27 && (!feof(PtrArq) || Descr.Inicio->Inicio != NULL || Descr.Inicio->prox->Inicio != NULL || Descr.Inicio->prox->prox->Inicio != NULL || Descr.Fim->Inicio != NULL))
	{	
		
		if(ut1==0)
		{
			Removido = Remover(Descr,1);
			if(Descr.Inicio->Inicio == NULL)
				ut1= 999;
			else
				ut1=Descr.Inicio->Inicio->Id.ut;
			Tarefas(contGravarInt,contGravarExt,contDel,contLer,contImp,Removido);
			TarefasProc(Descr.Inicio,Removido);
			Descr.Inicio->Qtde++;
	 	}
		if(ut2==0)
		{
			Removido = Remover(Descr,2);
			if(Descr.Inicio->prox->Inicio == NULL)
				ut2= 999;
			else
				ut2=Descr.Inicio->prox->Inicio->Id.ut;
			Tarefas(contGravarInt,contGravarExt,contDel,contLer,contImp,Removido);
			TarefasProc(Descr.Inicio->prox,Removido);
			Descr.Inicio->prox->Qtde++;
		}
		if(ut3==0)
		{
			Removido = Remover(Descr,3);
			if(Descr.Inicio->prox->prox->Inicio == NULL)
				ut3 = 999;
			else
				ut3= Descr.Inicio->prox->prox->Inicio->Id.ut;
			Tarefas(contGravarInt,contGravarExt,contDel,contLer,contImp,Removido);
			TarefasProc(Descr.Inicio->prox->prox,Removido);
			Descr.Inicio->prox->prox->Qtde++;
		}
		if(ut4==0)
		{
			Removido = Remover(Descr,4);
			if(Descr.Fim->Inicio == NULL)
				ut4 = 999;
			else
				ut4=Descr.Fim->Inicio->Id.ut;
			Tarefas(contGravarInt,contGravarExt,contDel,contLer,contImp,Removido);
			TarefasProc(Descr.Fim,Removido);
			Descr.Fim->Qtde++;
		}
		//tem que colcoar as a funcao tarefas dentro dos if pois pode remover mais de uma tarefa no mesmo laço de repeticao
		if(ut1>0)
		{
			ExibeP1(Descr.Inicio->Inicio,ut1);
			ut1--;
		}
		if(ut2>0)
		{
			ExibeP2(Descr.Inicio->prox->Inicio,ut2);
			ut2--;
		}
		if(ut3>0)
		{
			ExibeP3(Descr.Inicio->prox->prox->Inicio,ut3);
			ut3--;
		}
		if(ut4>0)
		{
			ExibeP4(Descr.Fim->Inicio,ut4);
			ut4--;
		}
		
		UT++;
		if(i != 1 && (UT % 2 == 0 || !feof(PtrArq)))
		{
			fscanf(PtrArq,"%d;%[^;];%[^;];%d\n", &Aux.Processador, &Aux.Nome, &Aux.Tipo, &Aux.ut);
			Inserir(Descr,Aux,ut1,ut2,ut3,ut4);
			if(feof(PtrArq))
				i = 1;
		}
		if(kbhit())
		{
			controle = getch();
			if(controle==27)
			{
				TerminarExecucao(Descr,UT,ut1,ut2,ut3,ut4,contGravarInt,contGravarExt,contDel,contLer,contImp,Removido);
				ut1 = ut2 = ut3 = ut4 = 999;
				Recuperacao(Descr, PtrArq, UT, ut1, ut2, ut3, ut4, contGravarInt, contGravarExt, contDel, contLer, contImp, Descr.Inicio->Qtde, Descr.Inicio->prox->Qtde, Descr.Inicio->prox->prox->Qtde, Descr.Fim->Qtde);
			}
		}
		MenuProcessador(Descr);
		MenuTarefas(contGravarInt,contGravarExt,contDel,contLer,contImp);
		gotoxy(168,43);
		//Sleep(1);
	}
	getch();
	if(feof(PtrArq))
		fclose(PtrArq);
	MenuRelatorio(Descr, contGravarInt, contGravarExt, contDel, contLer, contImp);
}

int main(void)
{
	Executa();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return 0;
}
