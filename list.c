/* list.c */
#include <stdlib.h>
#include <string.h>

#include "list.h"

/* list_init */
void list_init(List *list, void (*destroy)(void *data))
{
	/* Initialize the list */
	list->size = 0;
	list->destroy = destroy;
	list_head = NULL;
	list_tail = NULL;

	return;
}

/* list_destroy */
void list_destroy(List *list)
{
	void *data;
	/*Remove each element */
	while(list_size(list) > 0)
	{
		if (list_rem_next(list,NULL,(void **)&data) == 0 && list->destroy != NULL)
			list->destroy(data);
	}
	memset(list,0,sizeof(List));
	return;
}

/* 在list指定的链表中element后面插入一个新元素，如果element设置为NULL，则新元素插入链表头部。*/
int list_ins_next(List *list, ListElmt *element, const void *data)
{
	ListEmlt * new_element;
	if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
		return -1;

	new_element->data = (void *)data;
	if (element == NULL)
	{
		if(list_size(list) == 0)
			list->tail = new_element;

		new_element->next = list->head;
		list->head = new_element;
	}
	else
	{
		if(element->next == NULL)
			list->tail = new_element;

		new_element = element->next;
		element->next = new_element;
	}
	list->size++;
	return 0;
}

/* 移除有list指定的链表中element后的那个元素，如果element设置为NULL，则移除链表头元素。 */
/* data指向所移除的元素中存储的数据，由调用者扶着管理打他所引用的空间。 */
int list_rem_next(List *list, ListElmt * element, void **data)
{
	ListElmt *old_element;
	if (list_size(list) == 0)
		return -1;

	if (element == NULL)
	{
		*data = list->head->data;
		old_element = list->head;
		list->head = list->head->next

		if(list_size(list) == 1)
			list->tail = NULL;
	}
	else
	{
		if (element->next == NULL)
			return -1;

		*data = element->next->data;
		old_element = element->next;
		element->next = element->next->next;

		if(element->next = NULL)
			list->tail = element;
	}
	free (old_element);  

	list->size--;
	return 0;
}