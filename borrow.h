#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct Borrow {
	char bNo[5];	//绘本编号
	char pNo[10];	//会员编号
	char loanTime[10];	//借出时间
	char returnTIme[10];	//归还时间
};
struct BorrowNode {
	struct Borrow data;	//数据域
	struct BorrowNode* next;	//指针域
};

struct BorrowNode* createBorrowList() {
	struct BorrowNode* headNode = (struct BorrowNode*)malloc(sizeof(struct BorrowNode));
	headNode->next = NULL;
	return headNode;
}
//创建节点
struct BorrowNode* createBorrowNode(struct Borrow data) {
	struct BorrowNode* newNode = (struct BorrowNode*)malloc(sizeof(struct BorrowNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//查找功能(返回查找到的结构体指针)(名称)

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
//插入节点
void insertBorrowNodeByHead(struct BorrowNode* headNode, struct Borrow data) {
	struct BorrowNode* newNode = createBorrowNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//指定位置删除(按姓名)
void deleteBorrowNode(struct BorrowNode* headNode, char* name1,char* name2) {
	//生成posNode开始进行查找
	struct BorrowNode* posNode = headNode->next;
	//查找节点的前一个节点
	struct BorrowNode* posFrontNode = headNode;
	if (posNode == NULL) {
		cout << "数据为空，无法删除！" << endl;
		return;
	}
	while (strcmp(posNode->data.bNo, name1)&&strcmp(posNode->data.pNo,name2)) {
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
void printBorrowList(struct BorrowNode* headNode) {
	struct BorrowNode* pMove = headNode->next;
	while (pMove) {
		cout << "绘本编号\t会员姓名\t借出时间\t归还时间" << endl;
		cout << pMove->data.bNo << "\t\t" << pMove->data.pNo << "\t\t" << pMove->data.loanTime << "\t" << pMove->data.returnTIme << endl;
		pMove = pMove->next;
	}
	cout << endl;
}

//文件读操作
void readBorrowFromFile(struct BorrowNode* headNode, const char* fileName) {
	//文件基本操作 
	//1、打开文件
	FILE* fp;
	struct	Borrow data;
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		cout << "未找到文件" << endl;
		fp = fopen(fileName, "w+");
	}
	//读文件
	while (fscanf(fp, "%s\t%s\t%s\t%s\n", data.bNo,data.pNo,data.loanTime,data.returnTIme) != EOF) {
		insertBorrowNodeByHead(headNode, data);
	}
	fclose(fp);
}
//文件写操作
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