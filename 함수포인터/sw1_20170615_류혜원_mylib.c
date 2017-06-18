#include "sw1_20170615_류혜원_mylib.h"

int readInputFile_getDataNumber(const char *filename)
{
	FILE *fp;
	char tp_name[10];
	char tp_phone[20];
	char tp_email[20];
	int i;
	fp=fopen(filename,"r");
	if(fp==NULL){
		puts("File open Error");
	}
	i=0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %s\n",tp_name,tp_phone,tp_email);
		i++;
	}
	return i;
}

void readInputFile_loadData(const char *fn,Person *p, int number){
	int i;
	FILE *fp;
	fp=fopen(fn,"r");
	if(fp==NULL){
		printf("file open error");
	}
	for(i=0; i<number; i++){
		fscanf(fp,"%s %s %s\n",p[i].name,p[i].phone,p[i].email);
	}
}

void writeInputFile(const char *filename, Person *p, int number){

	int i;
	FILE *fp;
	fp=fopen(filename,"w+");
	if(fp==NULL){
		printf("file open error");
	}

	for(i=0; i<number; i++){
		fprintf(fp,"%s %s %s\n",p[i].name,p[i].phone,p[i].email);
	}
	printf("결과 >>%s\n",filename);
}
int printAllPersons(Person *p,int number){
	int i=0;
		printf("총(%d): %-10s %-20s %-20s\n",number,"이름","전화번호","이메일");
		printf("-----------------------------------------------------------\n");
	for(i=0; i< number ; i++){
		printf("[%d] : %-10s %-20s %-20s\n",i+1,p[i].name,p[i].phone,p[i].email);
	}
	return number;
}



void makeSampleInput(const char *filename){
	int i;
	FILE *fp;
	Person sample[3]={{"KIM","010-1111-1111","kim@mobis.co.kr"},
		{"LEE","010-2222-2222","lee@mobis.co.kr"},
	{"MIN","010-1111-1111","min@mobis.co.kr"}};
	fp=fopen(filename,"w+");
	for(i=0; i<3; i++){
		fprintf(fp,"%-11s %-21s %-21s\n",sample[i].name,sample[i].phone,sample[i].email);
	}
	fclose(fp);
	
}
void printMenu(){
	printf("\n-------------------------메뉴-------------------\n");
	printf("1.입력    \t");
	printf("2.조회    \t");
	printf("3.수정    \n");
	printf("4.삭제    \t");
	printf("5.전체출력\t");
	printf("6.종료 \n");
	printf("--------------------------------------------------\n");
}

int getMenu(){
	int menu;
	printMenu();
	printf("입력 : ");
	scanf("%d",&menu);
	return menu;
}

int createPerson(Person * p, int cnt){

	int total_cnt=cnt;
	printf("\n");
	printf("추가할 사람의 이름:");
	fflush(stdin);
	gets(p[cnt-1].name);

	printf("추가할 사람의 전화번호:");
	fflush(stdin);
	gets(p[cnt-1].phone);

	printf("추가할 사람의 이메일:");
	fflush(stdin);
	gets(p[cnt-1].email);

	return total_cnt;
}


int readPerson(Person *p, int cnt){
	int i,j;
	int new_cnt=cnt;
	char tp[20];
	printf("조회할 이름 : ");
	fflush(stdin);
	gets(tp);
	for(i=0; i<cnt; i++){
		if(!strcmp(tp,p[i].name)){
			printf("이름   : %s\t전화번호: %s\t이메일 : %s\n",p[i].name,p[i].phone,p[i].email);
			break;
		}
	}
	if(i==cnt){
		printf("%s이름은 존재하지 않습니다\n",tp);
	}
	return new_cnt;
}


int updatePerson(Person *p, int cnt){
	int i;
	int new_cnt=cnt;
	char tp[20];
	printf("수정할 이름 : ");
	fflush(stdin);
	gets(tp);
	for(i=0; i<cnt; i++){
		if(!strcmp(tp,p[i].name)){
				printf("수정할 번호 : ");
				fflush(stdin);
				gets(p[i].phone);

				printf("수정할 이메일 : ");
				fflush(stdin);
				gets(p[i].email);
				break;
		}
	}
	if(i==cnt){
		printf("%s이름은 존재하지 않습니다\n",tp);
	}
	return new_cnt;
}

int deletePerson(Person *p, int cnt){
	int i,j;
	int new_cnt=cnt;
	char tp[20];
	printf("삭제할 이름 : ");
	fflush(stdin);
	gets(tp);
	for(i=0; i<cnt; i++){
		if(!strcmp(tp,p[i].name)){
			for(j=i; j<cnt-1; j++){
				p[j]=p[j+1];
			}
			new_cnt--;
			break;
		}
	}
	if(i==cnt){
		printf("%s이름은 존재하지 않습니다\n",tp);
	}
	return new_cnt;
}