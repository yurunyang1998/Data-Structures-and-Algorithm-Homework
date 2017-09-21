//约瑟夫环实现
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Ring
{
    int id;//每个人的编号
    int pwd;//每个人的密码
    struct Ring *next;//指向下一结点的指针
}RingLink,*RingPtr;

RingPtr GetNum(int scan_id, int scan_passwd)
{
    RingPtr pNew;
    pNew=(RingPtr)malloc(sizeof(RingLink));
    if(!pNew)
    {
        printf("error to apply for space！");
        exit(0);
    }
    pNew->id=scan_id;
    pNew->pwd=scan_passwd;
    pNew->next=NULL;
    return pNew;

}

RingPtr CreatList(RingPtr pHead , int TotalNum)
{
    int i;
    int passwd;
    RingPtr pNew,pEnd;
    pEnd = pHead;
    for (i=1; i<=TotalNum; i++)
    {
        printf("input  the %d people's password: ",i);
        scanf("%d",&passwd);
        pNew = GetNum(i , passwd);
        pEnd->next = pNew;
        pEnd = pNew;
    }
    pEnd->next=pHead->next;
    printf("List creat finish \n\n");
    return pHead;
}
void GameStar(RingPtr pHead ,int TotalNum, int OutNum)
{
    int count;
    int Outpassword = OutNum;
    RingPtr p=NULL,pEnd=NULL,pDel=NULL;
    pEnd = pHead;
    p=pHead->next;
    while(p ->next != pHead->next)
    {
        p=p->next;

    }
    pEnd = p;

    while(TotalNum != 0)
    {
        for(count = 1; count < Outpassword; count++)
        {

            p = p->next;
        }

       /* if (p=pEnd);
        {
            flag = 0;
        }*/
        pDel = p->next;
        p->next= pDel->next;

        Outpassword = pDel->pwd;

        printf("the %d people out,his password is%d\n",pDel->id,pDel->pwd);
        free(pDel);
        TotalNum --;
    }
}

int main(void)
{
    int TotalNum=0,OutNum=0;
    RingPtr pHead=NULL;
    printf("Please input total number:");
    scanf("%d",&TotalNum);
    printf("Please input out number:");
    scanf("%d",&OutNum);
    if(TotalNum<0 || TotalNum>MAX)
    {
        printf("Total number error");
        return 0;
    }
    if(OutNum<0 || OutNum>MAX)
    {
        printf("Out number error");
        return 0;
    }
    pHead = (RingPtr)malloc(sizeof(RingLink));
    pHead->id = 0;
    pHead->next = NULL;
    pHead = CreatList(pHead , TotalNum);

    GameStar(pHead ,TotalNum, OutNum);
}
