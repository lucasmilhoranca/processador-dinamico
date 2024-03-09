void Moldura(int CLI, int LNI, int CLF, int LNF, int corMold, int corFundo)
{
	int i;
	
	textcolor(corMold); //1..15
	textbackground(corFundo); //1..7
	gotoxy(CLI,LNI);
	printf("%c",201);
	gotoxy(CLI,LNF);
	printf("%c",200);
	gotoxy(CLF,LNI);
	printf("%c",187);
	gotoxy(CLF,LNF);
	printf("%c",188);
	
	for(i=CLI+1 ; i<CLF ; i++)
	{
		gotoxy(i,LNI);
		printf("%c",205);
		gotoxy(i,LNF);
		printf("%c",205);
		//Sleep(1);
	}
	
	for(i=LNI+1 ; i<LNF ; i++)
	{
		gotoxy(CLI,i);
		printf("%c",186);
		gotoxy(CLF,i);
		printf("%c",186);
		//Sleep(1);
	}
	textcolor(7);
	textbackground(0);
}

void Processador1(void)
{
	Moldura(2,2,41,4,4,0);
	Moldura(2,5,41,35,4,0);
}

void Processador2(void)
{
	Moldura(43,2,84,4,10,0);
	Moldura(43,5,84,35,10,0);
}

void Processador3(void)
{
	Moldura(86,2,127,4,13,0);
	Moldura(86,5,127,35,13,0);
}

void Processador4(void)
{
	Moldura(129,2,167,4,7,0);
	Moldura(129,5,167,35,7,0);
}

void MolduraPrincipal(void)
{
	Moldura(1,1,168,43,3,0);
	Processador1();
	Processador2();
	Processador3();
	Processador4();
	Moldura(2,36,167,42,8,0);
	gotoxy(14,6);
	printf("Executando");
	gotoxy(58,6);
	printf("Executando");
	gotoxy(101,6);
	printf("Executando");
	gotoxy(143,6);
	printf("Executando");
}

void ExibeP1(TpFila *F, int ut)
{
	gotoxy(3,8);
	printf("                                      ");
	gotoxy(3,9);
	printf("                                      ");
	gotoxy(3,10);
	printf("                                      ");
			
	gotoxy(3,13);
	printf("                                      ");
	gotoxy(3,14);
	printf("                                      ");
	gotoxy(3,15);
	printf("                                      ");
	
	gotoxy(3,18);
	printf("                                      ");
	gotoxy(3,19);
	printf("                                      ");
	gotoxy(3,20);
	printf("                                      ");
	
	gotoxy(3,23);
	printf("                                      ");
	gotoxy(3,24);
	printf("                                      ");
	gotoxy(3,25);
	printf("                                      ");
	
	if(F == NULL)
	{
		gotoxy(9,8);
		printf("Nao existe tarefa.");
	}
	else
	{
		gotoxy(3,8);
		printf("%s", F->Id.Nome);
		gotoxy(3,9);
		printf("%s", F->Id.Tipo);
		gotoxy(3,10);
		printf("Tempo: [%d]s",ut);
		
		if(F->prox!=NULL)
		{
			gotoxy(3,13);
			printf("%s", F->prox->Id.Nome);
			gotoxy(3,14);
			printf("%s", F->prox->Id.Tipo);
			gotoxy(3,15);
			printf("Tempo: [%d]s",F->prox->Id.ut);
			
			if(F->prox->prox!=NULL)
			{
				gotoxy(3,18);
				printf("%s", F->prox->prox->Id.Nome);
				gotoxy(3,19);
				printf("%s", F->prox->prox->Id.Tipo);
				gotoxy(3,20);
				printf("Tempo: [%d]s",F->prox->prox->Id.ut);
				
				if(F->prox->prox->prox!=NULL)
				{
					gotoxy(3,23);
					printf("%s", F->prox->prox->prox->Id.Nome);
					gotoxy(3,24);
					printf("%s", F->prox->prox->prox->Id.Tipo);
					gotoxy(3,25);
					printf("Tempo: [%d]s",F->prox->prox->prox->Id.ut);
				}
			}
		}
	}
}

