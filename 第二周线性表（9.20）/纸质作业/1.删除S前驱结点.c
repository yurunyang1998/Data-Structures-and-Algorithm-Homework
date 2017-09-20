//链表结点声明
typedef struct Node
{
	int data;
	struct Node *next;
}Node;

void Del(Node *s)
{
	Node *pSprior=NULL,*pSPprior=s;
	while(pSPprior->next->next != s)
		pSPprior = pSPprior->next;	//s前驱结点的前驱结点
		pSprior = pSPprior->next	//s的前驱结点
		pSPprior->next = s          //把s接到前驱结点的前驱结点上
		free(pSprior);				//删除s的前驱结点
}