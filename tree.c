#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int altura;
    int countdireita;
    int countesquerda;
    int number;
    struct node *left;
    struct node *right;
}node;


struct arvore
{
    int cont;
    node **pai;
};
typedef struct arvore arvore;
node *add(int n2, node *noderaiz)
{
    node *node2;
    node2 = (struct node *)malloc(sizeof(struct node));
    node2->number = n2;
    int n1 = noderaiz->number;
    if (n1 > n2)
    {
        noderaiz->right = node2;
        printf("%d \n", noderaiz->right->number);
        printf("w \n");
    }
    else
    {
        noderaiz->left = node2;
        printf("%d \n", noderaiz->left->number);
        printf("a \n");
    }
    return noderaiz;
}

node *insereno(node *noadd, int n)
{
    noadd = (node *)malloc(sizeof(node));
    noadd->left = NULL;
    noadd->right = NULL;
    noadd->number = n;
    return noadd;
}

node *nodeadda(node *noadd, int n)
{
    int contadireita = 0, contaesquerda = 0;
    while (1)
    {
        if (noadd->number > n)
        {
            noadd = noadd->left;
            contadireita++;
            if (noadd == NULL)
            {
                noadd = insereno(noadd, n);
                noadd->countdireita = contadireita;
                noadd->altura = contadireita + contaesquerda;
                printf("e %d \n",noadd->altura);
                break;
            }
        }
        else
        {
            noadd = noadd->right;
            contaesquerda++;
            if (noadd == NULL)
            {
                noadd = insereno(noadd, n);
                noadd->countesquerda = contaesquerda;
                noadd->altura = contadireita + contaesquerda;
                printf("o %d \n",noadd->altura);
                break;
            }
        }
    }
    return noadd;
}

arvore *atualiza(arvore *arvore1, node *contado)
{
    int i;
    i = arvore1->cont;
    arvore1->pai[i] = contado;
    arvore1->cont++;
    printf("%d", arvore1->cont);
    return arvore1;
}
arvore *crianoinicial(node *noinicial, arvore *arvore1, int n)
{
    arvore1->pai = (node **)malloc(n * sizeof(node *));
    arvore1->pai[0] = noinicial;
    return arvore1;
}
arvore *countdireita(node *contado, int n)
{
    int i3 = 0;
    int i = 0;
    arvore *arvore1;
    arvore1 = (arvore *)malloc(sizeof(arvore));
    crianoinicial(contado, arvore1, n);
    while (i3 == 0)
    {
        if (contado->right == NULL)
        {
            i3 = 1;
        }
        else
        {
            arvore1 = atualiza(arvore1, contado->right);
            contado = contado->right;
            i++;
            printf("z");
        }
    }
    return arvore1;
}

arvore *countesquerda(node *contado, int n)
{
    int i3 = 0;
    arvore *arvore1;
    arvore1 = (arvore *)malloc(sizeof(arvore));
    crianoinicial(contado, arvore1, n);
    while (i3 == 0)
    {
        if (arvore1->pai == NULL)
        {
            i3 = 1;
        }
        else
        {
            atualiza(arvore1, contado->left);
        }
    }
    return arvore1;
}
int temfilho(node *pai, int n)
{
    int n1, n2;
    arvore *arvore1;
    arvore1 = (arvore *)malloc(sizeof(arvore));
    arvore1 = countdireita(pai, n);
    arvore1 = countesquerda(pai, n);
    n2 = arvore1->cont;
    if (n2 >= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    };
}
arvore *carrega(arvore *arvorecarga, arvore *arvorecarregar)
{
    int i, n, iinicio;
    iinicio = arvorecarregar->cont;
    n = arvorecarregar->cont + arvorecarga->cont;
    arvorecarregar->pai = (node **)realloc(arvorecarregar->pai, arvorecarga->cont * sizeof(node));
    for (i = iinicio; i < n; i++)
    {
        arvorecarregar->pai[i] = arvorecarga->pai[i - iinicio];
    }
    arvorecarregar->cont = n;
    return arvorecarregar;
}

void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}
arvore *abreesquerda(arvore *arvore1, arvore *arvoreg, int n)
{
    int i;
    node *noarvore;
    for (i = 0; i < arvore1->cont; i++)
    {
        noarvore = arvore1->pai[i];
        if (temfilho(noarvore, n) == 1)
        {
            arvore1 = countesquerda(arvore1->pai[i], n);
            arvoreg = carrega(arvore1, arvoreg);
        }
    }
    return arvoreg;
}
int converte(node *raiz)
{
    if (raiz == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

node *inicia_no(node *no)
{
    no = (node *)malloc(sizeof(node));
    no->left = NULL;
    no->right = NULL;
    return no;
}
void busca2(node *no, int n)
{
    if (no == NULL)
    {

        return;
    }

    else if (no->number == n)
    {
        printf("o numero foi encontrado \n");
        return;
    }

    busca2(no->left, n);
    busca2(no->right, n);
    printf("o numero nao foi encontrado \n");
}
void busca(int n2, node *raiz)
{
    int n1;
    int bool2 = 0;
    bool2 = converte(raiz);
    if (bool2 == 1)
    {
        printf("  o no esta nulo \n");
    }
    n1 = raiz->number;
    while (bool2 == 0)
    {
        if (n1 > n2)
        {
            raiz = raiz->right;
        }
        else
        {
            raiz = raiz->left;
        }
        if (raiz == NULL || n1 == n2)
        {
            bool2 = 1;
        }
        else
        {
            bool2 = 0;
            n1 = raiz->number;
        }
    }
    if (n2 == n1)
    {
        printf("o numero foi encontrado \n");
    }
    else
    {
        printf("o numero nao foi encontrado \n");
    }
    //return raiz;
}

int tamanhohierarquia(node *pai, int n)
{
    int n1, i;
    arvore *arvore1;
    arvore *arvoreg;
    arvore *arvore2;
    node *noarvore;
    int *temfilho;
    arvore1 = countdireita(pai, n);
    arvoreg = (arvore *)malloc(sizeof(arvore));
    arvoreg = carrega(arvore1, arvoreg);
    abreesquerda(arvore1, arvoreg, n);
}
node *desenharvore(node *no)
{
    char resposta;
    resposta = 's';
    int n;
    node *noadd;
    noadd = inicia_no(noadd);

    int i = 0;
    while (resposta == 's')
    {
        printf("digite o valor a ser colocado na arvore \n");
        scanf("%d", &n);
        flush_in();

        if (i == 0)
        {
            noadd->number = n;
        }

        no = nodeadda(noadd, n);
        printf("voce deseja criar um novo no digite s para sim ou n para nao \n");
        scanf("%c", &resposta);
        flush_in();
        i++;
    }

    return no; //arvore1;
}
void libera(node *no){
  if (no == NULL)
    return;
  free(no);
  libera(no->left);
  libera(no->right);
}

int main()
{
    node *raiz, *no;

    int n;
    //arvore1=desenharvore(raiz,no);
    no = desenharvore(no);
    //printf("%d",countdireita(arvore1.pai[0], n)->cont);
    printf("digite um valor para ser buscado \n");
    scanf("%d", &n);
    //busca(no,n); //busca iterativa
    busca2(no, n); //busca recursiva por travessia
    libera(no);
    return 0;
}
