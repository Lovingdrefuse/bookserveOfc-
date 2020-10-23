#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct People {
	char pNo[5];	//会员编号
	char pName[10];	//会员名称
	int pAge;	//年龄
	char sex[5];	//性别
	char tel[15];	//电话
	int readNum=0;	//借阅书籍次数
};
struct PeopleNode {
	struct People data;	//数据域
	struct PeopleNode* next;	//指针域
};
//创建表
struct PeopleNode* createPeopleList() {
	struct PeopleNode* headNode = (struct PeopleNode*)malloc(sizeof(struct PeopleNode));
	headNode->next = NULL;
	return headNode;
}
//创建节点
struct PeopleNode* createPeopleNode(struct People data) {
	struct PeopleNode* newNode = (struct PeopleNode*)malloc(sizeof(struct PeopleNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//查找功能(返回查找到的结构体指针)(名称)

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
//插入节点
void insertPeopleNodeByHead(struct PeopleNode* headNode, struct People data) {
	struct PeopleNode* newNode = createPeopleNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//指定位置删除(按姓名)
void deletePeopleNode(struct PeopleNode* headNode, char* name) {
	//生成posNode开始进行查找
	struct PeopleNode* posNode = headNode->next;
	//查找节点的前一个节点
	struct PeopleNode* posFrontNode = headNode;
	if (posNode == NULL) {
		cout << "数据为空，无法删除！" << endl;
		return;
	}
	while (strcmp(posNode->data.pName, name)) {
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
void printPeopleList(struct PeopleNode* headNode) {
	struct PeopleNode* pMove = headNode->next;
	while (pMove) {
		cout << "会员号\t会员名\t会员年龄\t会员性别\t联系电话\t借阅次数" << endl;
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
//文件读操作
void readPeopleFromFile(struct PeopleNode* headNode, const char* fileName) {
	//文件基本操作 
	//1、打开文件
	FILE* fp;
	struct	People data;
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		cout << "未找到文件" << endl;
		fp = fopen(fileName, "w+");
	}
	//读文件
	while (fscanf(fp, "%s\t%s\t%d\t%s\t%s\t%d\n",data.pNo,data.pName,&data.pAge,data.sex,data.tel,&data.readNum) != EOF) {
		insertPeopleNodeByHead(headNode, data);
	}
	fclose(fp);
}
//文件写操作
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