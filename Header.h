#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include<Windows.h>
#include <locale.h>
#include <vector>
#include <conio.h>
class logpass;
class information;
class client;
class data;
class dogovor;
int user_login(std::vector <logpass>&);
void User_haveAccount();//������ � ������ ��������
void Admin_haveAccount();//������ � �������������� ��������
int getInt(std::string);// ��������� ������
void menu();//���� 1-�� ������
void data_user_file(std::vector<logpass>& );//��������� ������ ������/������ ������������
void data_admin_file(std::vector<logpass>&);//��������� ������ ������/������ ������
void admin_enter_account(std::vector<logpass>&);//���� ��� �������
std::string getString(std::string);//��������� ������ � ����������
void data_client_file(std::vector<information>&);//��������� ���� � ������� �� �����
void rewrite_user_file(std::vector<logpass>&);
void data_passport_file(std::vector<information>&);//��������� ������������������ ������ �� �����





class logpass {
public:
	logpass(std::string, std::string);
	std::string password;//������
	std::string login;//�����
	bool operator==(logpass human);
	logpass();

};
class information {
public:
	information(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
	std::string client_code;
	std::string telephone_number;
	std::string country;
	std::string city;
	std::string street;
	std::string housenumber;
	std::string flatnumber;
	information();
	information(std::string);
	bool operator==(information user);
};

class dogovor {
public:
	std::string name;
	std::string document_code;
	std::string service_code;
	std::string summ;
	std::string commition;
};
class data {
public:
	data(std::string);
	data();
	std::string day;
	std::string month;
	std::string year;
};
class Client {
public:
	logpass human;
	information user;
	data data;
	dogovor dogovor;
	virtual void enterAccount(std::vector<logpass>&);
	void login(int, bool&, bool&);
	void password(bool&);
	std::string client_code(std::string);//�������� �� ���� ���� �������
	std::string telephone_number(std::string);//�������� �� ���������� �����
	std::string ccs(std::string);// �������� �� ���� ������, ������ � �����
	std::string hf(std::string);// �������� �� ����� ���� � ��������
	void userMenu(std::vector<logpass>&);// ���� ������������
    void changePassword(std::vector<logpass>&);//������� ������
	int checkPasswords();//�������� �� ������


};
class Admin :public Client
{public:
    void enterAccount(std::vector<logpass>& ) ;//���� � �������
	void CreateAccount(std::vector<logpass>&);//�������� ��������
	void deleteAccount(std::vector<logpass>&);//�������� ��������
	void addlogpass(std::vector<logpass>&);//�������� ������������(����� � ������)
	void adminMenu(std::vector <logpass>&);//���� ������
	void add_user_information(std::vector <logpass>&);//�������� ���������� � ������������
	

};
