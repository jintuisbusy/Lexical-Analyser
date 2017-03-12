#include<stdio.h>
#include<ctype.h>
#include<string.h>

//*************************** CREATED BY JINTU KUMAR DAS *********************************************
//---------------------- DATE : 3/11/2017 ----------------------------------
// KNOWN ISSUE : Duplicate values not handled 


main(void)
{
    FILE *open;
    open = fopen("assembly.txt", "r");		//Replace assembly.txt with your assembly language text file
    FILE *write;
    write = fopen("tokens.txt", "w");		//Tokens will stored in this file (Autogenerated)
    FILE *a;
    
    //Declaring string arrays
    
	char *mn[50] = {"ADD","DIV","MULT","SUB","READ","MOV","START","STOP"};	//Mnemonic codes
	char *reg [50]= {"AREG","BREG","CREG","DREG"};				//Registors
	char *symbols[50] = {"!","#","%","$",",","'"};				//Symbols
	char *aDir[50] = {"DS","DC","LTORG","ORIGIN","EQU"};			//Assembly directives
	
    char ch;
    char str[127];	//String buffer
    int i;

	//Reading content of assembly file

    while ((ch = fgetc(open)) != EOF)
    {
        if (ch == 32 || ch == ',')			//If space found start new line  or if , found write it on the file
          if(ch == ',')	
            fprintf(write, "\n,\n");
          else
		  	fprintf(write,"\n");  
				
		else
            fprintf(write, "%c", ch);		//Write individual characters till space or , found
    }

	
	//Closing file stream

    fclose(write);
    fclose(open);
    
    a = fopen("tokens.txt", "r");		//Pointing to token file

    while (!feof(a))	 //Reading content of tokens.txt
    {
    	int m = 0,r = 0,sym=0,dir=0;
    	
        if (fgets(str, 126, a)){	//Getting first line from token file
        	
        //checking mnemonic code	
          for(i=0;i<8;i++){
		   	
		   	int res = strncmp(str,mn[i],3);		//Comparing the string upto 3 digits
		   	
			if(res == 0){			
				 
				   printf("%s : Mnemonic code",str);
				   m = 1;			
        	}
		}
		
		printf("\n");

		//checking registors
		  for(i=0;i<4;i++){
		   
			int res = strncmp(str,reg[i],4);	   
		   
		   	if(res == 0){
				 
				   printf("%s : Register",str); 
				   r = 1;
				}
        }
        
			printf("\n");  
			
		
		//checking symbols
		  for(i=0;i<6;i++){
		   
			int res = strncmp(str,symbols[i],1);	   
		   
		   	if(res == 0){
				 
				   printf("%s : Symbol",str); 
				   sym = 1;
				}
        }
        
			printf("\n"); 	


		//checking assembly directive
		  for(i=0;i<5;i++){
		   
			int res = strncmp(str,aDir[i],2);	   
		   
		   	if(res == 0){
				 
				   printf("%s : Assembly directive ",str); 
				   dir = 1;
				}
        }
        
			printf("\n"); 				      
        	
        //Checking digits and constant
        
          if(m == 0 && r == 0 && dir == 0 && sym == 0){		//If none of the string matches continue with this if
          	
          		if(isdigit(str[0]))			//Checking for digit
				   printf("%s : Digit ",str);
				
				else				//Operand
				   printf("%s : Operand",str);	   
					
		}
		
		printf("\n");
	          
  	  }
   
	}	//End of token file
	
  fclose(a);	//Closing token file stream
  
}	//Main end
