#ifndef _hw_h
#define _hw_h

#include "LinearList.h"
typedef struct _grade Grade;

typedef struct _grade {
	int score;
	int rank;
	int initial_idx;
}GradeStruct;

int compare_grade ( const void *g1, const void *g2);
void calcuate_rank(Grade *a, int size);

void printfByInputIndex(Array * nameArray, Array *gradeArr); 
void printfByRankIndex(Array* nameArray, Array* gradeArr);
void print_GradeStruct(void *data);
int getRankIndexOfGrade(Array *gradeArr, int initIndex);

void setRank (Array * self);

#endif