#include<iostream>
using namespace std;

//Program by Christina Ochsner
//PS#: 1166214

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h> 
#include <stdlib.h> 
#include <iomanip>

using namespace std;

template <class T>
struct Node
{
	T data;
	Node <T>* next=NULL;
};
template <class T>
void add(Node<T>** head, T data)
{
		Node<T>* node = (Node<T>*) malloc(sizeof(Node<T>));

		Node<T> *last = *head;  

		node->data = data;

		node->next = NULL;

		if (*head == NULL)
		{
			*head = node;
			return;
		}

		while (last->next != NULL)
			last = last->next;
		last->next = node;
		return;
}
template <class T>
T deletes(Node <T> **head, int pos)
{
	Node<T>* temp = *head;
	if (*head == NULL)
		return 0;
	if (temp->next==NULL)
	{
		*head = temp->next;  
		T d = temp->data;
		free(temp);             
		return d;
	}
	for (int i = 0; temp != NULL && i < pos - 1; i++)
	{
		temp = temp->next;
	}

	if (temp == NULL || temp->next == NULL)
		return 0;

	Node<T> *next = temp->next->next;
	T item = temp->next->data;
	free(temp->next); 
	temp->next = next;
	return item;
}

template <class T>
void print(Node<T> *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl << endl;
}


int main()
{
	char a[100];
	cin >> a;
	Node <char>* head = NULL;
	Node <char>* head2 = NULL;
	int i = 0;
	while (a[i]!='\0')
	{
		add(&head, a[i]);
		i++;
	}
	cout << "Your list before delete is applied:" << endl;
	print(head);
	int count=1;
	while (count<7)
	{
		cout << "Round " << count << endl;
		for (int u = 1; u<i; u++)
		{
			add(&head2, deletes(&head, u));
		}
		i = (i / 2)+1;
		cout << "starting list: ";
		print(head);
		cout << "removal list: ";
		print(head2);
		count++;
	}
	system("pause");
	return 0;
}