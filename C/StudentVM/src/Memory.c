/*
 * Memory.c
 *
 *  Created on: 18.02.2013
 *      Author: Batov
 */

#include "Memory.h"

int GetStatusOfMemory(int adress)
 {

    int test = ((CurPage->BitInit) >> (adress % SizeOfPage) & 1);
 return test ;
 }


 void SetStatusOfMemory(int adress)
 {

     CurPage->BitInit = (1 << (adress % SizeOfPage)) | (CurPage->BitInit);
     int test = CurPage->BitInit;
 }

void initFirst() // ������ ������
    {
    Memory = malloc(sizeof(tpages));  //���� ��� ������ �������� ������
    Memory->NumofPage = 0;
    Memory->page = 0x0;
    Memory->BitInit = 0;
    LastPage = Memory;
    CurPage = Memory;
    }
void initOther() // ��������� �������
    {
    CurPage = malloc(sizeof(tpages)); // ��������� ������� ��� �������
    CurPage->NumofPage = LastPage->NumofPage + 1;
    CurPage->page = 0x0;
    CurPage->BitInit = 0;
    LastPage->next = CurPage;
    LastPage = CurPage;
    }

int initPage(int page)
    {
    //Memory = CurPage;
    do
	{
	if (LastPage == 0x0)
	    {
	    initFirst();
	    }
	else
	    {
	    if (LastPage->NumofPage < page)
		{
		initOther();
		}
	    else
		return 0; // ���� ������ ��� ������
	    }
	}
    while ((CurPage->NumofPage != page));
    return 0;
    }

int getElemMemory(unsigned int adress)
    {
    CurPage = Memory;
    if (Memory == 0x0)
	{
	error(MEMORY, 0);
	}
    while (CurPage->NumofPage != adress / SizeOfPage)
	{
	CurPage = CurPage->next;
	}
    if (CurPage->page == 0x0)
	error(MEMORY, 0);
    else
	if (GetStatusOfMemory(adress))
	return CurPage->page->page[adress % SizeOfPage];
	else
	    error(MEMORY, 0);
    return 0;
    }

void setElemMemory(unsigned int adress, int value)
    {

    initPage(adress / SizeOfPage);
    if (CurPage->page->page == 0x0) //���� � ������� ��� ��������
	{
	CurPage->page = malloc(sizeof(tpage));
	CurPage->page->page[adress % SizeOfPage] = value;
	SetStatusOfMemory(adress);
	}
    else
	{
	if (CurPage->NumofPage == adress / SizeOfPage) // ���� � ������� ��� ���� ��������
	    {
	    CurPage->page->page[adress % SizeOfPage] = value;
	    SetStatusOfMemory(adress);
	    }
	else
	    {
	    CurPage = Memory;
	    while (CurPage->NumofPage < adress / SizeOfPage) // ���� ������� ���� �������� � �����-�� �������� ����������
		{
		CurPage = CurPage->next;
		}
	    CurPage->page = malloc(sizeof(tpage));
	    CurPage->page->page[adress % SizeOfPage] = value;
	    SetStatusOfMemory(adress);
	    }
	}
    }
