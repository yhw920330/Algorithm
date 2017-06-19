#include"sw1_20170619_류혜원_struct.h"
#include "LinearList.h"

int compare_grade ( const void *g1, const void *g2){
	int s1 = ((GradeStruct *)g1)->score;
	int s2 = ((GradeStruct *)g2)->score;
	return s2-s1;

}

void setRank (Array * self){
	GradeStruct *tp =(GradeStruct *)(self->front);
	int i=0;
	int rank_tp=1;
	
	tp[0].rank=1;
	for( i=1; i<self ->length; i++) 
	{
		if(tp[i-1].score == tp[i].score){
			tp[i].rank= rank_tp;//동점자 처리 
		}
		else{
			rank_tp ++;
			tp[i].rank = rank_tp;
		}
	}	
}


void printfByInputIndex(Array * nameArr, Array *gradeArr){
	int i;
	int element_size_name = nameArr -> element_size;
	int element_size_grade = gradeArr -> element_size;
	int positionOfGrade;
	for(i=0; i< nameArr->length; i++){
		positionOfGrade = getRankIndexOfGrade(gradeArr,i);
		printf("[%d] %-20s",i+1, (char*)(nameArr->front)+ element_size_name*i);
		print_GradeStruct((char*)(gradeArr->front)+element_size_grade*positionOfGrade);
	}
}

int getRankIndexOfGrade(Array *gradeArr, int initIndex){
	GradeStruct * p = (GradeStruct *)gradeArr->front;
	int i;
	for(i=0; i< gradeArr->length; i++){
		if(p[i].initial_idx == initIndex){
			return i;
		}
	}
	return -1;
}
void printfByRankIndex(Array * nameArr, Array *gradeArr){
	int i;
	GradeStruct *p = (GradeStruct *)gradeArr -> front;
	int element_size_name = nameArr -> element_size;
	int element_size_grade = gradeArr -> element_size;
	for(i=0; i< gradeArr->length; i++){
		int init_idx=p[i].initial_idx;
		printf("[%d] %-20s", i+1, (char*)nameArr->front + element_size_name * init_idx);
		print_GradeStruct(&p[i]);
	}

}
void print_GradeStruct(void *data){
		printf(" %4d (%2d등)\n", ((Grade*) data)->score, ((Grade *)data)->rank); 
}