
/*
*
*	Name: Work wiyh double linked list
*	Date: 26.07.2021
*	Author: Kostyaev Gregory
*	
*/

#include "stdio.h"

#ifndef _FUNCS
#define _FUNCS

//Структура элемента списка
typedef struct _Node{
	int value;
	struct _Node *next;
	struct _Node *prev;
} node; 

//Структура двусявзного списка
typedef struct _list{
	unsigned int size;
	node * head;
	node * tail;
} list; 

list * DblLnkdLst;
unsigned int inpData[8];

									/* Работа с двусвязным списком */
//Инициализация двусвязного списка
list * DoubleLinkedList_init(void);
//Удаление двусвязного списка
void DoubleLinkedList_Delete(list * DelList);
//Добавление в начало списка
void DoubleLinkedList_AddFront(list * DblLnkdLst, int Val);
//Удаление из начала списка
int DoubleLinkedList_DelFrornt(list * DblLnkdLst);
//Добавление в конец списка
void DoubleLinkedList_AddBack(list * DblLnkdLst, int Val);
//Удаление из конца списка
int DoubleLinkedList_DelBack(list * DblLnkdLst);
//Найти эелмент по его порядковому номеру в двусвязном списке
void * DoubleLinkedLis_GetNthNode(list * DblLnkdLst, unsigned int NodeIndex);
//Вставить элемент после указанного
void DoubleLinkedList_AddAfter(list * DblLnkdLst, unsigned int index, int nodeVal);
//Удалить элемент по его порядковому номеру
int DoubleLinkedList_DeleteNode(list * DblLnkdLst, unsigned int delIndex);
//Найти эелмент по его порядковому номеру в двусвязном списке
void * DoubleLinkedList_GetNthNode(list * DblLnkdLst, unsigned int NodeIndex);
//Найти элемент по значению
void * DoubleLinkedList_SearchNode(list * DblLnkdLst, int sValue);
//Сортировка списка
list * DoubleLinkedList_SortByValue(list * inputDblLnkdLst);
//Ввыод начальный значений
list * DoubleLinkedList_SetDefaults(void);


								/* Работа с выводом информации */

//Печать списка (вывод на экран)
void DoubleLinkedList_PrintList(list * inputDblLnkdLst);
//Вывод информации о двусвязанном списке
void DoubleLinkedList_PrintListInfo(list * DblLnkdLst);
//Поиск и вывод элемента на экран по его значению
void DoubleLinkedList_SearchAndPrintByVal(list * DblLnkdLst, int sVal);

#endif
