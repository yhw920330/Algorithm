#ifndef _my_lib_h
#define _my_lib_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct __Person {
	char name[10];
	char phone[20];
	char email[20];
}Person;

int  (*function_array[6])(Person *p, int number);

void makeSampleInput(const char *filenam);
void printMenu();
int getMenu();

int readInputFile_getDataNumber(const char *filename);
void readInputFile_loadData(const char *filename,Person *p, int number);
void writeInputFile(const char *filename, Person *p, int number);

int printAllPersons(Person *p,int number);
int createPerson(Person * p, int cnt);
int readPerson (Person *p, int cnt);
int updatePerson(Person *p, int cnt);
int deletePerson(Person *p, int cnt);
#endif