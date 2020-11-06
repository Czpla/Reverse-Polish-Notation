#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    char Item[100];
    int Topo;
} Pilha;

void CriaPilha (Pilha *p) {
   p->Topo = -1;
} 

bool Pilha_Vazia (Pilha *p) {
    if(p->Topo == -1) {
        return true;
    } else {
        return false;
    }
}

bool Pilha_Cheia (Pilha *p) {
    if(p->Item == 100 -1) {
        return true;
    } else {
        return false;
    }
}

void Empilha (Pilha *p, int x) {
    if(Pilha_Cheia(p) == true) {
        printf("Erro: Pilha cheia");
    } else {
        p->Topo++;
        p->Item[p->Topo] = x;
    }
}

int Desempilha (Pilha *p) {
    int aux;

    if(Pilha_Vazia(p) == true) {
        printf("Erro: Pilha vazia");
    } else {
        aux = p->Item[p->Topo];
        p->Topo--;
        return aux;
    }
}

int Prioridade(char c, char t) {
  int pc, pt;
 
  if(c == '^') {
        pc = 4;
  } else if(c == '*' || c == '/') {
        pc = 2;
  } else if(c == '+' || c == '-') {
        pc = 1;
  } else if(c == '(') {
        pc = 4;
  } if(t == '^') {
        pt = 3;
  } else if(t == '*' || t == '/') {
        pt = 2;
  } else if(t == '+' || t == '-') {
        pt = 1;
  } else if(t == '(') {
        pt = 0;
  }

  return (pc > pt);
}

void Polonesa_Inversa(char expressao[]) {
    int i = 0;
    char c,t; 

    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    CriaPilha(p);

    Empilha(p, '(');
    
    do {
        c = expressao[i];
        i++;

        if(c >= 'a' && c <= 'z') {
            printf("%c", c);
        } else if(c == '(') {
            Empilha(p, '(');
        } else if(c == ')' || c == '\0') {
            do{
                t = Desempilha(p);
                if(t != '(')
                printf("%c", t);
            } while(t != '(');
        } else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ) {
            while(1) {
                t = Desempilha(p);

                if(Prioridade(c,t)) {
                    Empilha(p, t);

                    Empilha(p, c);
                    break;
                } else {
                    printf("%c", t);
                }   
            }
        }
    } while(c != '\0');
        printf("\n");
//      LiberaPilha(p);
        system("pause >> NULL");
}

int main () {
    
    char expressao[] = "a*(b+c)*(d-g)*h";
  
    Polonesa_Inversa(expressao);

    return 0;
}