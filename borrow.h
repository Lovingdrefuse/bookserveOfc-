#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct Borrow {
	char bNo[5];	//�汾���
	char pNo[10];	//��Ա���
	char loanTime[10];	//���ʱ��
	char returnTIme[10];	//�黹ʱ��
};
struct BorrowNode {
	struct Borrow data;	//������
	struct BorrowNode* next;	//ָ����
};

struct BorrowNode* createBorrowList() {
	struct BorrowNode* headNode = (struct BorrowNode*)malloc(sizeof(struct BorrowNode));
	headNode->next = NULL;
	return headNode;
}
//�����ڵ�
struct BorrowNode* createBorrowNode(struct Borrow data) {
	struct BorrowNode* newNode = (struct BorrowNode*)malloc(sizeof(struct BorrowNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//���ҹ���(���ز��ҵ��Ľṹ��ָ��)(����)

struct BorrowNode* searchBorrowByName(struct BorrowNode* headNode, char* name1,char* name2) {
	struct BorrowNode* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.bNo, name1) && strcmp(pMove->data.pNo,name2)) {
		if (pMove->next == NULL) {
			//cout << "111111111111" << endl;
			return NULL;
		}
		pMove = pMove->next;
	}
	return pMove;
}
struct BorrowNode* searchBorrowBybNo(struct BorrowNode* headNode, char* bNo) {
	struct BorrowNode* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.bNo, bNo)) {
		if (pMove->next == NULL) {
			//cout << "111111111111" << endl;
			return NULL;
		}
		pMove = pMove->next;
	}
	return pMove;
}
struct BorrowNode* searchBorrowBypNo(struct BorrowNode* headNode, char* pNo) {
	struct BorrowNode* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	while (strcmp(pMove->data.pNo, pNo)) {
		if (pMove->next == NULL) {
			//cout << "111111111111" << endl;
			return NULL;
		}
		pMove = pMove->next;
	}
	return pMove;
}
//����ڵ�
void insertBorrowNodeByHead(struct BorrowNode* headNode, struct Borrow data) {
	struct BorrowNode* newNode = createBorrowNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//ָ��λ��ɾ��(������)
void deleteBorrowNode(struct BorrowNode* headNode, char* name1,char* name2) {
	//����posNode��ʼ���в���
	struct BorrowNode* posNode = headNode->next;
	//���ҽڵ��ǰһ���ڵ�
	struct BorrowNode* posFrontNode = headNode;
	if (posNode == NULL) {
		cout << "����Ϊ�գ��޷�ɾ����" << endl;
		return;
	}
	while (strcmp(posNode->data.bNo, name1)&&strcmp(posNode->data.pNo,name2)) {
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
void printBorrowList(struct BorrowNode* headNode) {
	struct BorrowNode* pMove = headNode->next;
	while (pMove) {
		cout << "�汾���\t��Ա����\t���ʱ��\t�黹ʱ��" << endl;
		cout << pMove->data.bNo << "\t\t" << pMove->data.pNo << "\t\t" << pMove->data.loanTime << "\t" << pMove->data.returnTIme << endl;
		pMove = pMove->next;
	}
	cout << endl;
}

//�ļ�������
void readBorrowFromFile(struct BorrowNode* headNode, const char* fileName) {
	//�ļ��������� 
	//1�����ļ�
	FILE* fp;
	struct	Borrow data;
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		cout << "δ�ҵ��ļ�" << endl;
		fp = fopen(fileName, "w+");
	}
	//���ļ�
	while (fscanf(fp, "%s\t%s\t%s\t%s\n", data.bNo,data.pNo,data.loanTime,data.returnTIme) != EOF) {
		insertBorrowNodeByHead(headNode, data);
	}
	fclose(fp);
}
//�ļ�д����
void writeBorrowToFile(struct BorrowNode* headNode, const char* fileName) {
	FILE* fp;
	fp = fopen(fileName, "w");
	struct BorrowNode* pMove = headNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%s\n", pMove->data.bNo,pMove->data.pNo, pMove->data.loanTime,pMove->data.returnTIme);
		pMove = pMove->next;
	}
	fclose(fp);
}