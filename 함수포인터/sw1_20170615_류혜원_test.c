#include "sw1_20170615_류혜원_mylib.h"

int main()
{
	Person *p;
	const char filename[]="data.txt";
	int i;
	int total_num=0;
	int menu;

	//Sample Data
	makeSampleInput(filename);
	
	function_array[0]=createPerson;
	function_array[1]=readPerson;
	function_array[2]=updatePerson;
	function_array[3]=deletePerson;
	function_array[4]=printAllPersons;


	//Read Data text file
	total_num=readInputFile_getDataNumber(filename);
	p=(Person *)malloc(sizeof(Person) *total_num);
	readInputFile_loadData(filename,p,total_num);

	while(1){
		menu=getMenu();
		if(menu==6){
			break;
		}
		if(menu<=0 || menu>6){
			printf("Menu입력 오류입니다\n");
			continue;
		}
		//realloc for insert person
		if(menu==1){
			p=(Person *) realloc(p,sizeof(Person) * ++total_num);
		}

		//함수 호출 
		total_num= function_array[menu-1](p,total_num);
		

		//realloc for delete person
		if(menu==4){
			p=(Person *) realloc(p,sizeof(Person) * total_num);
		}

	}
	writeInputFile(filename,p,total_num);

	free(p);

	return 0;
	//

	
	return 0;
}