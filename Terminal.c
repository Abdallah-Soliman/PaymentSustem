/*****************************************/
/* Author  :  Abdullah Mohamed  soliman  */
/* Version :  V01                        */
/* Date    : 30 Dec 2021                 */
/*****************************************/

#include<stdio.h>

#include"typedef.h"

     /*Card Data*/

typedef struct ST_card_t
{
	unit8_t cardHolderName[25] ;
	unit8_t primaryAccountNumber[20] ;
	unit8_t cardExpirationDate[6];
	
}ST_cardData_t;


   /*terminal Data*/

 typedef struct ST_terminalData
{
	 f32 transAmount;
	 f32 maxTransAmount ;
	unit8_t transactionDate[11];
}ST_terminalData_t;    
	 
	 
  /*transaction data*/
typedef enum EN_transStat_t
{  
   DECLINED,
   APPROVED

}EN_transStat_t;

typedef struct ST_transaction_t
{ 
  ST_cardData_t cardHolderData;
  ST_terminalData_t transData;
  EN_transStat_t transStat;

}ST_transaction;	 
	 


     /*server Data*/
       typedef struct ST_acountBalance_t
    { 
     f32 balance;
     unit8_t primaryAccountNumber[20];
     }ST_accountBalance_t;

ST_accountBalance_t st_gserverData[10];
    
	        /*creat object for card data*/
	            ST_cardData_t  Card;
	
	        /*creat object for terminaL data*/
                ST_terminalData_t  terminal;
	
	        /*creat object for transaction data*/
                ST_transaction  Transaction;
				
				
				/*user interface for card input*/
void Read_Card(void)
{
printf("please Enter Card Data:\n");
printf("please Enter Card Holder Name:\n");
    scanf("%s",Card.cardHolderName);
printf("please Enter the Primary Account Number:\n");
	scanf("%s",Card.primaryAccountNumber);
printf("please Enter card Expirt Date:\n");
	scanf("%s",Card.cardExpirationDate);
	
}


                  /*terminal read and excution program*/
unit8_t teminal_read_DateCheck(void)
{
	Transaction.transStat =APPROVED;
unit8_t  error_state=0;

                /*local variable and arrays to convert from ASCI to int*/
            uint32_t  au32_resl_1=0;
            uint32_t  au32_resl_2=0;
            uint32_t  au32_res2_1=0;
            uint32_t  au32_res2_2=0;
          uint32_t au32_arr_transaction_Date[10];
          uint32_t au32_arr_Card_Date[5];
		  
		  
                /*user interface for terminal Data*/   
		  
		  printf("please Enter terminal Data:\n");
          printf("please Enter the transaction amount:\n");
          scanf("%f",&terminal.transAmount);
          printf("please Enter the Transaction Date:\n");
	      scanf("%s",terminal.transactionDate);
	      terminal.maxTransAmount =5000;
	
	
	
	
	
	for(uint32_t itration=0;itration<10;itration++)
	{
		au32_arr_transaction_Date[itration]=terminal.transactionDate[itration]-48;
	}
	 for(uint32_t itration=0;itration<5;itration++)
	{
		au32_arr_Card_Date[itration]=Card.cardExpirationDate[itration]-48;
		
	}
	
	au32_resl_1=(au32_arr_transaction_Date[3]*10)+au32_arr_transaction_Date[4];
	
	au32_resl_2=(au32_arr_transaction_Date[8]*10)+au32_arr_transaction_Date[9];
    
	
	au32_res2_1 = (au32_arr_Card_Date[0]*10) + au32_arr_Card_Date [1] ;
	au32_res2_2= (au32_arr_Card_Date[3]*10) + au32_arr_Card_Date [4] ;
	
	if((au32_res2_2>au32_resl_2) || ((au32_res2_2==au32_resl_2) && (au32_resl_1<au32_res2_1)))
	{
        if((terminal.transAmount )<= (terminal.maxTransAmount))  
		{		
              	uint32_t au32_counter =0;
	         for(uint32_t itration=0;itration<9;itration++)
			 {
			       au32_counter =0;
				 for(uint32_t itration_2=0;itration_2<9;itration_2++)
				 {
					if (st_gserverData[itration].primaryAccountNumber[itration_2] == Card.primaryAccountNumber[itration_2])
					{
						au32_counter++;
						
					}
                    else
                      break;						
				 }
				 
				 if(au32_counter == 9)
				 {
					if(terminal.transAmount <=st_gserverData[itration] .balance)
					{
						error_state =1;
						break;
					}
				else{
			         Transaction.transStat=DECLINED;
		            }			 
                    					  
				 } 
                      
			 }
			 		
		}
		else
			Transaction.transStat=DECLINED;
	}
	else{
            Transaction.transStat=DECLINED; 		
	    }
	return error_state ;
}

        /*Transfer Card Data and Terminal Data To Server*/
