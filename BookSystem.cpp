#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include "BookList.h"
#include "VIPList.h"
#include "borrow.h"
using namespace std;

void meun() {
	//���в�����ͬ�����ļ�
	cout << "----------���汾֮�ҡ�----------" << endl;
	cout << "0���˳��汾֮��" << endl;
	cout << "1���汾���Ϲ���" << endl;
	cout << "2����Ա��Ϣ����" << endl;
	cout << "3�����Ĺ���" << endl;
	cout << "4���ۺϲ�ѯ" << endl;
	cout << "5��ͳ�Ʒ���ģ��" << endl;
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
		cout << "���˳�" << endl;
		exit(0);
		break;
	case 1:
		cout << "----------���汾���Ϲ���---------" << endl;
		cout << "1���汾��Ϣ¼��" << endl;
		cout << "2���汾��Ϣ�޸�" << endl;
		cout << "3���汾ɾ��" << endl;
		cout << "4���汾��Ϣ��ʾ" << endl;
		cout << "5���汾��Ϣ����" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cout << "��������������¼��Ļ汾 ��ţ��汾�������ߣ������磬����ʱ�䣬�۸����ԣ��ʺ����䣬���״̬��" << endl;
			cin >> book.bNo >> book.bName >> book.author >> book.press >> book.outTime >> book.price >> book.language >>book.age >>book.isBorrow;
			//printBookList(Booklist);
			pMove = searchBookByName(Booklist, book.bName);
			if ( pMove != NULL) {
				cout << "�����Ѿ����ڣ�" << endl;
				return;
			}
			else {
				insertBookNodeByHead(Booklist, book);
				cout << "��ӳɹ���" << endl;
			}
			
			break;
		case 2:
			
			cout << "�����������޸ĵĻ汾��" << endl;
			cin >> book.bName;
			if (searchBookByName(Booklist, book.bName) == NULL) {
				cout << "δ�ҵ������޸ĵĻ汾��������������" << endl;
				return;
			}
			else {
				deleteBookNode(Booklist, book.bName);
				cout << "�����������޸ĺ�Ļ汾��ţ��汾�������ߣ������磬����ʱ�䣬�۸����ԣ��ʺ����䣬���״̬��" << endl;
				cin >> book.bNo >> book.bName >> book.author >> book.press >> book.outTime >> book.price >> book.language >> book.age >> book.isBorrow;
				insertBookNodeByHead(Booklist, book);
				cout << "�޸ĳɹ���" << endl;
			}

			break;
		case 3:
			cout << "����������ɾ���Ļ汾����" << endl;
			cin >> book.bName;
			deleteBookNode(Booklist, book.bName);
			cout << "ɾ���ɹ�" << endl;
			break;
		case 4:
			printBookList(Booklist);
			break;
		case 5:
			cout << "������������ҵĻ汾����" << endl;
			cin >> book.bName;
			pMove = searchBookByName(Booklist, book.bName);
			if (pMove == NULL) {
				cout << "δ�ҵ��汾��Ϣ!" << endl;
			}
			else {
				cout << "�汾���\t�汾��\t����\t������\t\t����ʱ��\t�۸�\t����\t\t�ʺ�����\t���״̬" << endl;
				cout << pMove->data.bNo << "\t\t" << pMove->data.bName << "\t" << pMove->data.author << "\t" << pMove->data.press << "\t\t"
					<< pMove->data.outTime << "\t" << pMove->data.price << "\t" << pMove->data.language << "\t\t" << pMove->data.age << "\t\t"
					<< pMove->data.isBorrow << endl;
			}

			break;
		default:
			cout << "����������������룡" << endl;
			
			break;
		}

		break;
	case 2:
		cout << "----------����Ա��Ϣ����---------" << endl;
		cout << "1����Ա��Ϣ¼��" << endl;
		cout << "2����Ա��Ϣ�޸�" << endl;
		cout << "3��ɾ����Ա��Ϣ" << endl;
		cout << "4����Ա��Ϣ���" << endl;
		cout << "5����Ա��Ϣ����" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cout << "������������Ҫ¼��Ļ�Ա��ţ���Ա�������䣬�Ա𣬵绰���룺" << endl;
			cin >> people.pNo >> people.pName >> people.pAge >> people.sex >> people.tel;
			if (searchPeopleByName(Peoplelist, people.pName) != NULL) {
				cout << "�û�Ա�ѱ�¼�룡" << endl;

			}
			else {
				insertPeopleNodeByHead(Peoplelist, people);
			}
			
			break;
		case 2:
			cout << "�����������޸���Ϣ�Ļ�Ա������" << endl;
			cin >> people.pName;
			if (searchPeopleByName(Peoplelist, people.pName) == NULL) {
				cout << "δ�ҵ���Ӧ��Ա��Ϣ��" << endl;
			}
			else {
				deletePeopleNode(Peoplelist, people.pName);
				cout << "�������µĵĻ�Ա��ţ���Ա�������䣬�Ա𣬵绰���룺" << endl;
				cin >> people.pNo >> people.pName >> people.pAge >> people.sex >> people.tel;
				insertPeopleNodeByHead(Peoplelist, people);
				cout << "�޸ĳɹ���" << endl;
			}

			break;
		case 3:
			cout << "����������ɾ���Ļ�Ա������" << endl;
			cin >> people.pName;
			if (searchPeopleByName(Peoplelist, people.pName)==NULL) {
				cout << "δ�ҵ���Ӧ��Ա��Ϣ��" << endl;
			}
			else {
				deletePeopleNode(Peoplelist, people.pName);
				cout << "ɾ���ɹ���" << endl;
			}
			break;
		case 4:
			printPeopleList(Peoplelist);
			break;
		case 5:
			cout << "�����������ѯ�Ļ�Ա������" << endl;
			cin >> people.pName;
			pMove1 = searchPeopleByName(Peoplelist, people.pName);
			if (pMove1 == NULL) {
				cout << "δ�ҵ���Ӧ��Ա��Ϣ��" << endl;
			}
			else {
				cout << "��Ա��\t��Ա��\t��Ա����\t��Ա�Ա�\t��ϵ�绰" << endl;
				cout << pMove1->data.pNo << "\t" << pMove1->data.pName << "\t" << pMove1->data.pAge << "\t\t" << pMove1->data.sex << "\t\t" << pMove1->data.tel << endl;
			}
			break;
		default:
			cout << "����������������룡" << endl;
			
			break;
		}
		break;
	case 3:
		cout << "----------�����Ĺ���---------" << endl;
		cout << "1��������Ϣ¼��" << endl;
		cout << "2��������Ϣ�޸�" << endl;
		cout << "3��������Ϣɾ��" << endl;
		cout << "4��������Ϣ���" << endl;
		cout << "5��������Ϣ��ѯ" << endl;
		cout << "6���黹�汾" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cout << "����������������ӵĻ汾��ţ���Ա�ţ����ʱ�䣺" << endl;
			if (borrow.returnTIme == NULL) {
				strcpy(borrow.returnTIme, "δ�黹");
			}
			cin >> borrow.bNo >> borrow.pNo >> borrow.loanTime;
			pMove = searchBookByNo(Booklist, borrow.bNo);
			pMove1 = searchPeopleByNo(Peoplelist, borrow.pNo);
			if (pMove->data.isBorrow == 1) {
				cout << "�û汾�ѱ����ģ���ȴ��黹���ٽ��н��Ĳ���" << endl;
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
				cout << "��ӳɹ���" << endl;
			}
			break;
		case 2:
			cout << "��������������ɾ���Ļ汾��ţ���Ա�ţ�" << endl;
			cin >> borrow.bNo >> borrow.pNo;
			if (searchBorrowByName(Borrowlist, borrow.bNo, borrow.pNo) == NULL) {
				cout << "δ�ҵ���Ӧ�Ľ�����Ϣ�����������룡" << endl;
				return;
			}
			else {
				deleteBorrowNode(Borrowlist, borrow.bNo, borrow.pNo);
				cout << "ɾ���ɹ���" << endl;
			}
			break;
		case 3:
			cout << "��������������ɾ���Ļ汾��ţ���Ա�ţ�" << endl;
			cin >> borrow.bNo >> borrow.pNo;
			deleteBorrowNode(Borrowlist, borrow.bNo, borrow.pNo);
			cout << "ɾ���ɹ���" << endl;
			break;
		case 4:
			printBorrowList(Borrowlist);
			break;
		case 5:
			cout << "��������������ɾ���Ļ汾��ţ���Ա�ţ�" << endl;
			cin >> borrow.bNo >> borrow.pNo;
			pMove2 = searchBorrowByName(Borrowlist, borrow.bNo, borrow.pNo);
			if ( pMove2== NULL) {
				cout << "δ�ҵ���Ӧ�Ľ�����Ϣ�����������룡";
				return;
			}
			else {
				cout << "�汾���\t��Ա��\t\t���ʱ��\t\t�黹ʱ��" << endl;
				cout << pMove2->data.bNo << "\t\t" << pMove2->data.pNo << "\t\t" << pMove2->data.loanTime << "\t\t" << pMove2->data.returnTIme << endl;
			}
			break;
		case 6:
			cout << "����������汾��ţ���Ա�ţ�" << endl;
			cin >> borrow.bNo >> borrow.pNo;
			pMove2 = searchBorrowByName(Borrowlist, borrow.bNo, borrow.pNo);
			if (pMove2 != NULL) {
				borrow = pMove2->data;
				cout << "������黹ʱ�䣺" << endl;
				cin >> borrow.returnTIme;
				fflush(stdin);
				deleteBorrowNode(Borrowlist, borrow.bNo, borrow.pNo);
				insertBorrowNodeByHead(Borrowlist, borrow);
				pMove = searchBookByNo(Booklist, borrow.bNo);
				pMove->data.isBorrow = 0;
				book = pMove->data;
				deleteBookNode(Booklist, book.bName);
				insertBookNodeByHead(Booklist, book);
				cout << "�黹�ɹ���" << endl;
			}
		default:
			cout << "����������������룡" << endl;
			
			break;
		}
		break;
	case 4:
		cout << "----------���ۺϲ�ѯ��---------" << endl;
		cout << "1���汾��Ϣ��ѯ" << endl;
		cout << "2����Ա��Ϣ��ѯ" << endl;
		cout << "3��������Ϣ��ѯ" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cout << "1��ͨ���汾��Ų�ѯ" << endl;
			cout << "2��ͨ���汾����ѯ" << endl;
			cout << "3��ͨ�����߲�ѯ" << endl;
			cin >> select2;
			switch (select2) {
			case 1:
				cout << "������汾��ţ�" << endl;
				cin >> book.bNo;
				pMove = searchBookByNo(Booklist, book.bNo);
				if (pMove == NULL) {
					cout << "δ�ҵ��汾��Ϣ!" << endl;
				}
				else {
					cout << "�汾���\t�汾��\t����\t������\t\t����ʱ��\t�۸�\t����\t\t�ʺ�����\t���״̬" << endl;
					cout << pMove->data.bNo << "\t\t" << pMove->data.bName << "\t" << pMove->data.author << "\t" << pMove->data.press << "\t\t"
						<< pMove->data.outTime << "\t" << pMove->data.price << "\t" << pMove->data.language << "\t\t" << pMove->data.age << "\t\t"
						<< pMove->data.isBorrow << endl;
				}

				break;
			case 2:
				cout << "������汾����" << endl;
				cin >> book.bName;
				pMove = searchBookByName(Booklist, book.bName);
				if (pMove == NULL) {
					cout << "δ�ҵ��汾��Ϣ!" << endl;
				}
				else {
					cout << "�汾���\t�汾��\t����\t������\t\t����ʱ��\t�۸�\t����\t\t�ʺ�����\t���״̬" << endl;
					cout << pMove->data.bNo << "\t\t" << pMove->data.bName << "\t" << pMove->data.author << "\t" << pMove->data.press << "\t\t"
						<< pMove->data.outTime << "\t" << pMove->data.price << "\t" << pMove->data.language << "\t\t" << pMove->data.age << "\t\t"
						<< pMove->data.isBorrow << endl;
				}
				break;
			case 3:
				cout << "��������������" << endl;
				cin >> book.author;
				pMove = searchBookByAuthor(Booklist, book.author);
				if (pMove == NULL) {
					cout << "δ�ҵ��汾��Ϣ!" << endl;
				}
				else {
					cout << "�汾���\t�汾��\t����\t������\t\t����ʱ��\t�۸�\t����\t\t�ʺ�����\t���״̬" << endl;
					cout << pMove->data.bNo << "\t\t" << pMove->data.bName << "\t" << pMove->data.author << "\t" << pMove->data.press << "\t\t"
						<< pMove->data.outTime << "\t" << pMove->data.price << "\t" << pMove->data.language << "\t\t" << pMove->data.age << "\t\t"
						<< pMove->data.isBorrow << endl;
				}
				break;
			default:
				cout << "����������������룡" << endl;
				
				break;
			}
			break;
		case 2:
			cout << "1��ͨ����Ա�Ų�ѯ" << endl;
			cout << "2��ͨ����Ա����ѯ" << endl;
			cout << "3��ͨ����ϵ�绰��ѯ" << endl;
			cin >> select2;
			switch (select2) {
			case 1:
				cout << "�������Ա�ţ�" << endl;
				cin >> people.pNo;
				pMove1 = searchPeopleByNo(Peoplelist, people.pNo);
				if (pMove1 == NULL) {
					cout << "δ�ҵ���Ӧ��Ա��Ϣ��" << endl;
				}
				else {
					cout << "��Ա��\t��Ա��\t��Ա����\t��Ա�Ա�\t��ϵ�绰" << endl;
					cout << pMove1->data.pNo << "\t" << pMove1->data.pName << "\t" << pMove1->data.pAge << "\t\t" << pMove1->data.sex << "\t\t" << pMove1->data.tel << endl;
				}

				break;
			case 2:
				cout << "�������Ա����" << endl;
				cin >> people.pName;
				pMove1 = searchPeopleByName(Peoplelist, people.pName);
				if (pMove1 == NULL) {
					cout << "δ�ҵ���Ӧ��Ա��Ϣ��" << endl;
				}
				else {
					cout << "��Ա��\t��Ա��\t��Ա����\t��Ա�Ա�\t��ϵ�绰" << endl;
					cout << pMove1->data.pNo << "\t" << pMove1->data.pName << "\t" << pMove1->data.pAge << "\t\t" << pMove1->data.sex << "\t\t" << pMove1->data.tel << endl;
				}
				break;
			case 3:
				cout << "��������ϵ�绰��" << endl;
				cin >> people.tel;
				pMove1 = searchPeopleByTel(Peoplelist, people.tel);
				if (pMove1 == NULL) {
					cout << "δ�ҵ���Ӧ��Ա��Ϣ��" << endl;
				}
				else {
					cout << "��Ա��\t��Ա��\t��Ա����\t��Ա�Ա�\t��ϵ�绰" << endl;
					cout << pMove1->data.pNo << "\t" << pMove1->data.pName << "\t" << pMove1->data.pAge << "\t\t" << pMove1->data.sex << "\t\t" << pMove1->data.tel << endl;
				}
				break;
			default:
				cout << "����������������룡" << endl;
				
				break;
			}
			break;
		case 3 :
			cout << "1��ͨ���汾��Ų�ѯ" << endl;
			cout << "2��ͨ����Ա�Ų�ѯ" << endl;
			cin >> select2;
			switch (select2) {
			case 1:
				cout << "������汾��ţ�" << endl;
				cin >> borrow.bNo;
				pMove2 = searchBorrowBybNo(Borrowlist, borrow.bNo);
				if (pMove2 == NULL) {
					cout << "δ�ҵ���Ӧ�Ľ�����Ϣ�����������룡";
					return;
				}
				else {
					cout << "�汾���\t��Ա��\t\t���ʱ��\t\t�黹ʱ��" << endl;
					cout << pMove2->data.bNo << "\t\t" << pMove2->data.pNo << "\t\t" << pMove2->data.loanTime << "\t\t" << pMove2->data.returnTIme << endl;
				}

				break;
			case 2:
				cout << "�������Ա��ţ�" << endl;
				cin >> borrow.pNo;
				pMove2 = searchBorrowBypNo(Borrowlist,borrow.pNo);
				if (pMove2 == NULL) {
					cout << "δ�ҵ���Ӧ�Ľ�����Ϣ�����������룡";
					return;
				}
				else {
					cout << "�汾���\t��Ա��\t\t���ʱ��\t\t�黹ʱ��"<<endl;
					cout << pMove2->data.bNo << "\t\t" << pMove2->data.pNo << "\t\t" << pMove2->data.loanTime << "\t\t" << pMove2->data.returnTIme << endl;
				}
				break;
			default:
				cout << "����������������룡" << endl;
				
				break;
			}
			break;
		default:
			cout << "����������������룡" << endl;
			
			break;
		}
		break;
	case 5:
		cout << "----------��ͳ�Ʒ���ģ�顿---------" << endl;
		cout << "1����Ա��������" << endl;
		cout << "2���汾��������" << endl;
		cout << "3�����ջ汾�ʺ���������" << endl;
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
			cout << "����������������룡" << endl;
			break;
		}
	default:
		//cout << "111112" << select << "211111" << endl;
		if (select >= 0 && select <= 5) {
			break;
		}
			cout << "����������������룡" << endl;
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