
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

//Инициализация двусвязного списка
list * DoubleLinkedList_init(void){
	list *retList = (list*)malloc(sizeof(list));
	retList->size = 0;
	retList->tail = NULL;
	retList->head = NULL;

	return retList;
}

//Удаление двусвязного списка
void DoubleLinkedList_Delete(list * DelList){
	node * DelNode = DelList->head;
	node * NextNode = NULL;

	//Перебериаем каждый элемент и освобождаем выделнную под него память
	while (DelNode)
	{
		NextNode = DelNode->next;
		free(DelNode);
		DelNode = NextNode;
	}
	//Освобождаем выделенную память под список
	free(DelList);
}

//Добавление в начало списка
void DoubleLinkedList_AddFront(list * DblLnkdLst, int Val){
	node * tmpNode = (node *)malloc(sizeof(node));
	if(tmpNode == NULL){
		exit(1);
	}

	tmpNode->value = Val;					//Записываем значение
	tmpNode->next = DblLnkdLst->head;		//Связываем следующий элемент текущего элемента с головой списка
	tmpNode->prev = NULL;					//Предыдущего элемента нет.

	//Если у головы был элемент, то связываем ccылку на предыдущий элемент со вновь созданным
	if(DblLnkdLst->head){
		DblLnkdLst->head->prev = tmpNode;
	}

	DblLnkdLst->head = tmpNode;				//Присваиваем голове новый элемент

	//Если хвоста не было то связываем хвост списка со вновь созданным элементом
	if(DblLnkdLst->tail == NULL){
		DblLnkdLst->tail = tmpNode;
	}

	//Увеличиваем значение размера списка
	DblLnkdLst->size++;
}

//Удаление из начала списка
int DoubleLinkedList_DelFrornt(list * DblLnkdLst){
	node * prevNode;
	int tmpVal;

	//Проверяем есть ли элемен в голове списка
	if(DblLnkdLst->head == NULL){
		exit(2);
	}

	prevNode = DblLnkdLst->head;					//Присваиваем текущий элемент головы списка во временную переменную
	DblLnkdLst->head = DblLnkdLst->head->next;		//Связываем голову списка со следующим элементом после удаляемого

	//Удаляем связь головы списка с "предыдущим элементом"
	if(DblLnkdLst->head){
		DblLnkdLst->head->prev = NULL;
	}
	//Если предыдущая голова являлась единстыенным элементом очищаем указать на хвост списка
	if(prevNode == DblLnkdLst->tail){
		DblLnkdLst->tail = NULL;
	}
	
	tmpVal = prevNode->value;						//Сохраняем значение удаляемого элемента
	free(prevNode);									//Освобождаем память, выделенную под удаляемый элемент
	DblLnkdLst->size--;								//Уменьшаем значение размера списка

	return tmpVal;									//Возвращаем значение удаленного элемента
}

//Добавление в конец списка
void DoubleLinkedList_AddBack(list * DblLnkdLst, int Val){
	node * tmpNode = (node *)malloc(sizeof(node));
	//Если не получилось выделить память то ошибка
	if(tmpNode == NULL){
		exit(2);
	}

	tmpNode->value = Val;				//Присваимваем значение
	tmpNode->next = NULL;				//Следующего элемента нет
	tmpNode->prev = DblLnkdLst->tail;	//Предыдущий элемент - хвост списка

	//Устанавливаем связь хвоста списка с новым элементом как "следующий"
	if(DblLnkdLst->tail){
		DblLnkdLst->tail->next = tmpNode;
	}

	DblLnkdLst->tail = tmpNode;			//Хвост списка связываем с вной созданным элементом

	//Если добавляемый элемент первый, то цепляем его к голове списка
	if(DblLnkdLst->head == NULL){		
		DblLnkdLst->head = tmpNode;
	}

	DblLnkdLst->size++;					//Увеличиваем размер списка

}

//Удаление из конца списка
int DoubleLinkedList_DelBack(list * DblLnkdLst){
	node * tmpNode;
	int tmpVal;

	//Если у хвоста нет элемента то ошибка - удалять нечего
	if(DblLnkdLst->tail == NULL){
		exit(4);
	}

	tmpNode = DblLnkdLst->tail;							//Сохраняем текущий элемент хвоста списка во временную переменную
	DblLnkdLst->tail = DblLnkdLst->tail->prev;			//Связываем хвост с предыдущим от текущего элемента
	//Если у нового хвоста есть связ со следующим элементом то удалям
	if(DblLnkdLst->tail){
		DblLnkdLst->tail->next = NULL;
	}
	//Если удаляемый элемент является головйо списка то очищаем
	if(tmpNode == DblLnkdLst->head){
		DblLnkdLst->head = NULL;
	}

	tmpVal = tmpNode->value;							//Сохраняем значение удаляемого элемента
	free(tmpNode);										//Освобождаем память, выделенную под удаляемый элемент
	DblLnkdLst->size--;									//Уменьшаем значение размера списка
	return tmpVal;										//Возвращаем значение удаленного элемента
}

//Найти эелмент по его порядковому номеру в двусвязном списке
void * DoubleLinkedList_GetNthNode(list * DblLnkdLst, unsigned int NodeIndex){
	node * tmpNode = DblLnkdLst->head;
	unsigned int i = 0;

	//Уменьшаем на один если больше нуля для правильного обращения к списку
	if(NodeIndex > 0){
		NodeIndex--;
	}

	//Если индекс искомого элемента больше половины списка ищем с середины вверх
	if(NodeIndex < DblLnkdLst->size/2){
		while (tmpNode && i < NodeIndex)
		{
			tmpNode = tmpNode->next;
			i++;
		}
	} else {
		i = DblLnkdLst->size -1;
		tmpNode = DblLnkdLst->tail;
		while (tmpNode && i > NodeIndex){
			tmpNode = tmpNode->prev;
			i--;
		}		
	}
	
	return tmpNode;														//Возвращаем найденный элемент или первый
}

