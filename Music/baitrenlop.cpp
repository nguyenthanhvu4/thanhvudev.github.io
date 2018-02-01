#include<conio.h>
#include<stdio.h>
#define Max100
int G[Max][Max],n
//matran ke
,O[Max],C[Max],P[Max],s,g;
//mang danh dau dinh
int Init_Graph(char*path){
	int i,j;
	FILE*fptr;
	fptr=fopen(path,"r");
	if(fptr==NULL){
		system("Error");
		return 0;
	}
	//doc so dinh:n dinh bat dau s,dinh ket thuc g
	fscanf(fptr,"%d%d%d",&n,&s,&g);
	for(i=1; i<n; i++)
	{
		O[i]=C[i]=0;
		for(j=1; j<=n; j++ )
		{
			G[i][j]=0;
		}
		
	}
	while(!feof(fptr)){
		fscanf(fptr,"%d",&i);
		fscanf(fptr,"%d",&j)
	}
}
QUEUE Q;
main(){
	Create_Q(Q);
	for(int i=1; i<=10; i++)
	{
		int x, printf("x="); scanf("%d",&x);
		Add_Q(Q,x);
	
	}
	while(!Empty_Q(Q)){
		int x; Remove_Q(Q,x);
		printf("%d\t",x);
		
	}
}
