#include<conio.h>
#include<stdio.h>
#include<windows.h>

#define Max 100//so phan tu toi da cua hang doi
int G[Max][Max],n ,//ma tran ke
O[Max],C[Max],P[Max],s,g;
//mang danh dau dinh
int Init_Graph(char *path)
{
	int i,j;
	FILE *fptr;
	fptr= fopen (path,"r");
	if(fptr==NULL)
	{
		system("Error");
		return 0;
		
	}
	//doc so dinh: n, dinh bat dau s,dinh ket thuc g
	fscanf(fptr,"%d%d%d",&n,&s,&g);
	for(i=1; i<=n; i++)
	{
		O[i]=C[i]=0;
		for(j=1;j<=n;j++)
		G[i][j]=0;
	}
	while(!feof(fptr)){
		fscanf(fptr,"%d",&i);
		fscanf(fptr,"%d",&j);
		fscanf(fptr,"%d",&G[i][j]);
		G[j][i]=G[i][j];
		
	}
	fclose(fptr);
	return 1;
	
}
void View_Graph(int G[][Max],int n)
{
	int i,j;
	printf("So dinh : %d\n",n);
	printf("Ma tran ke:\n\n");
	for(i=1; i<=n;i++)
	{
		for(j=1; j<=n; j++)
		printf("%d",G[i][j]);
		printf("\n");
		
	}
}
void Print(int P[],int s,int g)
{
	int i,Path[Max],k=0;
	printf("\n duong di tu %d den %d la\n",s,g);
	Path[k]=g;k++;
	i=P[g];
	while(i!=s)
	{
		Path[k]=i; k++;
		i=P[i];
	}
	Path[k]=s;
	for(i=k; i>0; i--)
	{
		if(i>0)
		printf("%d=>",Path[i]);
		else printf("%d",Path[i]);
	}
}
int Breadth_First_Search(int s,int g)
{
	QUEUE Open;
	int Close[Max];
	for(int i=1; i<=n; i++)
	Close[i]=0;
	Create_Q(Open);
	Add_Q(Open,s);//Dua dinh s vao hang doi
	P[s]=s;O[s]=1;//danh dau dinh s
	while(!Empty_Q(Open))
	{
		//lay mot dinh ra khoi hang doi luu vao u
		int u; Remove_Q(Open,u);
		if(u==g)
		return 1;
		Close[u]=1;//dua u vao tap Close
		for(int v=1; v<=n; v++)
		{
			if(G[u][v]!=0&&O[v]==0)
			{
				if(Close[v]==1)
				continue;
				Add_Q(Open,v);//dua dinh i vao hang doi 
				O[v]=1;//danh dau dinh v
				P[v]=u;
			}
		}
		return 0;//do thi ko lien thong
	}
}
int main(int argc,char **argv)
{
	int c,ok,path;
	Init_Graph((char*)"D\\Graph_01.INP");
	View_Graph(G,n);
	path=Breadth_First_Search(s,g);
	if(path)
	Print(P,s,g);
	else
	printf(" ko tona tai duong di tu %d den %d",s,g);
	return 0;
}


