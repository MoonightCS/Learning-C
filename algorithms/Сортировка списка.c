#include <stdlib.h>
#include <stdio.h>


struct Vector
{
	int key;
	struct Vector *next;
};

void Insert(struct Vector *curr, int key)
{
	struct Vector *temp;
	temp = (struct Vector *) malloc (sizeof(struct Vector));
    temp->key = key;
	temp->next = curr->next;
	curr->next = temp;
	return;
}

void Delete(struct Vector *curr)
{
	curr->next = (curr->next)->next;
	return;
}


struct Vector* Merge (struct Vector *list1, struct Vector *list2)
{
	struct Vector uzel;
	struct Vector *temp = &uzel;
	
	uzel.next = NULL;
	uzel.key = 0;
    
	while (list1 != NULL && list2 != NULL)
	{
        if (list1->key > list2->key)
		{
			temp->next = list2;
			temp = temp->next;
			list2 = list2->next;
		}
		else
		{
            temp->next = list1;
			temp = temp->next;;
			list1 = list1->next;
		}
	}
    
	if (list1 != NULL)
		temp->next = list1;
	else
        if (list2 != NULL)
            temp->next = list2;
	
	return uzel.next;
};

struct Vector* MergeSort(struct Vector* current)
{
	int n = 0, count;
	if (current->next != NULL)
	{
		struct Vector *temp, *list1, *list2;
        temp = current;
        
		while (temp!=NULL)
		{
			n++;
			temp=temp->next;
		}
        
		list1 = current;
        list2 = current;
        
		count = n/2-1;
		
		while (count > 0)
		{
			list2 = list2->next;
            count--;
		}
        
		temp = list2;
		list2 = list2->next;
		temp->next = NULL;
        
		list1 = MergeSort(list1);
		list2 = MergeSort(list2);
		return Merge(list1,list2);
	}
	return current;
}

int main()
{
	
    
	int key, n, i;
	struct Vector *begin = (struct Vector *)malloc(sizeof(struct Vector));
	struct Vector *current;
    
    current = begin;
    
	begin->key = 0;
	begin->next = NULL;
    
	scanf("%d", &n);
    
	for (i = 0; i < n; i++)
	{
		scanf("%d", &key);
		Insert(current, key);
		current = current->next;
	}
    
	begin->next = MergeSort(begin->next);
    
	current = begin->next;
    
	for (i = 0; i < n; i++)
	{
		printf("%d ", current->key);
		current = current->next;
	}
    
	current = begin;
    
	while (current->next != NULL)
        Delete(current);
	
	free(begin);
    
	return 0;
}
