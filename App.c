/*****************************************/
/* Author  :  Abdullah Mohamed  soliman  */
/* Version :  V01                        */
/* Date    : 30 Dec 2021                 */
/*****************************************/
#include<stdio.h>
#include"typedef.h"
extern unit8_t teminal_read_DateCheck(void) ;
extern void Read_Card(void)    ;
extern void TransactionData(void) ;
extern void ServerData(void)   ;
void main()
{	
while(1)
{
unit8_t res=0;
unit8_t mark =0;
ServerData();
 Read_Card();
res= teminal_read_DateCheck();
	if(res == 1)
		printf("The Transaction is APPROVED\n");
	else
		printf("The Transaction is DECLINED\n");
	TransactionData();
    printf("Do you want to continue (y/n)\n");
	fflush(stdin);
	scanf("%c",&mark);
	
	if(mark == 'n')
		break;
}	
}