void ExibeP2(TpFila *F, int ut)
{
	gotoxy(44,8);
	printf("                                        ");
	gotoxy(44,9);
	printf("                                        ");
	gotoxy(44,10);
	printf("                                        ");
	gotoxy(44,13);
	
	printf("                                      ");
	gotoxy(44,14);
	printf("                                      ");
	gotoxy(44,15);
	printf("                                      ");
	
	gotoxy(44,18);
	printf("                                      ");
	gotoxy(44,19);
	printf("                                      ");
	gotoxy(44,20);
	printf("                                      ");
	
	gotoxy(44,23);
	printf("                                      ");
	gotoxy(44,24);
	printf("                                      ");
	gotoxy(44,25);
	printf("                                      ");

	if(F == NULL)
	{
		gotoxy(44,8);
		printf("Nao existe tarefa.");
	}
	else
	{
		gotoxy(44,8);
		printf("%s", F->Id.Nome);
		gotoxy(44,9);
		printf("%s", F->Id.Tipo);
		gotoxy(44,10);
		printf("Tempo: [%d]s",ut);
		
		if(F->prox!=NULL)
		{
			gotoxy(44,13);
			printf("%s", F->prox->Id.Nome);
			gotoxy(44,14);
			printf("%s", F->prox->Id.Tipo);
			gotoxy(44,15);
			printf("Tempo: [%d]s",F->prox->Id.ut);
			
			if(F->prox->prox!=NULL)
			{
				gotoxy(44,18);
				printf("%s", F->prox->prox->Id.Nome);
				gotoxy(44,19);
				printf("%s", F->prox->prox->Id.Tipo);
				gotoxy(44,20);
				printf("Tempo: [%d]s",F->prox->prox->Id.ut);
				
				if(F->prox->prox->prox!=NULL)
				{
					gotoxy(44,23);
					printf("%s", F->prox->prox->prox->Id.Nome);
					gotoxy(44,24);
					printf("%s", F->prox->prox->prox->Id.Tipo);
					gotoxy(44,25);
					printf("Tempo: [%d]s", F->prox->prox->prox->Id.ut);
				}
			}
		}
	}
}

void ExibeP3(TpFila *F, int ut)
{
	gotoxy(87,8);
	printf("                                        ");
	gotoxy(87,9);
	printf("                                        ");
	gotoxy(87,10);
	printf("                                        ");
	
	gotoxy(87,13);
	printf("                                      ");
	gotoxy(87,14);
	printf("                                      ");
	gotoxy(87,15);
	printf("                                      ");
	
	gotoxy(87,18);
	printf("                                      ");
	gotoxy(87,19);
	printf("                                      ");
	gotoxy(87,20);
	printf("                                      ");
	
	gotoxy(87,23);
	printf("                                      ");
	gotoxy(87,24);
	printf("                                      ");
	gotoxy(87,25);
	printf("                                      ");
	
	if(F == NULL)
	{
		gotoxy(87,8);
		printf("Nao existe tarefa.");
	}
	else
	{
		gotoxy(87,8);
		printf("%s", F->Id.Nome);
		gotoxy(87,9);
		printf("%s", F->Id.Tipo);
		gotoxy(87,10);
		printf("Tempo: [%d]s",ut);
		
		
		if(F->prox!=NULL)
		{
			gotoxy(87,13);
			printf("%s", F->prox->Id.Nome);
			gotoxy(87,14);
			printf("%s", F->prox->Id.Tipo);
			gotoxy(87,15);
			printf("Tempo: [%d]s",F->prox->Id.ut);
			
			if(F->prox->prox!=NULL)
			{
				gotoxy(87,18);
				printf("%s", F->prox->prox->Id.Nome);
				gotoxy(87,19);
				printf("%s", F->prox->prox->Id.Tipo);
				gotoxy(87,20);
				printf("Tempo: [%d]s",F->prox->prox->Id.ut);
				
				if(F->prox->prox->prox!=NULL)
				{
					gotoxy(87,23);
					printf("%s", F->prox->prox->prox->Id.Nome);
					gotoxy(87,24);
					printf("%s", F->prox->prox->prox->Id.Tipo);
					gotoxy(87,25);
					printf("Tempo: [%d]s", F->prox->prox->prox->Id.ut);
				}
			}
		}
	}
}

