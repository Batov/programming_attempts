/*
 * Memory.h
 *
 *  Created on: 18.02.2013
 *      Author: Batov
 */

#ifndef MEMORY_H_
#define MEMORY_H_
#define SizeOfMemory 100
#define SizeOfPage 32
#define MEMORY 15
#include "SVM_data.h"
#include "libstack.h"



tpages* Memory;
tpages* CurPage;
tpages* LastPage;

int getElemMemory(unsigned int adress);
void setElemMemory(unsigned int adress, int value);

#endif /* MEMORY_H_ */
