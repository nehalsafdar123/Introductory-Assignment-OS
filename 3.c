#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	FILE *ptr,*ptr2;
	char arr[1000];
	int end_index=0;
	int start_index=0;
	char file_name[50];
	bool flag=true;

	if (strcmp(argv[1],"a")==0)
	{
		strcpy(file_name,"q3_a.txt");
	}
	 if (strcmp(argv[1],"b")==0)
	{
		strcpy(file_name,"q3_b.txt");
	}

	ptr=fopen(file_name,"r");
	ptr2=fopen("output_result","w");
	if(ptr==NULL)
	{
		printf("cannot open the file \n");
	}
	else
	{
		while (fgets(arr,1000,ptr)!=NULL)   // till last line
		{
			int size=strlen(arr);
			for (int i=0;i<size;i++)      //till first line 
			{
				start_index=i;
			  while (arr[i]!=' ')      //checking till space
			    {
				if ((arr[i]!='a' || arr[i]!='A'|| arr[i]!='e' || arr[i]!='E' || arr[i]!='i' || arr[i]!='I' || arr[i]!='o' || arr[i]!='O' ||
					arr[i]!='u' || arr[i]!='U')&&flag==true)
				{
					flag=true;          //if not any vowel keep own searching till space 
					i++;
				}
				else
				{
					flag=false;
					i++;              // if vowel found keep on tracking again 
				}
				end_index=i;

		    	}

			if (flag==true)
			{
				while(arr[end_index-1]!=' ')           // vowel not found reversing that word and writing in a new file
				{
					fprintf(ptr2, "%s\n", arr[end_index-1]);
				}
			}
			else
			{
				while(arr[start_index]!=' ')
				{                                             //if vowel found then just simply writing it to a file 
					fprintf(ptr2, "%s\n",arr[start_index] );
				}
			}
			  
         }
     }
fclose(ptr);
fclose(ptr2);                     //closing files 

	}

	return 0;
}