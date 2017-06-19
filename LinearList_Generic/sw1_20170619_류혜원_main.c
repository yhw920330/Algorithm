#include "LinearList.h"
#include "sw1_20170619_류혜원_struct.h"
int main(){
	

	Array nameArr, gradeArr;
	int i=0;
	int grade_input[10] = {  100		,80		,80		,40		,90,	60		,88, 50,	10		,15};
	char name_input[][20]= {"A Kim", "C Kim", "B Ryu", "B Kim", "Zay", "Gil", "Kai", "Min","Joy", "Anne"};
	
	//Create Array 
	CreateArray(&nameArr, 10, sizeof(name_input[0]));
	CreateArray(&gradeArr, 10, sizeof(GradeStruct));
	printf(" Create Array - name \t Capacity [%d] \t Length : %d\n", nameArr.GetCapacity(&nameArr), nameArr.GetLength(&nameArr));
	printf(" Create Array - grade \t Capacity [%d] \t Length : %d\n", gradeArr.GetCapacity(&gradeArr), gradeArr.GetLength(&gradeArr));

	
	//Append and Insert item to Each Array 
	for(i=0; i< 8; i++){
		nameArr.AppendArray( &nameArr, &name_input[i] );
		gradeArr.AppendArray( &gradeArr, &grade_input[i] );
	}
	nameArr.InsertArray(&nameArr,"Min",&name_input[8] , cmp_str);
	gradeArr.InsertArray(&gradeArr,&grade_input[7],&grade_input[8],compare_grade);

	nameArr.InsertIndexArray(&nameArr,8, &name_input[9]);
	gradeArr.InsertIndexArray(&gradeArr,8, &grade_input[9]);


	//store initail idx of GradeStruct
	for(i=0 ; i< 10 ; i++){
		GradeStruct *p = gradeArr.front;
		p[i].initial_idx =i;
		p[i].rank = 0;
	}
	


	//Sorting
	gradeArr.SortArray(&gradeArr, compare_grade);
	setRank(&gradeArr);
	
	printf("\n------------------입력순 출력--------------\n");
	printfByInputIndex(&nameArr, &gradeArr);


	printf("\n------------------성적순 출력--------------\n");
	printfByRankIndex(&nameArr, &gradeArr);
	

	nameArr.DeleteArray(&nameArr,"Kai",cmp_str);
	gradeArr.DeleteIndexArray(&gradeArr,0);
	
//	nameArr.TraverseArray(&nameArr,print_str);
//	gradeArr.TraverseArray(&gradeArr,print_GradeStruct);

	DeleteAllArray(&nameArr);
	DeleteAllArray(&gradeArr);

	Destroy(&nameArr);
	Destroy(&gradeArr);

	return 0;
}


