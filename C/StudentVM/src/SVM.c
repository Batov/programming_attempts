/*
 ============================================================================
 Name        : StudentVM.c
 Author      : Batov
 Version     :
 Copyright   : SPBSU, 171 gr
 Description : Virtual Machine
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libstack.h"
#include "SVM_data.h"
#include "Memory.h"
#define WRONGNAME 3
#define ARGUMENT 7
#define WRONGINPUT 0
#define DIVISIONBYZERO 5
#define SIZEOFSTR 256

tlabel* Labels = NULL;
tlabel* CurrentLabel = NULL;
tlabel* LastLabel = NULL;

//char* ClearString(char* instr) //������ ������ �� �������� � ������������
// {
//while(instr[0] == ' ')
//    {
//    instr = instr+1;
//    }
//int i=0;
//while(instr[i] != '\0')
//    {
//    if (instr[i] == ';')
//	{
//
//	instr = savehead (instr,i);
//	return instr;
//	}
//    i++;
//    }
//return instr;
// }

char* slashhead(char* instr, int count) //������� ��������
    {
    int i;
    int inlen = strlen(instr);
    if (instr[inlen - 1] == '\n')
	instr[inlen - 1] = '\0';
    char* res = malloc(8 * sizeof(char));
    for (i = count - 1; i <= inlen; i++)
	{

	res[i - count] = instr[i];
	}

    return res;
    }

char* savehead(char* instr, int count) //������� ��������
    {
    int i;
    char* res = malloc(4 * sizeof(char));

    for (i = 0; i < count; i++)
	{
	res[i] = instr[i];
	}
    res[i] = '\0';
    return res;
    }
float mpow(float a, int n)
    {
    int i;
    float answr;
    answr = 1;
    for (i = 0; i < abs(n); i++)
	{
	answr = answr * a;
	}
    if (n < 0)
	answr = 1 / answr;
    return answr;
    }
int strtoint(char* str, int Number)
    {
    int rslt, i;
    rslt = 0;
    if (!str)
	error(ARGUMENT, Number);
    int stl = strlen(str);
    for (i = 0; i < stl; i++)
	{

	if (isdigit(str[i]))
	    rslt = rslt + (str[i] - '0') * mpow(10, stl - 1 - i);
	else
	    error(ARGUMENT, Number);

	}
    return rslt;
    }

tcommand Processing_Labels(char* string, int Number)
    {
    char Current_char;
    int i = 0;
    int len = strlen(string);
    while ((i <= len) && (Current_char != ':'))
	{
	Current_char = string[i++];
	}

    if (Current_char == ':')
	{
	if (len == i + 1)
	    {

	    tcommand res; //����� ��������� ����� � ������� �� � �������!
	    res.TypeOfCommand = labdef;
	    res.arg.label = malloc(50);
	    string = savehead(string, strlen(string) - 2); //��������� ��������� � \n
	    strcpy(res.arg.label, string);
	    //------------
	    //�������� �������
	    if (Labels == NULL)
		{
		Labels = malloc(sizeof(tlabel));
		Labels->NumberOfStrings = Number;
		Labels->label = res.arg.label;
		Labels->next = NULL;
		LastLabel = Labels;
		}
	    else
		{
		CurrentLabel = malloc(sizeof(tlabel));
		CurrentLabel->NumberOfStrings = Number;
		CurrentLabel->label = res.arg.label;
		CurrentLabel->next = NULL;
		LastLabel->next = CurrentLabel;
		LastLabel = CurrentLabel;
		}
	    //------------
	    return res;
	    }
	else
	    error(WRONGNAME, Number);
	}
    tcommand res;
    res.TypeOfCommand = 0;
    return res;
    }

tcommand Processing_Commands(char* string, int Number)
    {
    tcommand result;
    char* com;
    if ((string[2] == ' '))
	{
	com = savehead(string, 2);
	string = slashhead(string, 3);
	}
    else if (string[3] == ' ')
	{
	com = savehead(string, 3);
	string = slashhead(string, 4);
	}
    else if ((string[3] == '\n') || (string[3] == '\0'))
	{
	com = savehead(string, 3);
	string = "";
	}
    else
	{
	com = string;
	}
    if ((!strcmp(com, "ldc")))
	{
	result.TypeOfCommand = ldc;
	result.arg.number = strtoint(string, Number);
	}
    else if (!strcmp(com, "ld"))
	{
	result.TypeOfCommand = ld;
	result.arg.address = strtoint(string, Number);
	}
    else if (!strcmp(com, "st"))
	{
	result.TypeOfCommand = st;
	result.arg.address = strtoint(string, Number);
	}
    else if (!strcmp(com, "add"))
	{
	result.TypeOfCommand = add;
	if (strtoint(string, Number))
	    error(ARGUMENT, Number);
	}
    else if (!strcmp(com, "sub"))
	{
	result.TypeOfCommand = sub;
	if (strtoint(string, Number))
	    error(ARGUMENT, Number);
	}
    else if (!strcmp(com, "mul"))
	{
	result.TypeOfCommand = mul;
	if (strtoint(string, Number))
	    error(ARGUMENT, Number);
	}
    else if (!strcmp(com, "div"))
	{
	result.TypeOfCommand = dv;
	if (strtoint(string, Number))
	    error(ARGUMENT, Number);
	}
    else if (!strcmp(com, "mod"))
	{
	result.TypeOfCommand = mod;
	if (strtoint(string, Number))
	    error(ARGUMENT, Number);
	}
    else if (!strcmp(com, "cmp"))
	{
	result.TypeOfCommand = cmp;
	if (strtoint(string, Number))
	    error(ARGUMENT, Number);
	}
    else if (!strcmp(com, "jmp"))
	{
	result.TypeOfCommand = jmp;
	result.arg.label = string;
	}
    else if (!strcmp(com, "br"))
	{
	result.TypeOfCommand = br;
	result.arg.label = string;
	}
    else if (!strcmp(com, "hlt"))
	{
	result.TypeOfCommand = hlt;
	if (strtoint(string, Number))
	    error(WRONGINPUT, Number);
	}
    else
	{
	error(WRONGINPUT, Number);
	}

    return result;
    }

tcommand lexer(char* string, int Number)
    {
    //======================================================
    while (string[0] == ' ')  //������� ������ �� �������� � ������
	{
	string = string + 1;
	}
    int i = 0;
    do       //������� ������ �� ������������
	{
	if (string[i] == ';')
	    {
	    string = savehead(string, i);
	    }
	}
    while (string[i++] != '\0');
    i -= 2;
    do
	{
	if (string[i] == ' ')
	    {
	    string[i] = '\0';
	    }
	}
    while (string[--i] == ' ');

//=================================================================
    tcommand result = Processing_Labels(string, Number);
    if (result.TypeOfCommand)
	{
	return result;
	}
    else  // ���� ��� �� ����� ������ ��� �������
	{
	result = Processing_Commands(string, Number);
	}
    return result;
    }

str* MoveOnLabel(tcommand CurCommand, str* root)
    {
//����� ����� � �������
    CurrentLabel = Labels;
    str* CurrentString = root;
    while (strcmp(CurrentLabel->label, CurCommand.arg.label)
	    || (CurrentString == NULL))
	{
	CurrentLabel = CurrentLabel->next;
	}

    while (CurrentLabel->NumberOfStrings != CurrentString->NumberOfStrings)
	{
	CurrentString = CurrentString->next;
	}
    return CurrentString;
    }

str* Load_and_Processing_Code(char* NameOfFile)
    {
    FILE* file = fopen(NameOfFile, "r");
    str * start = NULL;
    str* cur;
    str* last;
    char CurStr[50];
    int Number = 0;
    if (file == NULL)
	return NULL;
    while (!feof(file))
	{
	fgets(CurStr, 50, file);
	Number++;
	if (CurStr[0] != '\n')
	    {
	    if (start == NULL)
		{
		start = malloc(sizeof(str));
		start->command = lexer(CurStr, Number);
		start->NumberOfStrings = Number;
		last = start;
		}
	    else
		{
		cur = NULL;
		cur = malloc(sizeof(str));
		cur->command = lexer(CurStr, Number);
		cur->NumberOfStrings = Number;
		last->next = cur;
		last = cur;
		}
	    }
	}
    last->next = NULL;
    fclose(file);
    return start;
    }

int Run(str* root)
    {
    InitStack();
    str* CurrentString = root;
    int IP = 1;
    if (root == NULL)
	return 1;
    while (1)
	{

	switch (CurrentString->command.TypeOfCommand)
	    {
	case ldc:
	    {
	    push(CurrentString->command.arg.number);
	    CurrentString = CurrentString->next;
	    IP = CurrentString->NumberOfStrings;
	    break;
	    }
	case ld:
	    {
	    push(getElemMemory(CurrentString->command.arg.address));
	    CurrentString = CurrentString->next;
	    IP = CurrentString->NumberOfStrings;
	    break;
	    }
	case st:
	    {
	    setElemMemory(CurrentString->command.arg.address, pop());
	    IP = CurrentString->NumberOfStrings;
	    CurrentString = CurrentString->next;
	    break;
	    }
	case add:
	    {
	    push(pop() + pop());
	    CurrentString = CurrentString->next;
	    IP = CurrentString->NumberOfStrings;
	    break;
	    }
	case sub:
	    {
	    int temp = pop();
	    push(pop() - temp);
	    CurrentString = CurrentString->next;
	    IP = CurrentString->NumberOfStrings;
	    break;
	    }

	case mul:
	    {
	    push(pop() * pop());
	    CurrentString = CurrentString->next;
	    IP = CurrentString->NumberOfStrings;
	    break;
	    }
	case dv:
	    {
	    int temp = pop();
	    if (temp != 0)
		push(pop() / temp);
	    else
		error(DIVISIONBYZERO, CurrentString->NumberOfStrings);
	    CurrentString = CurrentString->next;
	    IP = CurrentString->NumberOfStrings;
	    break;
	    }
	case mod:
	    {
	    int temp = pop();
	    if (temp != 0)
		push(pop() % temp);
	    else
		error(DIVISIONBYZERO, CurrentString->NumberOfStrings);
	    CurrentString = CurrentString->next;
	    IP = CurrentString->NumberOfStrings;
	    break;
	    }
	case cmp:
	    {
	    int a = pop();
	    int b = pop();
	    if (a > b)
		push(-1);
	    if (a == b)
		push(0);
	    if (a < b)
		push(1);

	    CurrentString = CurrentString->next;
	    IP = CurrentString->NumberOfStrings;
	    break;
	    }
	case jmp:
	    {
	    CurrentString = MoveOnLabel(CurrentString->command, root);
	    IP = CurrentString->NumberOfStrings;
	    break;
	    }
	case br:
	    {
	    if (pop() != 0)
		{
		CurrentString = MoveOnLabel(CurrentString->command, root);
		IP = CurrentString->NumberOfStrings;
		}
	    else
		{
		CurrentString = CurrentString->next;
		IP = CurrentString->NumberOfStrings;
		}
	    break;
	    }
	case hlt:
	    {
	    printf("%d", pop());
	    return 0;
	    break;
	    }
	case labdef:
	    {
	    CurrentString = CurrentString->next;
	    IP = CurrentString->NumberOfStrings;
	    break;
	    }
	    }
	if (CurrentString == NULL)
	    return 0;
	}
    return 0;
    }

int Clear(str* root)
    {
    free(root);
    free(Labels);
    //������!!!
    CloseStack();
    return 0;
    }

int main()
    {
    str * root = Load_and_Processing_Code("prime.svm");
    Run(root);
    Clear(root);
    return 0;
    }
