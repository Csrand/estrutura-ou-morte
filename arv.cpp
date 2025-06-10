#include <iostream>

// Este ? um exemplo de programa em C++

using namespace std;

struct No{
	float ValorNum;
	string ValorTexto;
	No* Esq;
	No* Dir;
};

//header ou cabe?alho ou cabe?a
struct Arvore{
	No* Raiz;		
	int TotalElem;
};

void Ini_Arvore(Arvore* Arv){
	Arv->Raiz = NULL;
	Arv->TotalElem = 0;
}

No* CriaNo(float ValorNum, string ValorTexto){
	No* Ret;

	Ret = new No;
	Ret->ValorNum = ValorNum;
	Ret->ValorTexto = ValorTexto;	
	Ret->Esq = NULL;	
	Ret->Dir = NULL;	

	return Ret;
}

void ImprimeArvore(No* NoArv, string Tipo, char TipoValor) {
	
	if (NoArv != NULL){		//pr?-ordem
		if (Tipo == "PRE"){
			if (TipoValor == 'T'){
				cout << NoArv->ValorTexto << ", ";	
			}			
			else{
				cout << NoArv->ValorNum << ", ";	
			}
		}
				
		ImprimeArvore(NoArv->Esq, Tipo, TipoValor);						
		
		if (Tipo == "CEN"){
			if (TipoValor == 'T'){
				cout << NoArv->ValorTexto << ", ";	
			}			
			else{
				cout << NoArv->ValorNum << ", ";	
			}
		}
		
		ImprimeArvore(NoArv->Dir, Tipo, TipoValor);		

		if (Tipo == "POS"){
			if (TipoValor == 'T'){
				cout << NoArv->ValorTexto << ", ";	
			}			
			else{
				cout << NoArv->ValorNum << ", ";	
			}
		}

	}
}
No* BuscaPai(No* NoArv, int ValorNum){
	No* Ret;
	
	if (NoArv == NULL){
		Ret = NULL; 
	}
	else{
		if (ValorNum == NoArv->ValorNum){
			//cout << endl << "J? existe: " << NoArv->ValorNum;
			Ret = NULL; //Encontrou
		}
		else{		
			if (ValorNum > NoArv->ValorNum&&NoArv->Dir == NULL ||
				ValorNum < NoArv->ValorNum&&NoArv->Esq == NULL){
					//cout << endl << "Achei o pai: " << NoArv->ValorNum;
					Ret = NoArv;
			}
			else{
				if(ValorNum > NoArv->ValorNum){
					//cout << endl << "Indo pra direita: " << NoArv->ValorNum;
					Ret = BuscaPai(NoArv->Dir, ValorNum);			
				}
				else{
					//cout << endl << "Indo pra esquerda: " << NoArv->ValorNum;
					Ret = BuscaPai(NoArv->Esq, ValorNum);			
				}
			}
		}
	}
	
	return Ret;
}
No* InsereNoArvOrd(Arvore* Arv, int ValorNum, string ValorTexto){
	No *Item, *NoPai, *Aux;

	//Aloca espa?o, grava os dados e retorna o ponteiro pro elemento	
	if (Arv->Raiz == NULL){//?rvore Vazia
		Item = CriaNo(ValorNum, ValorTexto);
		Arv->Raiz = Item;
	}	
	else{
		NoPai = BuscaPai(Arv->Raiz, ValorNum);	
		if (NoPai != NULL){
			Item = CriaNo(ValorNum, ValorTexto);
			if (ValorNum < NoPai->ValorNum){				
				NoPai->Esq = Item;	
			}
			else{
				NoPai->Dir = Item;
			}							
		}
	}

	if (Item != NULL){
		Arv->TotalElem++;
	}
	
	return Item;
}


Arvore Arv;
int main () {
	setlocale (LC_ALL,"Portuguese");
	
	Ini_Arvore(&Arv);
	InsereNoArvOrd(&Arv, 6, "6");
	InsereNoArvOrd(&Arv, 5, "5");
	InsereNoArvOrd(&Arv, 8, "8");
	InsereNoArvOrd(&Arv, 4, "4");
	InsereNoArvOrd(&Arv, 7, "7");	
	InsereNoArvOrd(&Arv, 11, "B");
	InsereNoArvOrd(&Arv, 2, "2");
	InsereNoArvOrd(&Arv, 10, "A");
	InsereNoArvOrd(&Arv, 9, "9");
	InsereNoArvOrd(&Arv, 12, "C");		

	if (Arv.Raiz != NULL){
		//6,5,4,2,1,3,8,7,9,C
		ImprimeArvore(Arv.Raiz, "PRE", 'T');
		cout<< endl;
		//2, 4, 5, 6, 7, 8, 9, A, B, C,
		ImprimeArvore(Arv.Raiz, "CEN", 'T');
		cout<< endl;
		//2, 4, 5, 7, 9, A, C, B, 8, 6,
		ImprimeArvore(Arv.Raiz, "POS", 'T');
		cout<< endl;
	}
	
	return 0;
}
