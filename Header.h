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
void User_haveAccount(std::vector<logpass>&);//вопрос о имении аккаунта
void Admin_haveAccount(std::vector<logpass>&);//вопрос о персонализации личности
int getInt(std::string);// получение целого
void menu();//меню 1-го уровня
void data_user_file(std::vector<logpass>& );//получение данных логина/пароля пользователя
void data_admin_file(std::vector<logpass>&);//получение данных логина/пароля админа
void admin_enter_account(std::vector<logpass>&);//вход под админом
std::string getString(std::string);//получение строки с сообщением
void data_client_file(std::vector<information>&);//получение инфы о клиенте из файла
void rewrite_user_file(std::vector<logpass>&);
void data_passport_file(std::vector<information>&);//получение идентификационного номера из файла
std::string yes_no(std::string);//получение ответа да/нет
std::string login(int, bool&, bool&);
std::string password(bool&);











class logpass {
public:
	logpass(std::string, std::string);
	std::string password;//пароль
	std::string login;//логин
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
	Client();
	Client(std::string);
	virtual void enterAccount(std::vector<logpass>&);
	std::string client_code(std::string);//проверка на ввод кода клиента
	std::string telephone_number(std::string);//проверка на телефонный номер
	std::string ccs(std::string);// проверка на ввод страны, города и улицы
	std::string hf(std::string);// проверка на номер дома и квартиры
	void userMenu(std::vector<logpass>&);// меню пользователя
    void changePassword(std::vector<logpass>&);//сменить пароль
	int checkPasswords();//проверка на пароли
	bool check_login_once();//проверка на единственность логина


};
class Admin :public Client
{public:
    void enterAccount(std::vector<logpass>& ) override ;//вход в аккаунт
	void CreateAccount(std::vector<logpass>&);//создание аккаунта
	void deleteAccount(std::vector<logpass>&);//удаление аккаунта
	void addlogpass();//добавить пользователя(логин и пароль)
	void adminMenu(std::vector <logpass>&);//меню админа
	void add_user_information(std::vector <logpass>&);//добавить информацию о пользователе
	

};
