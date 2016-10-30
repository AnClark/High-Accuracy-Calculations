#include<cstdio>
#include<cstdlib>
#include<cstring>

#define MAXN 1000

int main()
{
	/* Variable definitions. 
		By using array, we can handle numbers those often be out of bounds.
	*/
	int num1[MAXN];
	int num2[MAXN];
	int ans[MAXN];
	
	char buff_num1[MAXN];
	char buff_num2[MAXN];
	
	while(true)
	{
		/* Initialize variables. */
			memset(num1,0,sizeof(num1));
			memset(num2,0,sizeof(num2));
			memset(ans,0,sizeof(ans));
		
		/* Input the two numbers for reducing */
			//Receive char format	
			printf("Input a first number:");
				scanf("%s", buff_num1);
			printf("Input a second number:");
				scanf("%s", buff_num2);
		
			//Get length
			int len1 = strlen(buff_num1);
			int len2 = strlen(buff_num2);
			
			//Convert char format into int format
			for(int i=0; i < len1; i++)
				num1[len1 - i - 1] = buff_num1[i] - '0';
			for(int i=0; i < len2; i++)
				num2[len2 - i - 1] = buff_num2[i] - '0';
			
		/* Now, let's calculate. */
			//Pick out the input number which is longer
			int larger_len = (len1 > len2) ? len1 : len2;
			
			//Backframe is the action that when we meet a step that the digit on num1 is smaller than num2,
			//		we shall mark a point on its left digit, to "borrow" a "ten" to continue calculating.
			int backframe = 0;
			
			//Reduce digit by digit
			for(int i=0; i <= len1; i++)
			{
				num1[i] += backframe;			//Apply backframe first.
				
				//If the digit on num1 is smaller, we'll make a backframe.
				if(num1[i] < num2[i])			
				{
					int s = (10 + num1[i]) - num2[i];	//Calculate the digit on the specified step
					ans[i] = s;			//Apply
					backframe = -1;		//Make a backframe
				}
				
				//If the digit on num1 is larger, then there's no need of backframe.
				else
				{
					int s = num1[i] - num2[i];		//Calculate the digit on the specified step
					ans[i] = s;			//Apply
					backframe = 0;		//Reset backframe
				}
			}
			
			/* Print result */
			//Ignore those leaded zeros
			int j;
			for(j=MAXN-1; j >= 0; j--)
				if(ans[j]) break;
				
			//Print out digits
			for(int i=j; i>=0; i--)
				printf("%d", ans[i]);
			printf("\n");
			
	}

}