void TransactionData(void)
{
	
	for(uint32_t i=0;i<25;i++)
		{
		Transaction.cardHolderData.cardHolderName[i] = Card.cardHolderName[i];
		}
		
		/*Primary account number*/
		for(uint32_t i=0;i<20;i++)
		{
		Transaction.cardHolderData.primaryAccountNumber[i] = Card.primaryAccountNumber[i];
		}
		
		/*Card expiration Data*/
        for(uint32_t i=0;i<6;i++)
		{
		Transaction.cardHolderData.cardExpirationDate[i] = Card.cardExpirationDate[i];
		}
        
		 Transaction.transData.transAmount =terminal.transAmount ;
         Transaction.transData.maxTransAmount =5000;
		 
		for(uint32_t i=0;i<6;i++)
		{
         Transaction.transData.transactionDate[i] =terminal.transactionDate[i];
		}
}


void ServerData(void)
{
	              /*Data server*/
		/***********************************************/		  
		/*	Primary account number & User balance      */
		/***********************************************/
	st_gserverData[0] .primaryAccountNumber[0]='1';
	st_gserverData[0] .primaryAccountNumber[1]='2';
	st_gserverData[0] .primaryAccountNumber[2]='3';
	st_gserverData[0] .primaryAccountNumber[3]='4';
	st_gserverData[0] .primaryAccountNumber[4]='5';
	st_gserverData[0] .primaryAccountNumber[5]='6';
	st_gserverData[0] .primaryAccountNumber[6]='7';
	st_gserverData[0] .primaryAccountNumber[7]='8';
	st_gserverData[0] .primaryAccountNumber[8]='9';
	
	
	st_gserverData[0] .balance=100.00;
	
	
	st_gserverData[1] .primaryAccountNumber[0]='2';
	st_gserverData[1] .primaryAccountNumber[1]='3';
	st_gserverData[1] .primaryAccountNumber[2]='4';
	st_gserverData[1] .primaryAccountNumber[3]='5';
	st_gserverData[1] .primaryAccountNumber[4]='6';
	st_gserverData[1] .primaryAccountNumber[5]='7';
	st_gserverData[1] .primaryAccountNumber[6]='8';
	st_gserverData[1] .primaryAccountNumber[7]='9';
	st_gserverData[1] .primaryAccountNumber[8]='1';
	
	
	st_gserverData[1] .balance=6000.00;
	
	
	
	
	
    st_gserverData[2] .primaryAccountNumber[0]='5';
	st_gserverData[2] .primaryAccountNumber[1]='6';
	st_gserverData[2] .primaryAccountNumber[2]='7';
	st_gserverData[2] .primaryAccountNumber[3]='8';
	st_gserverData[2] .primaryAccountNumber[4]='9';
	st_gserverData[2] .primaryAccountNumber[5]='1';
	st_gserverData[2] .primaryAccountNumber[6]='2';
	st_gserverData[2] .primaryAccountNumber[7]='3';
	st_gserverData[2] .primaryAccountNumber[8]='4';
	
	
	st_gserverData[2] .balance=3250.25;
	
	
	
    st_gserverData[3] .primaryAccountNumber[0]='4';
	st_gserverData[3] .primaryAccountNumber[1]='5';
	st_gserverData[3] .primaryAccountNumber[2]='6';
	st_gserverData[3] .primaryAccountNumber[3]='7';
	st_gserverData[3] .primaryAccountNumber[4]='8';
	st_gserverData[3] .primaryAccountNumber[5]='9';
	st_gserverData[3] .primaryAccountNumber[6]='1';
	st_gserverData[3] .primaryAccountNumber[7]='2';
	st_gserverData[3] .primaryAccountNumber[8]='3';
	
	
	st_gserverData[3] .balance=1500.12;	
	
	
	st_gserverData[4] .primaryAccountNumber[0]='2';
	st_gserverData[4] .primaryAccountNumber[1]='5';
	st_gserverData[4] .primaryAccountNumber[2]='8';
	st_gserverData[4] .primaryAccountNumber[3]='6';
	st_gserverData[4] .primaryAccountNumber[4]='4';
	st_gserverData[4] .primaryAccountNumber[5]='9';
	st_gserverData[4] .primaryAccountNumber[6]='1';
	st_gserverData[4] .primaryAccountNumber[7]='7';
	st_gserverData[4] .primaryAccountNumber[8]='3';
	
	
	st_gserverData[4] .balance=500.00;
	
	
	
	
	
	st_gserverData[5] .primaryAccountNumber[0]='6';
	st_gserverData[5] .primaryAccountNumber[1]='5';
	st_gserverData[5] .primaryAccountNumber[2]='4';
	st_gserverData[5] .primaryAccountNumber[3]='8';
	st_gserverData[5] .primaryAccountNumber[4]='2';
	st_gserverData[5] .primaryAccountNumber[5]='3';
	st_gserverData[5] .primaryAccountNumber[6]='7';
	st_gserverData[5] .primaryAccountNumber[7]='1';
	st_gserverData[5] .primaryAccountNumber[8]='9';
	
	
	st_gserverData[5] .balance=2100.00;
	
	
	
	
	
	
	st_gserverData[6] .primaryAccountNumber[0]='9';
	st_gserverData[6] .primaryAccountNumber[1]='7';
	st_gserverData[6] .primaryAccountNumber[2]='1';
	st_gserverData[6] .primaryAccountNumber[3]='3';
	st_gserverData[6] .primaryAccountNumber[4]='6';
	st_gserverData[6] .primaryAccountNumber[5]='2';
	st_gserverData[6] .primaryAccountNumber[6]='4';
	st_gserverData[6] .primaryAccountNumber[7]='8';
	st_gserverData[6] .primaryAccountNumber[8]='5';
	
	
	st_gserverData[6] .balance=0.00;
	
	
	
	
	
	st_gserverData[7] .primaryAccountNumber[0]='7';
	st_gserverData[7] .primaryAccountNumber[1]='9';
	st_gserverData[7] .primaryAccountNumber[2]='3';
	st_gserverData[7] .primaryAccountNumber[3]='1';
	st_gserverData[7] .primaryAccountNumber[4]='4';
	st_gserverData[7] .primaryAccountNumber[5]='8';
	st_gserverData[7] .primaryAccountNumber[6]='6';
	st_gserverData[7] .primaryAccountNumber[7]='2';
	st_gserverData[7] .primaryAccountNumber[8]='5';
	
	
	st_gserverData[7] .balance=1.00;
	
	
	
	st_gserverData[8] .primaryAccountNumber[0]='1';
	st_gserverData[8] .primaryAccountNumber[1]='2';
	st_gserverData[8] .primaryAccountNumber[2]='3';
	st_gserverData[8] .primaryAccountNumber[3]='1';
	st_gserverData[8] .primaryAccountNumber[4]='2';
	st_gserverData[8] .primaryAccountNumber[5]='3';
	st_gserverData[8] .primaryAccountNumber[6]='4';
	st_gserverData[8] .primaryAccountNumber[7]='5';
	st_gserverData[8] .primaryAccountNumber[8]='6';
	
	
	st_gserverData[8] .balance=10.12;
	
	
	
	
	
	
	st_gserverData[9] .primaryAccountNumber[0]='4';
	st_gserverData[9] .primaryAccountNumber[1]='5';
	st_gserverData[9] .primaryAccountNumber[2]='6';
	st_gserverData[9] .primaryAccountNumber[3]='7';
	st_gserverData[9] .primaryAccountNumber[4]='8';
	st_gserverData[9] .primaryAccountNumber[5]='9';
	st_gserverData[9] .primaryAccountNumber[6]='3';
	st_gserverData[9] .primaryAccountNumber[7]='2';
	st_gserverData[9] .primaryAccountNumber[8]='1';
	
	
	st_gserverData[9] .balance=0.55;
	
	
	
	
}