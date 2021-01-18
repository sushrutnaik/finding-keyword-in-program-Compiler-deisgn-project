#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
countkey=0;
countid=0;
countop=0;
int isKeyword(char buffer[]){
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
	int i, flag = 0;

	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}

	return flag;
}

int main(){
	char ch, buffer[15], operators[] = "+-*/%=";
	FILE *fp;
	int i,j=0;

	fp = fopen("/Users/sushrutnaik/Desktop/program.txt","r");

	if(fp == NULL){
		printf("error while opening the file\n");
		exit(0);
	}

	while((ch = fgetc(fp)) != EOF){
   		for(i = 0; i < 6; ++i){
   			if(ch == operators[i]){
   				printf("%c is operator\n", ch);
   				countop++;}
   		}

   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;

   				if(isKeyword(buffer) == 1){
   					printf("%s is keyword\n", buffer);
   					countkey++;}
   				else{
   					printf("%s is indentifier\n", buffer);
   					countid++;}
   		}

	}
    printf("\ntotal keywords=%d",countkey);
    printf("\ntotal identifier=%d",countid);
    printf("\ntotal oprator=%d",countop);
    printf("\n total oprator=%d",countop);
    printf("end");
	fclose(fp);

	return 0;
}
