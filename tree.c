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
      printf("%d \n",noderaiz->right->number);
      printf("w \n");
   }else{
      noderaiz->left=node2;  
      printf("%d \n" ,noderaiz->left->number);
      printf("a \n");  
   }
   return noderaiz;     
}

        
node* nodeadda(node* noadd, int n){
      int i=0;

      while(noadd!=NULL){       
         if(noadd->number>n){
             noadd=noadd->left;
             if(noadd == NULL){
                noadd=(node*)malloc(sizeof(node));
                noadd->left=NULL;
                noadd->right=NULL;
                noadd->number = n;  
                printf("e \n"); 
                break;
             }
         }else{
             noadd=noadd->right;
             if(noadd == NULL){
                noadd=(node*)malloc(sizeof(node));
                noadd->left=NULL;
                noadd->right=NULL;
                noadd->number = n;  
    
                printf("o \n");
                break;
             }             
            }
         }
           
      
      return noadd;
    
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
    arvore * arvore1;
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
void busca(int n2, node* raiz){
      printf("passo 1 \n");
      int n1;
      printf("passo 2 \n");
      int bool2=0;
      printf("passo 3 \n");
      bool2=converte(raiz);
      printf("passo 4 \n");
      n1=raiz->number;
      printf("passo 5 \n");         
      while(bool2==0){
          printf("passo 6 \n");    
         if(n1>n2){  
             printf("passo 7 \n");
              raiz=raiz->right;
              printf("passo 8 \n");  
         }else{
             printf("passo 7,5 \n");
            if(n1<n2){
                printf("passo 8.5 \n");
              raiz=raiz->left;
              printf("passo 9.5 \n");              
            }
         }
         if(raiz==NULL||n1==n2){
             printf("passo 10 \n");
           bool2=1;
           printf("passo 10.5 \n");
         }else{
             printf("passo 11 \n");
           bool2=0;
           printf("passo 12 \n");
           n1=raiz->number;
           printf("passo 13 \n");    
         }         
                 
      } 
      if(n2==n1){
        printf("o numero foi encontrado");
      }else{
        printf("o numero nao foi encontrado");
      }           
      //return raiz;   
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
arvore desenharvore(node* raiz, node* no){
    char resposta;
    resposta='s';   
    int n;
    node* noadd;
    noadd=(node*)malloc(sizeof(node)); 
    noadd->left=NULL;
    noadd->right=NULL;  
    int i = 0;     
    while(resposta=='s'){
        printf("digite o valor a ser colocado na arvore \n");
        scanf("%d",&n); 
        flush_in();
        printf("voce deseja criar um novo no digite s para sim ou n para nao \n");
        scanf("%c",&resposta);
        flush_in();
        if(i == 0){
            noadd->number=n;
            raiz->number=n;
        }
        no = nodeadda(noadd,n);    
        i++; 
    } 
    arvore arvore1; 
    arvore1.pai=(node**)malloc(sizeof(node*));
    arvore1.pai[0]=raiz;
    arvore1.cont=i;      
    return arvore1;  
} 
 
int main(){
   node* raiz, *no;
   raiz=(node*)malloc(sizeof(node));
   raiz->left=NULL;
   raiz->right=NULL; 
   arvore arvore1;        
   int n;   
   arvore1=desenharvore(raiz,no);
   
   n=arvore1.cont; 
   printf("%d",countdireita(arvore1.pai[0], n)->cont);  
   printf("digite um valor para ser buscado");
   scanf("%d",&n); 
   busca(n,no); 
   return 0;   
}
