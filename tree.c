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
        
      while(raiz!=NULL){
         n1=raiz->number;
         n2=noadd->number;   
         if(n1>n2){
            raiz=raiz->left;
         }else{
            if(n1<n2){
              raiz=raiz->right;              
            }
         }
      } 
      raiz=noadd; 
      return raiz;
    
}            
                  
         
arvore* atualiza(arvore* arvore1, node* contado){
        int i;
        i=arvore1->cont;  
        arvore1->pai=(node**)realloc(arvore1->pai,sizeof(node*));
        arvore1->pai[i]=contado;
        arvore1->cont++;
        return arvore1;   
}
arvore* crianoinicial(node* noinicial, arvore* arvore1){
       arvore1->pai=(node*)malloc(sizeof(node)); 
       arvore1->pai[0]=noinicial;
       return arvore1;   
}   
arvore* countdireita(node* contado){
    int i3=0;
    arvore* arvore1;
    arvore1=(arvore*) malloc(sizeof(arvore));  
    crianoinicial(contado,arvore1);  
    while(i3==0){
        if(arvore1->pai==NULL){ 
         i3=1; 
        }else{    
         arvore1=atualiza(arvore1,contado->right);
        }
    }     
   return arvore1;
}

arvore* countesquerda(node* contado){
    int i3=0;
    arvore* arvore1;
    arvore1=(arvore*) malloc(sizeof(arvore));
    crianoinicial(arvore1,contado);
    while(i3==0){
       if(arvore1->pai==NULL){
         i3=1;
       }else{    
         atualiza(arvore1,contado->left);
       }
    }    
    return arvore1;
}
int temfilho(node* pai){
    int n1,n2;
    arvore* arvore1;
    arvore1=(arvore*)malloc(sizeof(arvore));
    arvore1=countdireita(pai);
    arvore1=countesquerda(pai);
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
arvore* abreesquerda(arvore* arvore1, arvore* arvoreg){
      int i; 
      node* noarvore;       
      for(i=0;i<arvore1->cont;i++){  
        noarvore=arvore1->pai[i];     
        if(temfilho(noarvore)==1){  
          arvore1=countesquerda(arvore1->pai[i]);
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
      while(bool2==0){ 
         n1=raiz->number;    
         if(n1>n2){  
              raiz=raiz->left;   
         }else{
            if(n1<n2){
              raiz=raiz->right;              
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
                                  
int tamanhohierarquia(node* pai){
    int n1, i;
    arvore* arvore1; 
    arvore* arvoreg;
    arvore* arvore2;
    node* noarvore;
    int* temfilho;  
    arvore1=countdireita(pai); 
    arvoreg=(arvore*)malloc(sizeof(arvore));   
    arvoreg=carrega(arvore1,arvoreg);
    abreesquerda(arvore1,arvoreg);
    
}  
node* desenharvore(node* raiz){
    char resposta;
    resposta='s';   
    int n;
    node* noadd;
    noadd=(node*)malloc(sizeof(node)); 
    noadd->left=NULL;      
    while(resposta=='s'){
        printf("digite o valor a ser colocado na arvore");
        scanf("%d",&n); 
        flush_in();
        printf("voce deseja criar um novo no digite s para sim ou n para nao");
        scanf("%c",&resposta);
        flush_in();
        noadd->number=n;
        nodeadda(noadd,raiz); 
    } 
    return raiz;  
} 
 
int main(){
   node* raiz;
   raiz=(node*)malloc(sizeof(node));
   raiz->left=NULL;
   raiz->right=NULL;      
   int n;   
   raiz=desenharvore(raiz);
   printf("digite um valor para ser buscado");
   printf("%d",countdireita(raiz));
   //busca(n,raiz); 
   return 0;   
}
