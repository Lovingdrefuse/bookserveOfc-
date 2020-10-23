#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct People {
	char pNo[5];	//��Ա���
	char pName[10];	//��Ա����
	int pAge;	//����
	char sex[5];	//�Ա�
	char tel[15];	//�绰
	int readNum=0;	//�����鼮����
};
struct PeopleNode {
	struct People data;	//������
	struct PeopleNode* next;	//ָ����
};
//������
struct PeopleNode* createPeopleList() {
	struct PeopleNode* headNode = (struct PeopleNode*)malloc(sizeof(struct PeopleNode));
	headNode->next = NULL;
	return headNode;
}
//�����ڵ�
struct PeopleNode* createPeopleNode(struct People data) {
	struct PeopleNode* newNode = (struct PeopleNode*)malloc(sizeof(struct PeopleNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//���ҹ���(���ز��ҵ��Ľṹ��ָ��)(����)

struct PeopleNode* searchPeopleByName(struct PeopleNode* headNode, char* name) {
	struct PeopleNode* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.pName, name)) {
		if (pMove->next == NULL) {
			//cout << "111111111111" << endl;
			return NULL;
		}
		pMove = pMove->next;
	}
	return pMove;
}

struct PeopleNode* searchPeopleByNo(struct PeopleNode* headNode, char* name) {
	struct PeopleNode* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.pNo, name)) {
		if (pMove->next == NULL) {
			//cout << "111111111111" << endl;
			return NULL;
		}
		pMove = pMove->next;
	}
	return pMove;
}
struct PeopleNode* searchPeopleByTel(struct PeopleNode* headNode, char* name) {
	struct PeopleNode* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.tel, name)) {
		if (pMove->next == NULL) {
			//cout << "111111111111" << endl;
			return NULL;
		}
		pMove = pMove->next;
	}
	return pMove;
}
//����ڵ�
void insertPeopleNodeByHead(struct PeopleNode* headNode, struct People data) {
	struct PeopleNode* newNode = createPeopleNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//ָ��λ��ɾ��(������)
void deletePeopleNode(struct PeopleNode* headNode, char* name) {
	//����posNode��ʼ���в���
	struct PeopleNode* posNode = headNode->next;
	//���ҽڵ��ǰһ���ڵ�
	struct PeopleNode* posFrontNode = headNode;
	if (posNode == NULL) {
		cout << "����Ϊ�գ��޷�ɾ����" << endl;
		return;
	}
	while (strcmp(posNode->data.pName, name)) {
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
void printPeopleList(struct PeopleNode* headNode) {
	struct PeopleNode* pMove = headNode->next;
	while (pMove) {
		cout << "��Ա��\t��Ա��\t��Ա����\t��Ա�Ա�\t��ϵ�绰\t���Ĵ���" << endl;
		cout <<pMove->data.pNo<<"\t"<< pMove->data .pName<<"\t"<< pMove->data .pAge<<"\t\t"<< pMove->data .sex<<"\t\t"<< pMove->data .tel<< "\t\t"<<pMove->data.readNum<<endl;
		pMove = pMove->next;
	}
	cout << endl;
}
void OrderByVipBorrow(struct PeopleNode* headNode) {
	struct PeopleNode* p = NULL;
	struct PeopleNode* q = NULL;
	struct PeopleNode* t = NULL;
	if (headNode == NULL || headNode->next == NULL) {
		return;
	}
	for(p=headNode;p!=NULL;p=p->next){
		for (q = headNode->next; q->next != NULL; q = q->next) {
			if (q->data.readNum < q->next->data.readNum) {
				swap(q->data, q->next->data);
			}
		}
	}
	printPeopleList(headNode);
}
//�ļ�������
void readPeopleFromFile(struct PeopleNode* headNode, const char* fileName) {
	//�ļ��������� 
	//1�����ļ�
	FILE* fp;
	struct	People data;
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		cout << "δ�ҵ��ļ�" << endl;
		fp = fopen(fileName, "w+");
	}
	//���ļ�
	while (fscanf(fp, "%s\t%s\t%d\t%s\t%s\t%d\n",data.pNo,data.pName,&data.pAge,data.sex,data.tel,&data.readNum) != EOF) {
		insertPeopleNodeByHead(headNode, data);
	}
	fclose(fp);
}
//�ļ�д����
void writePeopleToFile(struct PeopleNode* headNode, const char* fileName) {
	FILE* fp;
	fp = fopen(fileName, "w");
	struct PeopleNode* pMove = headNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%d\t%s\t%s\t%d\n", pMove->data.pNo,pMove->data.pName ,pMove->data.pAge , pMove->data.sex ,pMove->data.tel,pMove->data.readNum);
		pMove = pMove->next;
	}
	fclose(fp);
}