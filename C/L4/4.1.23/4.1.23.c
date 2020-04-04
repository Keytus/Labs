#include<conio.h>
#include<malloc.h>
#include<windows.h>
int nestrlen(char *text)
{
	int i;
	for(i=0;;i++)
	{
		if(text[i]=='\0') return i;
	}
}
int palindrome(char *text)
{
	int len,i;
	for(i=0,len=nestrlen(text);i<len/2;i++)
	{
		if(text[i]!=text[len-1-i])return 0;
	}
	return 1;
}
int main(void)
{
	int z=1,i,j;
	char ***matrices;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("������� ����� ������:");
	scanf("%d",&z);
	if(z<0)
	{
		scanf("%*[^\n]");
		printf("������ �����\n");
		getch();
		return 0;
	}
	matrices=(char***)malloc(z);
	for(i=0;i<z;i++)
	{
		matrices[i]=(char**)malloc(3);
		for(j=0;j<3;j++)
		{
			matrices[i][j]=(char*)malloc(10);
		}
	}
	for(i=0;i<z;i++)
	{
		printf("������� �������� ������� %d:",i+1);
		for(j=0;j<3;j++)
		{
			scanf("%s",matrices[i][j]);
		}
	}
	for(i=0;i<z;i++)
	{
		for(j=0;j<3;j++)
		{
			if(palindrome(matrices[i][j])!=0)matrices[i][j][0]='\0';
		}
	}
	for(i=0;i<z;i++)
	{
		printf("�������� ������� %d:",i+1);
		for(j=0;j<3;j++)
		{
			printf("%s\t",matrices[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<z;i++)
	{
		for(j=0;j<3;j++)
		{
			free(matrices[i][j]);
		}
	}
	for(i=0;i<z;i++)
	{
		free(matrices[i]);
	}
	free(matrices);
	getch();
	return 0;
}
//---------------------------------------------------------------------------
