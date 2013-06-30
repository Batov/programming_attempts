/*
 * SVM_data.h
 *
 *  Created on: 13.02.2013
 *      Author: Batov
 */

#ifndef SVM_DATA_H_
#define SVM_DATA_H_


enum commands // ��������� �������
    {
    ldc = 2,
    ld,
    st,
    add,
    sub,
    mul,
    dv,
    mod,
    cmp,
    jmp,
    br,
    hlt,
    labdef,
    } lex;

typedef struct //���� �������
    {
	int TypeOfCommand;
	union
	    {
		int number;
		unsigned int address;
		char* label;
	    } arg;
    } tcommand;

typedef struct tstr //���� ������
    {
	int NumberOfStrings;
	tcommand command;
	struct tstr* next;
    } str;


    typedef struct tlab //���� ������
        {
    	int NumberOfStrings;
    	char* label;
    	 struct tlab* next;
        } tlabel;


typedef struct tpage
    {
    int page[32];
    } tpage ;

typedef struct tpages
    {
    tpage* page;
    int NumofPage;
    int BitInit;
    struct tpages* next;
    } tpages;


#endif /* SVM_DATA_H_ */
