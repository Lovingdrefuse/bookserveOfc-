#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include "BookList.h"
#include "VIPList.h"
#include "borrow.h"
using namespace std;

void meun() {
	//所有操作都同步到文件
	cout << "----------【绘本之家】----------" << endl;
	cout << "0、退出绘本之家" << endl;
	cout << "1、绘本资料管理" << endl;
	cout << "2、会员信息管理" << endl;
	cout << "3、借阅管理" << endl;
	cout << "4、综合查询" << endl;
	cout << "5、统计分析模块" << endl;
}
struct BookNode* Booklist = createList();
struct PeopleNode* Peoplelist = createPeopleList();
struct BorrowNode* Borrowlist = createBorrowList();

struct Book book;
struct People people;
struct Borrow borrow;

struct BookNode* pMove = NULL;
struct PeopleNode* pMove1 = NULL;
struct BorrowNode* pMove2 = NULL;

void keyDown() {
	int choice = 0;
	int select = 0;
	int select2 = 0;
	fflush(stdin);
	cin >> choice;
	switch (choice) {
	case 0:
		cout << "已退出" << endl;
		exit(0);
		break;
	case 1:
		cout << "----------【绘本资料管理】---------" << endl;
		cout << "1、绘本信息录入" << endl;
		cout << "2、绘本信息修改" << endl;
		cout << "3、绘本删除" << endl;
		cout << "4、绘本信息显示" << endl;
		cout << "5、绘本信息查找" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cout << "请依次输入所需录入的绘本 编号，绘本名，作者，出版社，出版时间，价格，语言，适合年龄，借出状态：" << endl;
			cin >> book.bNo >> book.bName >> book.author >> book.press >> book.outTime >> book.price >> book.language >>book.age >>book.isBorrow;
			//printBookList(Booklist);
			pMove = searchBookByName(Booklist, book.bName);
			if ( pMove != NULL) {
				cout << "该书已经存在！" << endl;
				return;
			}
			else {
				insertBookNodeByHead(Booklist, book);
				cout << "添加成功！" << endl;
			}
			
			break;
		case 2:
			
			cout << "请输入所需修改的绘本名" << endl;
			cin >> book.bName;
			if (searchBookByName(Booklist, book.bName) == NULL) {
				cout << "未找到所需修改的绘本名，请重新输入" << endl;
				return;
			}
			else {
				deleteBookNode(Booklist, book.bName);
				cout << "请依次输入修改后的绘本编号，绘本名，作者，出版社，出版时间，价格，语言，适合年龄，借出状态：" << endl;
				cin >> book.bNo >> book.bName >> book.author >> book.press >> book.outTime >> book.price >> book.language >> book.age >> book.isBorrow;
				insertBookNodeByHead(Booklist, book);
				cout << "修改成功！" << endl;
			}

			break;
		case 3:
			cout << "请输入所需删除的绘本名：" << endl;
			cin >> book.bName;
			deleteBookNode(Booklist, book.bName);
			cout << "删除成功" << endl;
			break;
		case 4:
			printBookList(Booklist);
			break;
		case 5:
			cout << "请输入所需查找的绘本名：" << endl;
			cin >> book.bName;
			pMove = searchBookByName(Booklist, book.bName);
			if (pMove == NULL) {
				cout << "未找到绘本信息!" << endl;
			}
			else {
				cout << "绘本编号\t绘本名\t作者\t出版社\t\t出版时间\t价格\t语言\t\t适合年龄\t借出状态" << endl;
				cout << pMove->data.bNo << "\t\t" << pMove->data.bName << "\t" << pMove->data.author << "\t" << pMove->data.press << "\t\t"
					<< pMove->data.outTime << "\t" << pMove->data.price << "\t" << pMove->data.language << "\t\t" << pMove->data.age << "\t\t"
					<< pMove->data.isBorrow << endl;
			}

			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			
			break;
		}

		break;
	case 2:
		cout << "----------【会员信息管理】---------" << endl;
		cout << "1、会员信息录入" << endl;
		cout << "2、会员信息修改" << endl;
		cout << "3、删除会员信息" << endl;
		cout << "4、会员信息浏览" << endl;
		cout << "5、会员信息查找" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cout << "请依次输入所要录入的会员编号，会员名，年龄，性别，电话号码：" << endl;
			cin >> people.pNo >> people.pName >> people.pAge >> people.sex >> people.tel;
			if (searchPeopleByName(Peoplelist, people.pName) != NULL) {
				cout << "该会员已被录入！" << endl;

			}
			else {
				insertPeopleNodeByHead(Peoplelist, people);
			}
			
			break;
		case 2:
			cout << "请输入所需修改信息的会员姓名：" << endl;
			cin >> people.pName;
			if (searchPeopleByName(Peoplelist, people.pName) == NULL) {
				cout << "未找到相应会员信息！" << endl;
			}
			else {
				deletePeopleNode(Peoplelist, people.pName);
				cout << "请输入新的的会员编号，会员名，年龄，性别，电话号码：" << endl;
				cin >> people.pNo >> people.pName >> people.pAge >> people.sex >> people.tel;
				insertPeopleNodeByHead(Peoplelist, people);
				cout << "修改成功！" << endl;
			}

			break;
		case 3:
			cout << "请输入所需删除的会员姓名：" << endl;
			cin >> people.pName;
			if (searchPeopleByName(Peoplelist, people.pName)==NULL) {
				cout << "未找到相应会员信息！" << endl;
			}
			else {
				deletePeopleNode(Peoplelist, people.pName);
				cout << "删除成功！" << endl;
			}
			break;
		case 4:
			printPeopleList(Peoplelist);
			break;
		case 5:
			cout << "请输入所需查询的会员姓名：" << endl;
			cin >> people.pName;
			pMove1 = searchPeopleByName(Peoplelist, people.pName);
			if (pMove1 == NULL) {
				cout << "未找到相应会员信息！" << endl;
			}
			else {
				cout << "会员号\t会员名\t会员年龄\t会员性别\t联系电话" << endl;
				cout << pMove1->data.pNo << "\t" << pMove1->data.pName << "\t" << pMove1->data.pAge << "\t\t" << pMove1->data.sex << "\t\t" << pMove1->data.tel << endl;
			}
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			
			break;
		}
		break;
	case 3:
		cout << "----------【借阅管理】---------" << endl;
		cout << "1、借阅信息录入" << endl;
		cout << "2、借阅信息修改" << endl;
		cout << "3、借阅信息删除" << endl;
		cout << "4、借阅信息浏览" << endl;
		cout << "5、借阅信息查询" << endl;
		cout << "6、归还绘本" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cout << "请依次输入所需添加的绘本编号，会员号，借出时间：" << endl;
			if (borrow.returnTIme == NULL) {
				strcpy(borrow.returnTIme, "未归还");
			}
			cin >> borrow.bNo >> borrow.pNo >> borrow.loanTime;
			pMove = searchBookByNo(Booklist, borrow.bNo);
			pMove1 = searchPeopleByNo(Peoplelist, borrow.pNo);
			if (pMove->data.isBorrow == 1) {
				cout << "该绘本已被借阅，请等待归还后再进行借阅操作" << endl;
				return;
			}
			else {
				insertBorrowNodeByHead(Borrowlist, borrow);
				pMove->data.borNum += 1;
				pMove->data.isBorrow = 1;
				pMove1->data.readNum += 1;
				book = pMove->data;
				deleteBookNode(Booklist, book.bName);
				insertBookNodeByHead(Booklist, book);
				cout << "添加成功！" << endl;
			}
			break;
		case 2:
			cout << "请依次输入所需删除的绘本编号，会员号：" << endl;
			cin >> borrow.bNo >> borrow.pNo;
			if (searchBorrowByName(Borrowlist, borrow.bNo, borrow.pNo) == NULL) {
				cout << "未找到相应的借阅信息，请重新输入！" << endl;
				return;
			}
			else {
				deleteBorrowNode(Borrowlist, borrow.bNo, borrow.pNo);
				cout << "删除成功！" << endl;
			}
			break;
		case 3:
			cout << "请依次输入所需删除的绘本编号，会员号：" << endl;
			cin >> borrow.bNo >> borrow.pNo;
			deleteBorrowNode(Borrowlist, borrow.bNo, borrow.pNo);
			cout << "删除成功！" << endl;
			break;
		case 4:
			printBorrowList(Borrowlist);
			break;
		case 5:
			cout << "请依次输入所需删除的绘本编号，会员号：" << endl;
			cin >> borrow.bNo >> borrow.pNo;
			pMove2 = searchBorrowByName(Borrowlist, borrow.bNo, borrow.pNo);
			if ( pMove2== NULL) {
				cout << "未找到相应的借阅信息，请重新输入！";
				return;
			}
			else {
				cout << "绘本编号\t会员号\t\t借出时间\t\t归还时间" << endl;
				cout << pMove2->data.bNo << "\t\t" << pMove2->data.pNo << "\t\t" << pMove2->data.loanTime << "\t\t" << pMove2->data.returnTIme << endl;
			}
			break;
		case 6:
			cout << "请依次输入绘本编号，会员号：" << endl;
			cin >> borrow.bNo >> borrow.pNo;
			pMove2 = searchBorrowByName(Borrowlist, borrow.bNo, borrow.pNo);
			if (pMove2 != NULL) {
				borrow = pMove2->data;
				cout << "请输入归还时间：" << endl;
				cin >> borrow.returnTIme;
				fflush(stdin);
				deleteBorrowNode(Borrowlist, borrow.bNo, borrow.pNo);
				insertBorrowNodeByHead(Borrowlist, borrow);
				pMove = searchBookByNo(Booklist, borrow.bNo);
				pMove->data.isBorrow = 0;
				book = pMove->data;
				deleteBookNode(Booklist, book.bName);
				insertBookNodeByHead(Booklist, book);
				cout << "归还成功！" << endl;
			}
		default:
			cout << "输入错误，请重新输入！" << endl;
			
			break;
		}
		break;
	case 4:
		cout << "----------【综合查询】---------" << endl;
		cout << "1、绘本信息查询" << endl;
		cout << "2、会员信息查询" << endl;
		cout << "3、借阅信息查询" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cout << "1、通过绘本编号查询" << endl;
			cout << "2、通过绘本名查询" << endl;
			cout << "3、通过作者查询" << endl;
			cin >> select2;
			switch (select2) {
			case 1:
				cout << "请输入绘本编号：" << endl;
				cin >> book.bNo;
				pMove = searchBookByNo(Booklist, book.bNo);
				if (pMove == NULL) {
					cout << "未找到绘本信息!" << endl;
				}
				else {
					cout << "绘本编号\t绘本名\t作者\t出版社\t\t出版时间\t价格\t语言\t\t适合年龄\t借出状态" << endl;
					cout << pMove->data.bNo << "\t\t" << pMove->data.bName << "\t" << pMove->data.author << "\t" << pMove->data.press << "\t\t"
						<< pMove->data.outTime << "\t" << pMove->data.price << "\t" << pMove->data.language << "\t\t" << pMove->data.age << "\t\t"
						<< pMove->data.isBorrow << endl;
				}

				break;
			case 2:
				cout << "请输入绘本名：" << endl;
				cin >> book.bName;
				pMove = searchBookByName(Booklist, book.bName);
				if (pMove == NULL) {
					cout << "未找到绘本信息!" << endl;
				}
				else {
					cout << "绘本编号\t绘本名\t作者\t出版社\t\t出版时间\t价格\t语言\t\t适合年龄\t借出状态" << endl;
					cout << pMove->data.bNo << "\t\t" << pMove->data.bName << "\t" << pMove->data.author << "\t" << pMove->data.press << "\t\t"
						<< pMove->data.outTime << "\t" << pMove->data.price << "\t" << pMove->data.language << "\t\t" << pMove->data.age << "\t\t"
						<< pMove->data.isBorrow << endl;
				}
				break;
			case 3:
				cout << "请输入作者名：" << endl;
				cin >> book.author;
				pMove = searchBookByAuthor(Booklist, book.author);
				if (pMove == NULL) {
					cout << "未找到绘本信息!" << endl;
				}
				else {
					cout << "绘本编号\t绘本名\t作者\t出版社\t\t出版时间\t价格\t语言\t\t适合年龄\t借出状态" << endl;
					cout << pMove->data.bNo << "\t\t" << pMove->data.bName << "\t" << pMove->data.author << "\t" << pMove->data.press << "\t\t"
						<< pMove->data.outTime << "\t" << pMove->data.price << "\t" << pMove->data.language << "\t\t" << pMove->data.age << "\t\t"
						<< pMove->data.isBorrow << endl;
				}
				break;
			default:
				cout << "输入错误，请重新输入！" << endl;
				
				break;
			}
			break;
		case 2:
			cout << "1、通过会员号查询" << endl;
			cout << "2、通过会员名查询" << endl;
			cout << "3、通过联系电话查询" << endl;
			cin >> select2;
			switch (select2) {
			case 1:
				cout << "请输入会员号：" << endl;
				cin >> people.pNo;
				pMove1 = searchPeopleByNo(Peoplelist, people.pNo);
				if (pMove1 == NULL) {
					cout << "未找到相应会员信息！" << endl;
				}
				else {
					cout << "会员号\t会员名\t会员年龄\t会员性别\t联系电话" << endl;
					cout << pMove1->data.pNo << "\t" << pMove1->data.pName << "\t" << pMove1->data.pAge << "\t\t" << pMove1->data.sex << "\t\t" << pMove1->data.tel << endl;
				}

				break;
			case 2:
				cout << "请输入会员名：" << endl;
				cin >> people.pName;
				pMove1 = searchPeopleByName(Peoplelist, people.pName);
				if (pMove1 == NULL) {
					cout << "未找到相应会员信息！" << endl;
				}
				else {
					cout << "会员号\t会员名\t会员年龄\t会员性别\t联系电话" << endl;
					cout << pMove1->data.pNo << "\t" << pMove1->data.pName << "\t" << pMove1->data.pAge << "\t\t" << pMove1->data.sex << "\t\t" << pMove1->data.tel << endl;
				}
				break;
			case 3:
				cout << "请输入联系电话：" << endl;
				cin >> people.tel;
				pMove1 = searchPeopleByTel(Peoplelist, people.tel);
				if (pMove1 == NULL) {
					cout << "未找到相应会员信息！" << endl;
				}
				else {
					cout << "会员号\t会员名\t会员年龄\t会员性别\t联系电话" << endl;
					cout << pMove1->data.pNo << "\t" << pMove1->data.pName << "\t" << pMove1->data.pAge << "\t\t" << pMove1->data.sex << "\t\t" << pMove1->data.tel << endl;
				}
				break;
			default:
				cout << "输入错误，请重新输入！" << endl;
				
				break;
			}
			break;
		case 3 :
			cout << "1、通过绘本编号查询" << endl;
			cout << "2、通过会员号查询" << endl;
			cin >> select2;
			switch (select2) {
			case 1:
				cout << "请输入绘本编号：" << endl;
				cin >> borrow.bNo;
				pMove2 = searchBorrowBybNo(Borrowlist, borrow.bNo);
				if (pMove2 == NULL) {
					cout << "未找到相应的借阅信息，请重新输入！";
					return;
				}
				else {
					cout << "绘本编号\t会员号\t\t借出时间\t\t归还时间" << endl;
					cout << pMove2->data.bNo << "\t\t" << pMove2->data.pNo << "\t\t" << pMove2->data.loanTime << "\t\t" << pMove2->data.returnTIme << endl;
				}

				break;
			case 2:
				cout << "请输入会员编号：" << endl;
				cin >> borrow.pNo;
				pMove2 = searchBorrowBypNo(Borrowlist,borrow.pNo);
				if (pMove2 == NULL) {
					cout << "未找到相应的借阅信息，请重新输入！";
					return;
				}
				else {
					cout << "绘本编号\t会员号\t\t借出时间\t\t归还时间"<<endl;
					cout << pMove2->data.bNo << "\t\t" << pMove2->data.pNo << "\t\t" << pMove2->data.loanTime << "\t\t" << pMove2->data.returnTIme << endl;
				}
				break;
			default:
				cout << "输入错误，请重新输入！" << endl;
				
				break;
			}
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			
			break;
		}
		break;
	case 5:
		cout << "----------【统计分析模块】---------" << endl;
		cout << "1、会员借阅排名" << endl;
		cout << "2、绘本借阅排名" << endl;
		cout << "3、按照绘本适合年龄排名" << endl;
		cin >> select;
		switch (select) {
		case 1:
			OrderByVipBorrow(Peoplelist);
			break;
		case 2:
			OrderByBookBorrow(Booklist);
			break;
		case 3:
			OrderByBookAge(Booklist);
			
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
	default:
		//cout << "111112" << select << "211111" << endl;
		if (select >= 0 && select <= 5) {
			break;
		}
			cout << "输入错误，请重新输入！" << endl;
		break;
	}
	writeBookToFile(Booklist, "Book.txt");
	writePeopleToFile(Peoplelist, "People.txt");
	writeBorrowToFile(Borrowlist, "Borrow.txt");

}

int main() {
	readBookFromFile(Booklist, "Book.txt");
	readPeopleFromFile(Peoplelist, "People.txt");
	readBorrowFromFile(Borrowlist, "Borrow.txt");
	while (1) {
		meun();
		keyDown();
	}

	return 0;
}