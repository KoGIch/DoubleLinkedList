
/*
*
*	Name: Work wiyh double linked list
*	Date: 26.07.2021
*	Author: Kostyaev Gregory
*	
*/
 
#include "stdio.h"
#include "stdlib.h"
#include "funcs.h"


int main(void){
	printf("Пример работы с двусвязными списками\n\r");
	printf("Автор: Костяев Григорий Игоревич\n\r");
	printf("\n\r");

	DblLnkdLst = DoubleLinkedList_SetDefaults();

	printf("Добавляем первые три значения в начало списка по очереди по возрастанию\n\r");
	//Добавляем в начало списка
	for(unsigned int i = 0; i < 3; i++){
		DoubleLinkedList_AddFront(DblLnkdLst, inpData[i]);
	}
	DoubleLinkedList_PrintListInfo(DblLnkdLst);


	printf("Добавляем вторые три значения в конец списка по очереди по возрастанию\n\r");
	//Добавляем в конец списка
	for(unsigned int i = 3; i < 6; i++){
		DoubleLinkedList_AddBack(DblLnkdLst, inpData[i]);
	}

	DoubleLinkedList_PrintListInfo(DblLnkdLst);


	printf("Значение второго элемента: %d\n\r", ((node *)DoubleLinkedList_GetNthNode(DblLnkdLst, 2))->value);
	printf("Значение пятого элемента: %d\n\r\n\r", ((node *)DoubleLinkedList_GetNthNode(DblLnkdLst, 5))->value);
	
	DoubleLinkedList_SearchAndPrintByVal(DblLnkdLst, 40);

	printf("Удаляем первый элемент со значением: %d\n\r",  DoubleLinkedList_DelFrornt(DblLnkdLst));
	printf("Удаляем первый элемент со значением: %d\n\r", DoubleLinkedList_DelFrornt(DblLnkdLst));
	
	DoubleLinkedList_PrintListInfo(DblLnkdLst);

	printf("Удаляем последний элемент со значением: %d\n\r", DoubleLinkedList_DelBack(DblLnkdLst));
	printf("Удаялем последний элемент со значением: %d\n\r", DoubleLinkedList_DelBack(DblLnkdLst));
		
	DoubleLinkedList_PrintListInfo(DblLnkdLst);


	printf("Вставляем значение 70 после первого элемента\n\r");
	DoubleLinkedList_AddAfter(DblLnkdLst, 1, inpData[6]);	
	DoubleLinkedList_PrintListInfo(DblLnkdLst);


	printf("Вставляем значение 80 после второго элемента\n\r");
	DoubleLinkedList_AddAfter(DblLnkdLst, 2, inpData[7]);
	DoubleLinkedList_PrintListInfo(DblLnkdLst);


	printf("Удаляем значение после второго элемента\n\r");
	DoubleLinkedList_DeleteNode(DblLnkdLst, 2);
	DoubleLinkedList_PrintListInfo(DblLnkdLst);
				

	printf("Удаляем двусвязный список...\n\r");
	//Удаляем список
	DoubleLinkedList_Delete(DblLnkdLst);


	getchar();
	return 0;
}

