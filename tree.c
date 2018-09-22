#include<stdio.h>
#include<stdlib.h>

struct node {
    int number;
    struct node* left;
    struct node* right;
};
typedef struct node node;
struct arvore{
       int cont;
       node** pai;
};
typedef struct arvore arvore;  
node* add(int n2, node* noderaiz){
      node* node2;
      node2=(struct node*)malloc(sizeof(struct node)); 
      node2->number=n2;
      int  n1= noderaiz->number;      
   if(n1>n2){
      noderaiz->right=node2;  
      printf("%d",noderaiz->right->number);
      printf("w");
   }else{
      noderaiz->left=node2;  
      printf("%d" ,noderaiz->left->number);
      printf("a");  
   }
   return noderaiz;     
}

        
node* nodeadda(node* noadd, node* raiz){
      int n1, n2;
      node* raiz2;  
      raiz2=raiz;
      while(raiz2!=NULL){
         n1=raiz2->number;    
         n2=noadd->number;   
         if(n1>n2){
             raiz2=raiz2->left;
             printf("e"); 
         }else{
            if(n1<n2){
             raiz2=raiz2->right; 
             printf("o");             
            }
         }
      }     
      raiz2=noadd; 
      return raiz2;
    
}            
                  
         
arvore* atualiza(arvore* arvore1, node* contado){
        int i;
        i=arvore1->cont;  
        arvore1->pai[i]=contado;
        arvore1->cont++;
        printf("%d",arvore1->cont);  
        return arvore1;   
}
arvore* crianoinicial(node* noinicial, arvore* arvore1, int n){
       arvore1->pai=(node**)malloc(n*sizeof(node*)); 
       arvore1->pai[0]=noinicial;
       return arvore1;   
}   
arvore* countdireita(node* contado, int n){
    int i3=0;
    int i=0;
    arvore* arvore1;
    arvore1=(arvore*) malloc(sizeof(arvore));  
    crianoinicial(contado,arvore1,n);       
    while(i3==0){
        if(contado->right==NULL){ 
         i3=1; 
        }else{    
         arvore1=atualiza(arvore1, contado->right);
         contado=contado->right;
         i++; 
         printf("z"); 
        }
          
               
    }      
   return arvore1;
}

arvore* countesquerda(node* contado, int n){
    int i3=0;
    arvore* arvore1;
    arvore1=(arvore*) malloc(sizeof(arvore));
    crianoinicial(contado,arvore1,n);
    while(i3==0){
       if(arvore1->pai==NULL){
         i3=1;
       }else{    
         atualiza(arvore1,contado->left);
       }
    }    
    return arvore1;
}
int temfilho(node* pai, int n ){
    int n1,n2;
    arvore* arvore1;
    arvore1=(arvore*)malloc(sizeof(arvore));
    arvore1=countdireita(pai,n);
    arvore1=countesquerda(pai,n);
    n2=arvore1->cont;         
    if(n2>=1){
       return 1;
    }else{
       return 0;
    };
}
arvore* carrega(arvore* arvorecarga, arvore* arvorecarregar){
    int i,n,iinicio;
    iinicio=arvorecarregar->cont;
    n=arvorecarregar->cont+arvorecarga->cont;
    arvorecarregar->pai=(node**)realloc(arvorecarregar->pai,arvorecarga->cont*sizeof(node)); 
    for(i=iinicio;i<n;i++){
        arvorecarregar->pai[i]=arvorecarga->pai[i-iinicio];
    }
    arvorecarregar->cont=n;
    return arvorecarregar;       
} 
          
void flush_in(){
     int ch;
     while((ch=fgetc(stdin))!=EOF&& ch!='\n'){}
} 
arvore* abreesquerda(arvore* arvore1, arvore* arvoreg, int n ){
      int i; 
      node* noarvore;       
      for(i=0;i<arvore1->cont;i++){  
        noarvore=arvore1->pai[i];     
        if(temfilho(noarvore,n)==1){  
          arvore1=countesquerda(arvore1->pai[i], n);
          arvoreg=carrega(arvore1,arvoreg);
        } 
            
     }
     return arvoreg;   
   
}
int converte(node* raiz){
    if(raiz==NULL){
     return 1;
    }else{
     return 0;
    } 
}         
node* busca(int n2, node* raiz){
      int n1;
      int bool2=0;
      bool2=converte(raiz);  
      n1=raiz->number;         
      while(bool2==0){    
         if(n1>n2){  
              raiz=raiz->right;   
         }else{
            if(n1<n2){
              raiz=raiz->left;              
            }
         }
         if(raiz==NULL||n1==n2){
           bool2=1;
         }else{
           bool2=0;
           n1=raiz->number;    
         }         
                 
      } 
      if(n2==raiz->number){
        printf("o numero foi encontrado");
      }else{
        printf("o numero nao foi encontrado");
      }           
      return raiz;   
 }        
                                  
int tamanhohierarquia(node* pai, int  n){
    int n1, i;
    arvore* arvore1; 
    arvore* arvoreg;
    arvore* arvore2;
    node* noarvore;
    int* temfilho;  
    arvore1=countdireita(pai, n); 
    arvoreg=(arvore*)malloc(sizeof(arvore));   
    arvoreg=carrega(arvore1,arvoreg);
    abreesquerda(arvore1,arvoreg,n);
    
}  
arvore desenharvore(node* raiz){
    char resposta;
    resposta='s';   
    int n;
    node* noadd;
    noadd=(node*)malloc(sizeof(node)); 
    noadd->left=NULL;
    noadd->right=NULL;  
    int i;     
    while(resposta=='s'){
        printf("digite o valor a ser colocado na arvore");
        scanf("%d",&n); 
        flush_in();
        printf("voce deseja criar um novo no digite s para sim ou n para nao");
        scanf("%c",&resposta);
        flush_in();
        noadd->number=n;
        nodeadda(noadd,raiz);    
        i++; 
    } 
    arvore arvore1; 
    arvore1.pai=(node**)malloc(sizeof(node*));
    arvore1.pai[0]=raiz;
    arvore1.cont=i;      
    return arvore1;  
} 
 
int main(){
   node* raiz;
   raiz=(node*)malloc(sizeof(node));
   raiz->left=NULL;
   raiz->right=NULL; 
   arvore arvore1;        
   int n;   
   arvore1=desenharvore(raiz);
   
   n=arvore1.cont; 
   printf("%d",countdireita(arvore1.pai[0], n)->cont);  
   printf("digite um valor para ser buscado");
   scanf("%d",&n); 
   busca(n,raiz); 
   return 0;   
}
