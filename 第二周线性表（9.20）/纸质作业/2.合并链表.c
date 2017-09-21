//链表结点声明
typedef struct Node
{
	int data;
	struct Node *next;
}Node;

Node* merge(Node *A,Node *B)
{
	Node *pA = A->next,*pB = B->next,*pC = NULL,*pChead = NULL; 
	//pA/B/C 表A/B/C的当前结点，pChead表C的头指针
	int m=1,n=1;
	while(pA->next != NULL)		//A表数目为m
	{
		pA = pA->next;
		m++;
	}
	while(pB->next != NULL)		//B表数目为n
	{
		pB = pB->next;
		n++;
	}
	pA = A->next,pB = B->next;
	if(m =< n)					//B表长或者相等时
	{
		pChead = pC = pA;			//表A的第一个结点为新表第一个结点
		while(pA ->next != NULL)	
		{
			pA = pA->next;			//处理完表A当前结点，pA后移
			pC->next = pB;			//表C的下一个结点为表B当前结点
			pC = pC->next;			//pC后移
			pB = pB->next;			//处理完表B当前结点，pB后移
			pC->next = pA;			//表C的新一个结点为表A的当前结点
			pC = pC->next;			//pC后移到pA位置
		}
		pC->next = pB;				//连接表B剩下的一个或者多个结点
	}else{							//表A长的时候和上面一样
		pChead = pC = pB;
		while(pB ->next != NULL)
		{
			pB = pB->next;
			pC->next = pA;
			pC = pC->next;
			pA = pA->next;
			pC->next = pB;
			pC = pC->next;
		}
		pC->next = pA
	}
return pChead;
}