void ExibeP4(TpFila *F, int ut)
{
	gotoxy(130,8);
	printf("                                     ");
	gotoxy(130,9);
	printf("                                     ");
	gotoxy(130,10);
	printf("                                     ");
	
	gotoxy(130,13);
	printf("                                     ");
	gotoxy(130,14);
	printf("                                     ");
	gotoxy(130,15);
	printf("                                     ");
	
	gotoxy(130,18);
	printf("                                     ");
	gotoxy(130,19);
	printf("                                     ");
	gotoxy(130,20);
	printf("                                     ");
	
	gotoxy(130,23);
	printf("                                     ");
	gotoxy(130,24);
	printf("                                     ");
	gotoxy(130,25);
	printf("                                     ");
	
	if(F == NULL)
	{
		gotoxy(130,8);
		printf("Nao existe tarefa.");
	}
	else
	{
		gotoxy(130,8);
		printf("%s", F->Id.Nome,F->Id.Tipo);
		gotoxy(130,9);
		printf("%s", F->Id.Tipo);
		gotoxy(130,10);
		printf("Tempo: [%d]s",ut);
		
		if(F->prox!=NULL)
		{
			gotoxy(130,13);
			printf("%s", F->prox->Id.Nome);
			gotoxy(130,14);
			printf("%s", F->prox->Id.Tipo);
			gotoxy(130,15);
			printf("Tempo: [%d]s",F->prox->Id.ut);
			
			if(F->prox->prox!=NULL)
			{
				gotoxy(130,18);
				printf("%s", F->prox->prox->Id.Nome);
				gotoxy(130,19);
				printf("%s", F->prox->prox->Id.Tipo);
				gotoxy(130,20);
				printf("Tempo: [%d]s",F->prox->prox->Id.ut);
				
				if(F->prox->prox->prox!=NULL)
				{
					gotoxy(130,23);
					printf("%s", F->prox->prox->prox->Id.Nome);
					gotoxy(130,24);
					printf("%s", F->prox->prox->prox->Id.Tipo);
					gotoxy(130,25);
					printf("Tempo: [%d]s",F->prox->prox->prox->Id.ut);
				}
			}
		}
	}
}

void MenuTarefas(int contGInt, int contGExt, int contDel, int contLer, int contImp)
{
	gotoxy(22,39);
	printf("Gravar Disp. Int.:%d",contGInt);
	gotoxy(52,39);
	printf("Gravar Disp. Ext.:%d",contGExt);
	gotoxy(82,39);
	printf("Deletar:%d",contDel);
	gotoxy(109,39);
	printf("Leitura:%d",contLer);
	gotoxy(139,39);
	printf("Imprimir:%d",contImp);
}

void MenuProcessador(TpDescritor D)
{
	gotoxy(3,29);
	printf("Gravar Int: %d", D.Inicio->contGI);
	gotoxy(3,30);
	printf("Gravar Ext: %d", D.Inicio->contGE);
	gotoxy(3,31);
	printf("Deletar: %d", D.Inicio->contDel);
	gotoxy(3,32);
	printf("Leitura: %d", D.Inicio->contLer);
	gotoxy(3,33);
	printf("Imprimir: %d", D.Inicio->contImp);
	gotoxy(3,34);
	printf("Tarefas: %d", D.Inicio->Qtde);
	
	gotoxy(44,29);
	printf("Gravar Int: %d", D.Inicio->prox->contGI);
	gotoxy(44,30);
	printf("Gravar Ext: %d", D.Inicio->prox->contGE);
	gotoxy(44,31);
	printf("Deletar: %d", D.Inicio->prox->contDel);
	gotoxy(44,32);
	printf("Leitura: %d", D.Inicio->prox->contLer);
	gotoxy(44,33);
	printf("Imprimir: %d",D.Inicio->prox->contImp);
	gotoxy(44,34);
	printf("Tarefas: %d",D.Inicio->prox->Qtde);
	
	gotoxy(87,29);
	printf("Gravar Int: %d",D.Inicio->prox->prox->contGI);
	gotoxy(87,30);
	printf("Gravar Ext: %d",D.Inicio->prox->prox->contGE);
	gotoxy(87,31);
	printf("Deletar: %d",D.Inicio->prox->prox->contDel);
	gotoxy(87,32);
	printf("Leitra: %d",D.Inicio->prox->prox->contLer);
	gotoxy(87,33);
	printf("Imprimir: %d",D.Inicio->prox->prox->contImp);
	gotoxy(87,34);
	printf("Tarefas: %d",D.Inicio->prox->prox->Qtde);
	
	gotoxy(130,29);
	printf("Gravar Int: %d",D.Fim->contGI);
	gotoxy(130,30);
	printf("Gravar Ext: %d",D.Fim->contGE);
	gotoxy(130,31);
	printf("Deletar: %d",D.Fim->contDel);
	gotoxy(130,32);
	printf("Leitura: %d",D.Fim->contLer);
	gotoxy(130,33);
	printf("Imprimir: %d",D.Fim->contImp);
	gotoxy(130,34);
	printf("Tarefas: %d",D.Fim->Qtde);
}

