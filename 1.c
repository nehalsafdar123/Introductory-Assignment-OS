#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{

	FILE *ptr;
	char file_name[50];
	//char a[5]=argv[1];
	if (strcmp(argv[1],"a")==0)
	{
		strcpy(file_name,"q1_a.txt");
	}
	 if (strcmp(argv[1],"b")==0)
	{
		strcpy(file_name,"q1_b.txt");          //asking from the console and then copying file name according to it
	}                                 
	 if (strcmp(argv[1],"c")==0)
	{
		strcpy(file_name,"q1_c.txt");
	}

	printf("string is %s\n",argv[1]);
	printf("file name is %s\n",file_name );
	char str[100];
	int count=0;
	ptr=fopen(file_name,"r");                         //if file cannot be opened displaying error 
	if (ptr==NULL)
	{
		printf("cannot open the file\n");

	}
	else
	{
		while(fgets(str,1000,ptr)!=NULL)
		{
			int size=strlen(str);                     //running till null and getting the legth of string and then counting no of digits
			for (int i = 0; i < size; ++i)
			{
				if(str[i]>='0'&&str[i]<='9')
				{
					count++;
				}
			}
		}
		printf("No of digits are %x \n", count);    //printing no of digits
	}
	return 0;
}