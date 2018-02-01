#include<stdio.h>
#include<conio.h>

Struct Node{
 int data;
 Node* link;
};
Struct Stack
{
	Node *top;
};
void Creat_S(Stack &S)
{
	S.top=NULL;
}
int Empty S(Stack S)
{
	if(S.top == NULL)
	return 1;
	return 0;
	
}
//day ptu vao stack
void Push_S(Stack &S, int a)
{
	Node *p=new (Node);
	p->data=a;
	p->link=S.top;
	S.top=p;
}
void Pop_S(Stack &S, int &x)
{
	Node *p =S.top;
	S.top=S.top->link;
	x=p->data;
	delete(p);
	
}
main()
{
	Stack S;
	Creat_S(s);
	for(int i=1; i<=10; i++)
	{
		int x; 
		printf("x=");
		scanf("%d",&a);
		Push_S(S,x);
		
		
	}
	while(!Empty_S(S))
	{
		int x;
		Pop_S(S,x);
		printf("%d\n",x);
	}
}