void MenuRelatorio(TpDescritor D, int contGInt, int contGExt, int contDel, int contLer, int contImp)
{
	clrscr();
	Moldura(1,1,168,43,3,0);
	Moldura(2,36,167,42,8,0);
	MenuTarefas(contGInt, contGExt, contDel, contLer, contImp);
	Processador1();
	gotoxy(19,3);
	printf("P1");
	Processador2();
	gotoxy(62,3);
	printf("P2");
	Processador3();
	gotoxy(105,3);
	printf("P3");
	Processador4();
	gotoxy(147,3);
	printf("P4");
	
	gotoxy(15,10);
	printf("Gravar Int: %d", D.Inicio->contGI);
	gotoxy(15,12);
	printf("Gravar Ext: %d", D.Inicio->contGE);
	gotoxy(15,14);
	printf("Deletar: %d", D.Inicio->contDel);
	gotoxy(15,16);
	printf("Leitura: %d", D.Inicio->contLer);
	gotoxy(15,18);
	printf("Imprimir: %d", D.Inicio->contImp);
	gotoxy(15,20);
	printf("Tarefas: %d", D.Inicio->Qtde);
	
	gotoxy(57,10);
	printf("Gravar Int: %d", D.Inicio->prox->contGI);
	gotoxy(57,12);
	printf("Gravar Ext: %d", D.Inicio->prox->contGE);
	gotoxy(57,14);
	printf("Deletar: %d", D.Inicio->prox->contDel);
	gotoxy(57,16);
	printf("Leitura: %d", D.Inicio->prox->contLer);
	gotoxy(57,18);
	printf("Imprimir: %d",D.Inicio->prox->contImp);
	gotoxy(57,20);
	printf("Tarefas: %d",D.Inicio->prox->Qtde);
	
	gotoxy(100,10);
	printf("Gravar Int: %d",D.Inicio->prox->prox->contGI);
	gotoxy(100,12);
	printf("Gravar Ext: %d",D.Inicio->prox->prox->contGE);
	gotoxy(100,14);
	printf("Deletar: %d",D.Inicio->prox->prox->contDel);
	gotoxy(100,16);
	printf("Leitra: %d",D.Inicio->prox->prox->contLer);
	gotoxy(100,18);
	printf("Imprimir: %d",D.Inicio->prox->prox->contImp);
	gotoxy(100,20);
	printf("Tarefas: %d",D.Inicio->prox->prox->Qtde);
	
	gotoxy(142,10);
	printf("Gravar Int: %d",D.Fim->contGI);
	gotoxy(142,12);
	printf("Gravar Ext: %d",D.Fim->contGE);
	gotoxy(142,14);
	printf("Deletar: %d",D.Fim->contDel);
	gotoxy(142,16);
	printf("Leitura: %d",D.Fim->contLer);
	gotoxy(142,18);
	printf("Imprimir: %d",D.Fim->contImp);
	gotoxy(142,20);
	printf("Tarefas: %d",D.Fim->Qtde);
	
	getch();
}

void Menu(void)
{
	MolduraPrincipal();
	gotoxy(19,3);
	printf("P1");
	gotoxy(62,3);;
	printf("P2");
	gotoxy(105,3);
	printf("P3");
	gotoxy(147,3);
	printf("P4");
}
