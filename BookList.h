#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct Book {
	char  bNo[5];	//绘本编号
	char bName[20];	//绘本名称
	char author[20];	//作者
	char press[100];	//出版社
	char outTime[20];	//出版时间
	double price;	//价格
	char language[10];	//语言
	int age;	//适合年龄
	int isBorrow;	//借出状态
	int borNum=0;	//借阅次数
};

struct BookNode {
	struct Book data;		//数据域
	struct BookNode* next;	//指针域
};
//创建表
struct BookNode* createList() {
	struct BookNode* headNode = (struct BookNode*)malloc(sizeof(struct BookNode));
	headNode->next = NULL;
	return headNode;
}
//创建节点
struct BookNode* createNode(struct Book data) {
	struct BookNode* newNode= (struct BookNode*)malloc(sizeof(struct BookNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//查找功能(返回查找到的结构体指针)(名称)

struct BookNode* searchBookByName(struct BookNode* headNode,char* name) {
	struct BookNode* pMove = headNode->next;
	//cout << pMove->data.bName;
	if (pMove == NULL) {
		cout << "未找到该名称绘本！" << endl;
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

//插入节点
void insertBookNodeByHead(struct BookNode* headNode,struct Book data) {
	struct BookNode* newNode = createNode(data);
	newNode ->next = headNode->next;
	headNode->next = newNode;
}
//指定位置删除(按姓名)
void deleteBookNode(struct BookNode* headNode,char* name) {
	//生成posNode开始进行查找
	struct BookNode* posNode = headNode->next;
	//查找节点的前一个节点
	struct BookNode* posFrontNode = headNode;
	if (posNode == NULL) {
		cout << "数据为空，无法删除！" << endl;
		return;
	}
	while (strcmp(posNode->data.bName,name)) {
		posFrontNode = posNode;
		posNode = posFrontNode->next;
		if (posNode == NULL) {
			cout << "没找到指定位置，无法删除！" << endl;
			return;
		}
	}
	//找到了
	posFrontNode->next = posNode->next;
	free(posNode);
}
//打印链表
void printBookList(struct BookNode* headNode) {
	struct BookNode* pMove = headNode->next;
	while (pMove) {
		cout << "绘本编号\t绘本名\t作者\t出版社\t\t出版时间\t价格\t语言\t适合年龄\t借出状态\t借阅次数"<<endl;
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
//文件读操作
void readBookFromFile(struct BookNode* headNode, const char* fileName) {
	//文件基本操作 
	//1、打开文件
	FILE* fp;
	struct	Book data;
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		cout << "未找到文件" << endl;
		fp=fopen(fileName, "w+");
	}
	//读文件
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%lf\t%s\t%d\t%d\t%d\n", data.bNo, data.bName, data.author, data.press,
		data.outTime, &data.price, data.language, &data.age, &data.isBorrow,&data.borNum)!=EOF) {
		insertBookNodeByHead(headNode, data);
	}
	fclose(fp);
}
//文件写操作
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