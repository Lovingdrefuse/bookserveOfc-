#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct Book {
	char  bNo[5];	//�汾���
	char bName[20];	//�汾����
	char author[20];	//����
	char press[100];	//������
	char outTime[20];	//����ʱ��
	double price;	//�۸�
	char language[10];	//����
	int age;	//�ʺ�����
	int isBorrow;	//���״̬
	int borNum=0;	//���Ĵ���
};

struct BookNode {
	struct Book data;		//������
	struct BookNode* next;	//ָ����
};
//������
struct BookNode* createList() {
	struct BookNode* headNode = (struct BookNode*)malloc(sizeof(struct BookNode));
	headNode->next = NULL;
	return headNode;
}
//�����ڵ�
struct BookNode* createNode(struct Book data) {
	struct BookNode* newNode= (struct BookNode*)malloc(sizeof(struct BookNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//���ҹ���(���ز��ҵ��Ľṹ��ָ��)(����)

struct BookNode* searchBookByName(struct BookNode* headNode,char* name) {
	struct BookNode* pMove = headNode->next;
	//cout << pMove->data.bName;
	if (pMove == NULL) {
		cout << "δ�ҵ������ƻ汾��" << endl;
		return NULL;
	}
	while (strcmp(pMove->data.bName,name)) {
		if (pMove->next == NULL) {
			//cout << "111111111111" << endl;
			return NULL;
		}
		pMove = pMove->next;
	}
	return pMove;
}
struct BookNode* searchBookByNo(struct BookNode* headNode, char* name) {
	struct BookNode* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.bNo, name)) {
		if (pMove->next == NULL) {
			//cout << "111111111111" << endl;
			return NULL;
		}
		pMove = pMove->next;
	}
	return pMove;
}
struct BookNode* searchBookByAuthor(struct BookNode* headNode, char* name) {
	struct BookNode* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.author, name)) {
		if (pMove->next == NULL) {
			//cout << "111111111111" << endl;
			return NULL;
		}
		pMove = pMove->next;
	}
	return pMove;
}

//����ڵ�
void insertBookNodeByHead(struct BookNode* headNode,struct Book data) {
	struct BookNode* newNode = createNode(data);
	newNode ->next = headNode->next;
	headNode->next = newNode;
}
//ָ��λ��ɾ��(������)
void deleteBookNode(struct BookNode* headNode,char* name) {
	//����posNode��ʼ���в���
	struct BookNode* posNode = headNode->next;
	//���ҽڵ��ǰһ���ڵ�
	struct BookNode* posFrontNode = headNode;
	if (posNode == NULL) {
		cout << "����Ϊ�գ��޷�ɾ����" << endl;
		return;
	}
	while (strcmp(posNode->data.bName,name)) {
		posFrontNode = posNode;
		posNode = posFrontNode->next;
		if (posNode == NULL) {
			cout << "û�ҵ�ָ��λ�ã��޷�ɾ����" << endl;
			return;
		}
	}
	//�ҵ���
	posFrontNode->next = posNode->next;
	free(posNode);
}
//��ӡ����
void printBookList(struct BookNode* headNode) {
	struct BookNode* pMove = headNode->next;
	while (pMove) {
		cout << "�汾���\t�汾��\t����\t������\t\t����ʱ��\t�۸�\t����\t�ʺ�����\t���״̬\t���Ĵ���"<<endl;
		cout << pMove->data.bNo << "\t\t" << pMove->data.bName << "\t" << pMove->data.author << "\t" << pMove->data.press << "\t\t"
			<< pMove->data.outTime << "\t" << pMove->data.price << "\t" << pMove->data.language << "\t" << pMove->data.age << "\t\t"
			<< pMove->data.isBorrow << "\t\t" << pMove->data.borNum << endl;

		pMove = pMove->next;
	}
}
void OrderByBookBorrow(struct BookNode* headNode) {
	struct BookNode* p = NULL;
	struct BookNode* q = NULL;
	struct BookNode* t = NULL;
	if (headNode == NULL || headNode->next == NULL) {
		return;
	}
	for (p = headNode; p != NULL; p = p->next) {
		for (q = headNode->next; q->next != NULL; q = q->next) {
			if (q->data.borNum < q->next->data.borNum) {
				swap(q->data, q->next->data);
			}
		}
	}
	printBookList(headNode);
}
void OrderByBookAge(struct BookNode* headNode) {
	struct BookNode* p = NULL;
	struct BookNode* q = NULL;
	struct BookNode* t = NULL;
	if (headNode == NULL || headNode->next == NULL) {
		return;
	}
	for (p = headNode; p != NULL; p = p->next) {
		for (q = headNode->next; q->next != NULL; q = q->next) {
			if (q->data.age < q->next->data.age) {
				swap(q->data, q->next->data);
			}
		}
	}
	printBookList(headNode);
}
//�ļ�������
void readBookFromFile(struct BookNode* headNode, const char* fileName) {
	//�ļ��������� 
	//1�����ļ�
	FILE* fp;
	struct	Book data;
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		cout << "δ�ҵ��ļ�" << endl;
		fp=fopen(fileName, "w+");
	}
	//���ļ�
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%lf\t%s\t%d\t%d\t%d\n", data.bNo, data.bName, data.author, data.press,
		data.outTime, &data.price, data.language, &data.age, &data.isBorrow,&data.borNum)!=EOF) {
		insertBookNodeByHead(headNode, data);
	}
	fclose(fp);
}
//�ļ�д����
void writeBookToFile(struct BookNode* headNode, const char* fileName) {
	FILE* fp;
	fp = fopen(fileName, "w");
	struct BookNode* pMove = headNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%lf\t%s\t%d\t%d\t%d\n", pMove->data.bNo, pMove->data.bName, 
			pMove->data.author, pMove->data.press, pMove->data.outTime,pMove->data.price,pMove->data.language,
			pMove->data.age, pMove->data.isBorrow,pMove->data.borNum);
		pMove = pMove->next;
	}
	fclose(fp);
}