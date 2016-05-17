#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct _employee{
	char employee_id[7];
	int score;
}employee;

int main(int argc,char *argv[]) {
	struct _employee* employee_list;
	int i;
	srand((unsigned)time(NULL));

	int total_num=0;
	sscanf(argv[1], "%d", &total_num);
	

	//insert data
	employee_list = (struct _employee *) malloc(sizeof(struct _employee)*total_num);
	for (i = 0; i < total_num; i++) {
		sprintf(employee_list[i].employee_id, "NT%05d", rand() % 100000);
		employee_list[i].score = rand() % 100;
	}
	

	//print data
	for (i = 0; i < total_num; i++) {
		printf("%7s %d\n", employee_list[i].employee_id, employee_list[i].score);
	}

}