//вставить элемент после указанного по его порядковому номеру
void DoubleLinkedList_AddAfter(list * DblLnkdLst, unsigned int index, int nodeVal){
	node * prevNode = NULL;
	node * insNode = NULL;

	//Получаем элемент по инедксу. Если такого нет, то ошибка
	prevNode = DoubleLinkedList_GetNthNode(DblLnkdLst, index);
	if(prevNode == NULL){
		exit(5);
	}
	
	insNode = (node *)malloc(sizeof(node));		//Создаем вставляемый элемент
	insNode->value = nodeVal;					//Присваиваем значение
	insNode->prev = prevNode;					//Связываем вставляемый элемент с найденным по индексу
	insNode->next = prevNode->next;				//Связываем вставляемый элемент со следующим, с которым связан найденный по индексу

	//Связываем слудеющий элемент от найденного по индекску с вновь созданным
	if(prevNode->next){
		prevNode->next->prev = insNode;
	}

	//Связываем найденный элемент со вновь созданным
	prevNode->next = insNode;
	//Если вновь созданный элемент явлеется первым, то связываем его с головой списка
	if(!insNode->prev){
		DblLnkdLst->head = insNode;
	}
	//Если вновь созданный элемент является последним, то связываем его с хвостом списка
	if(!insNode->next){
		DblLnkdLst->tail = insNode;
	}

	DblLnkdLst->size++;							//Увеличиваем значение размера списка
}

//Удлаить указанный элемент по его порядковому номеру
int DoubleLinkedList_DeleteNode(list * DblLnkdLst, unsigned int delIndex){
	node * delNode;
	int tmpVal;

	delNode = DoubleLinkedList_GetNthNode(DblLnkdLst, delIndex);			//Ищем элемент по индексу, который будем удалить
	//Если не найдено. Выходим. Ошибка
	if(delNode == NULL){
		exit(5);
	}										
	
	//Слудющий элемент связываем с предыдущим относительно удаляемого
	if(delNode->prev){
		delNode->prev->next = delNode->next;
	}
	//Предыдущий элемент связываем со следующим относительно удаляемого
	if(delNode->next){
		delNode->next->prev = delNode->prev;
	}

	tmpVal = delNode->value;												//Сохраняем значение удаляемого элемента

	//Если удаляемый элемент является первым, то к голове списка привязываем следующий элемент
	if(!delNode->prev){
		DblLnkdLst->head = delNode->next;
	}

	//Если удаялемый элемент является последним, то к хвосту списка привязываем предыдущий элемент
	if(!delNode->next){
		DblLnkdLst->tail = delNode->prev;
	}

	free(delNode);															//Освобождаем память, выделенную удаляемому элементу
	DblLnkdLst->size--;														//Уменьшаем значение размера списка

	return tmpVal;
}

//Найти элемент по значению
void * DoubleLinkedList_SearchNode(list * DblLnkdLst, int sValue){	
	node * tmpNode = NULL;	

	tmpNode = DblLnkdLst->head;

	while (tmpNode)
	{
		if(tmpNode->value == sValue){
			return tmpNode;
		} else {
			tmpNode = tmpNode->next;
		}
	}

	return tmpNode;
	
}

//Вывод целочисленного значения
void PrintInt(int val){
	printf("%d ", val);
}


//Ввыод начальный значений
list * DoubleLinkedList_SetDefaults(void){
	printf("Инициализация двусвязного списка...\n");
	DblLnkdLst = DoubleLinkedList_init();

	for(unsigned int i = 0; i < sizeof(inpData)/sizeof(inpData[0]); i++){
		inpData[i] = (i+1) * 10;
	}
	
	//Инициализируем переменные со значениями

	printf("Начальные данные: ");
	for(unsigned int i = 0; i < sizeof(inpData)/sizeof(inpData[0]); i++){
		printf("%d, ", inpData[i]);
	}
	printf("\n\n");

	return DblLnkdLst;
}

								/* Работа с выводом информации */

//Печать списка (вывод на экран)
void DoubleLinkedList_PrintList(list * inputDblLkdLst){
	node * prntNode = inputDblLkdLst->head;
	//Перебираем все эелементы и выводим значения на экран
	
	while (prntNode)
	{
		PrintInt(prntNode->value);
		prntNode = prntNode->next;
	}
	
	printf("\n\r");
}

//Поиск и вывод элемента на экран по его значению
void DoubleLinkedList_SearchAndPrintByVal(list * DblLnkdLst, int sVal){
	int head_val = -1;
	int tail_val = -1;

	printf("Ищем элемент со значением %d...\n\r", sVal);
	node * srNode = DoubleLinkedList_SearchNode(DblLnkdLst, sVal);
	if(srNode == NULL){
		printf("Элемент со значением %d не найден!\n\r", sVal);		
	} else {
		printf("Найден элемент со значением %d!  ", sVal);		

		if(srNode != DblLnkdLst->head){
			head_val = srNode->prev->value;
		}
		if(srNode != DblLnkdLst->tail){
			tail_val = srNode->next->value;
		}
			printf("%d %d %d\n\r\n\r", head_val, srNode->value, tail_val);				
	}
}

//Вывод информации о двусвязанном списке
void DoubleLinkedList_PrintListInfo(list * DblLnkdLst){
		printf("Значения двусвязного списка: ");
		//Печать списка
		DoubleLinkedList_PrintList(DblLnkdLst);
		printf("Размер списка: %d\n\r\n\r", DblLnkdLst->size);
}

