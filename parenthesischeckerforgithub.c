#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct stack{
	int data[100];
	int top;
}stack;
void push(stack *,char);
int pop(stack *);	
int main()
{
	stack s1;
	s1.top=-1;
	int i;
	char item[100] ;
	gets(item);
	for(i=0;i<strlen(item);i++)
	{
	if(item[i]=='[' || item[i]=='{' || item[i]=='(')
	{
		push(&s1,item[i]);
		continue;
	}
	else if(item[i]==')' || item[i]=='}' || item[i]==']')
	{			
	if(item[i]==')')
	{
	if(s1.data[s1.top]=='(')
	{
		pop(&s1);
	}
	else
	{
		printf("\nNot Balanced\n");
		break;
	}
	}
	if(item[i]=='}')
	{
	if(s1.data[s1.top]=='{')
	{
		pop(&s1);
	}
	else
	{
		printf("Not Balanced\n");
		break;
	}
	}
	if(item[i]==']')
	{
	if(s1.data[s1.top]=='[')
	{
		pop(&s1);
	}
	else
	{
		printf("Not Balanced\n");
		break;
	}
	}
	}
	}
	if(s1.top==-1)		
		printf("\nStack is balanced");
	return 0;
}
void push(stack *p,char item)
{
	p->top++;
	p->data[p->top]=item;
}
int pop(stack *p)
{
	char item;
	if(p->top==-1)
	{
		printf("\nUnerflow\n");	
	}
	else
	{
	item=p->data[p->top];
	p->top--;	
	}
	return item;
}



