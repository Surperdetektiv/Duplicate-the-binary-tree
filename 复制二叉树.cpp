#include<stdlib.h>
#include<iostream>
#define Maxsize 100
#include<stdio.h>
using namespace std;
typedef struct BiNode
{
	char data;
	BiNode *lc, *rc;
}BiNode, *BiTree;

void Creat(BiTree &T)
{
	char c;
	cin >> c;
	if (c == '*')
	{
		T = NULL;
	}
	else
	{
		T = new BiNode;
		T->data = c;
		Creat(T->lc);
		Creat(T->rc);
	}
}

BiTree gettree(char da, BiNode *lptr, BiNode *rptr)
{
	BiTree T;
	T = (BiNode *)malloc(sizeof(BiNode));
	if (!T )
		exit (- 1);
	T->data = da;
	T->lc = lptr;
	T->rc = rptr;

	return T;
}
BiTree CopyTree(BiTree &T)
{
	BiTree newlptr=NULL, newrptr=NULL,newtree=NULL;
	if (!T)
		return NULL;
	if (T)
	{
		if (T->lc)
			newlptr = CopyTree(T->lc);
		else
			newlptr = NULL;
		if (T->rc)
			newrptr = CopyTree(T->rc);
		else
			newrptr = NULL;

		newtree = gettree(T->data, newlptr, newrptr);
	}
	return newtree;
	
}

void Inorder(BiTree &T)
{
	if (T)
	{
		
		Inorder(T->lc);
		cout << T->data << " ";

		Inorder(T->rc);
	}
}

int main()
{
	BiTree T,p;
	Creat(T);
	Inorder(T);
	cout << "\n";
	p=CopyTree(T);
	Inorder(p);
	return 0;
}