/* 
	Exponentiation - POJ #1001 
	http://poj.org/problem?id=1001
	This code is written for local test. It has not been aimmed to submit. 
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 1000
#define __dot -1
using namespace std;

void multiply(int *num1, int *num2);

int main()
{
	int R[MAXN];
	int n;
	int ans[MAXN];
	int decimal_count;	
	
	char buff_R[MAXN];
	
	while(true){
			memset(R,0,sizeof(R));
			memset(ans,0,sizeof(ans));	ans[0] = 1;
			
			printf("Input basement R:");
				scanf("%s", buff_R);
			printf("Input exponentation n:");
				scanf("%d", &n);
				
			int len = strlen(buff_R);
			
			int i;
			for(i=0; i < len; i++)
				if(buff_R[i] == '.') break;
			decimal_count = len-i-1;
			 
			
			int j=0;
			for(int i=len-1; i>=0; i--)
				if(buff_R[i] >= '0' && buff_R[i] <= '9'){
					R[j] =  buff_R[i] - '0';
					j++;
				}
			
			system(":");
			
			/* Now, start calculations! */
			for(int i=0; i<=n; i++)
				multiply(ans, R);
			
			/* Print out results */
			//Ignore insignificant trailing zeros
			for(j=MAXN-1; j>=0; j--)
				if(ans[j]) break;
			
			for(i=j; i>=0; i++)
				printf("%d",ans[i]);
	}

	
}

void multiply(int *num1, int *num2){
	int ans[MAXN];
	memset(ans,0,sizeof(ans));
	
	//获取两个被乘数的长度；
	int len_num1,len_num2;
	for(int i=MAXN-1; i>=0; i--)
		if(num1[i]){
			len_num1 = i;
			break;
		}
	for(int i=MAXN-1; i>=0; i--)
		if(num2[i]){
			len_num2 = i;
			break;
		}
	
	//找出比较大的长度，作为接下来运算的基准	
	int maxlen = (len_num1 > len_num2) ? len_num1 : len_num2;
	
	//开始算乘积
	for(int j=0; j<=len_num2; j++){			//乘数的每一位都要与被乘数的每一位相乘 
		int current_ans[MAXN];
		memset(current_ans,0,sizeof(current_ans));
		
		//先乘 
		int c=0;
		for(int i=0; i<=len_num1; i++){
			int s = num2[i] * num1[i] + c;
			current_ans[i + (j)] = s;
			c = s / 10;
		}
		
		//后加
		c=0;
		for(int i=0; i<MAXN; i++){
			int s = ans[i] + current_ans[i] + c;
			ans[i] = s % 10;
			c = s / 10;
		}
		 
	}
	
}
