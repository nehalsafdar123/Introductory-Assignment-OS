#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	
	FILE *ptr,*ptr2;
	int take_input=1;
	int input;char data[1000];
	printf("press 1 to ADD a Record\n");
	printf("press 2 to READ a Record\n");
	printf("press 3 to DELETE a Record\n");
	printf("Enter Number now : ");
	scanf("%d",&input);
	

	if (input==1)
	{
		ptr=fopen("q2_output.txt","w");
		while(take_input!=0)
		{

		printf("Enter your Name : ");
		scanf("%s",data);
		//printf("%s\n",data );
		fprintf(ptr, "Name : %s\n",data );
		printf("Enter your Roll Number : ");                     //asking for the inputs
		scanf("%s",data);
		//printf("%s\n",data );
		fprintf(ptr, "Roll NO :%s\n",data );
		printf("Enter your Email : ");
		scanf("%s",data);
		//printf("%s\n",data );
		fprintf(ptr, "Email : %s\n",data );
		printf("Press 0 to END \n" );
		scanf("%d",&take_input);
	}
	fclose(ptr);

	}
	 if(input==2)
	{
		int choice;
		ptr=fopen("q2_output.txt","r");
		printf("press 0 to display your details \n");
		printf("press 1 to display details of your 1st fellow \n");             
		printf("press 2 to display details of your 2nd fellow \n");
		scanf("%d",&choice);
		int start=0;
		if(choice==0)
		{
			int till=3;
			for (int i = 0; i < till; ++i)
			{
				fgets(data,1000,ptr);              //since asking personal details which is in first 3 lines displaying that
				printf("%s\n",data );
			}
		}

		if(choice==1)
		{
			int till=6;
			for (int i = 0; i < till; ++i)
			{
				fgets(data,1000,ptr);
				if(i==3||i==4||i==5)
				{                                //for 2nd friend 
				  printf("%s\n",data );
				}
			}

		}
		if(choice==2)
		{
			int till=9;
			for (int i = 0; i < till; ++i)
			{
				fgets(data,1000,ptr);                  //for 3rd friend
				if(i==6||i==7||i==8)
				{
				  printf("%s\n",data );
				}
			}


		}
		fclose(ptr);

	}



	if(input==3)
	{
		int choice;
		ptr=fopen("q2_output.txt","r");
		printf("press 0 to DELETE your details \n");
		printf("press 1 to DELETE details of your 1st fellow \n");
		printf("press 2 to DELETE details of your 2nd fellow \n");
		scanf("%d",&choice);

		if(choice==0)
		{
			ptr2=fopen("deleted.txt","w");
			int x=0,till=9;
			while(fgets(data,1000,ptr)!=NULL)
		{
			if (x==0||x==1||x==2)
			{
				x++;

			}
			else                               //writing the deails of all the other users inspite of user itself
				                                // in another file.
			{
				fprintf(ptr2, "%s",data );
			}			
			
		}
			
			fclose(ptr);
			fclose(ptr2);
			//remove("q2_output.txt");
			//rename("second.txt","q2_output.txt");
	}

		if(choice==1)
		{
			ptr2=fopen("deleted.txt","w");
			int x=0,till=9;
			while(fgets(data,1000,ptr)!=NULL)           //for the 2nd user 
		{
			if (x==3||x==4||x==5)                    
			{
				x++;

			}
			else
			{
				fprintf(ptr2, "%s",data );
				x++;
			}			
			
		}
			
			fclose(ptr);
			fclose(ptr2);

		}
		if(choice==2)
		{
			ptr2=fopen("deleted.txt","w");
			int x=0,till=9;
			while(fgets(data,1000,ptr)!=NULL)
		{
			if (x==6||x==7||x==8)                  //for the 3rd user 
			{
				x++;
			}
			else
			{
				fprintf(ptr2, "%s",data );
				x++;
			}			
			
		}
			
			fclose(ptr);
			fclose(ptr2);
	}
}

	/* code */
	return 0;
}