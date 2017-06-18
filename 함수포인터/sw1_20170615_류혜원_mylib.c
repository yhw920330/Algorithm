#include "sw1_20170615_������_mylib.h"

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
	printf("��� >>%s\n",filename);
}
int printAllPersons(Person *p,int number){
	int i=0;
		printf("��(%d): %-10s %-20s %-20s\n",number,"�̸�","��ȭ��ȣ","�̸���");
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
	printf("\n-------------------------�޴�-------------------\n");
	printf("1.�Է�    \t");
	printf("2.��ȸ    \t");
	printf("3.����    \n");
	printf("4.����    \t");
	printf("5.��ü���\t");
	printf("6.���� \n");
	printf("--------------------------------------------------\n");
}

int getMenu(){
	int menu;
	printMenu();
	printf("�Է� : ");
	scanf("%d",&menu);
	return menu;
}

int createPerson(Person * p, int cnt){

	int total_cnt=cnt;
	printf("\n");
	printf("�߰��� ����� �̸�:");
	fflush(stdin);
	gets(p[cnt-1].name);

	printf("�߰��� ����� ��ȭ��ȣ:");
	fflush(stdin);
	gets(p[cnt-1].phone);

	printf("�߰��� ����� �̸���:");
	fflush(stdin);
	gets(p[cnt-1].email);

	return total_cnt;
}


int readPerson(Person *p, int cnt){
	int i,j;
	int new_cnt=cnt;
	char tp[20];
	printf("��ȸ�� �̸� : ");
	fflush(stdin);
	gets(tp);
	for(i=0; i<cnt; i++){
		if(!strcmp(tp,p[i].name)){
			printf("�̸�   : %s\t��ȭ��ȣ: %s\t�̸��� : %s\n",p[i].name,p[i].phone,p[i].email);
			break;
		}
	}
	if(i==cnt){
		printf("%s�̸��� �������� �ʽ��ϴ�\n",tp);
	}
	return new_cnt;
}


int updatePerson(Person *p, int cnt){
	int i;
	int new_cnt=cnt;
	char tp[20];
	printf("������ �̸� : ");
	fflush(stdin);
	gets(tp);
	for(i=0; i<cnt; i++){
		if(!strcmp(tp,p[i].name)){
				printf("������ ��ȣ : ");
				fflush(stdin);
				gets(p[i].phone);

				printf("������ �̸��� : ");
				fflush(stdin);
				gets(p[i].email);
				break;
		}
	}
	if(i==cnt){
		printf("%s�̸��� �������� �ʽ��ϴ�\n",tp);
	}
	return new_cnt;
}

int deletePerson(Person *p, int cnt){
	int i,j;
	int new_cnt=cnt;
	char tp[20];
	printf("������ �̸� : ");
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
		printf("%s�̸��� �������� �ʽ��ϴ�\n",tp);
	}
	return new_cnt;
}