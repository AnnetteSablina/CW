#include"Header.h"
void menu()
{  std::vector<logpass>admins;
	data_admin_file(admins);
	std::vector <logpass> users;
	data_user_file(users);
	system("cls");
	int a;
	bool run = true;
	while (run) {
		a = getInt("�������: \n 1.���� �� ����� ��������������. \n 2.���� �� ����� ������������.");
		run = false;
		switch (a) {
		case 1:
			system("cls");
			Admin_haveAccount(admins);
			break;
		case 2:
			system("cls");
			User_haveAccount(users);
			break;
		default:
			std::cout << "���������� ������ ��� ���. �������� ����." << std::endl;
			Sleep(2000);
			system("cls");
			run = true;
			break;
		}

	}
}	
void Admin_haveAccount(std::vector<logpass>&admins) {
	int a;
	bool run = true;
	Admin admin;
	while (true) {
		while (run) {
			a = getInt("�� ����� �������������? \n �������: \n 1.��.\n 2.���.");
			run = false;
			switch (a) {
			case 1:
				system("cls");
				admin.enterAccount(admins);
				break;
			case 2:
				system("cls");
				std::cout << "������� ��� ������������ ���� ����������������� � ��������������"<< std::endl;
				Sleep(2000);
				menu();
			default:
				system("cls");
				std::cout << "���������� ������ ��� ���. �������� ����." << std::endl;
				Sleep(2000);
				system("cls");
				run = true;
				break;

			}
		}
	}



}
void data_admin_file(std::vector<logpass>& admins) {
	{
		std::ifstream file("admins.txt");
		while (file)
		{
			logpass temp;
			getline(file, temp.login);
			getline(file, temp.password);
			admins.push_back(temp);
		}
		if (!admins.empty()) admins.erase(admins.end() - 1);
		file.close();

	}
}
void Admin::enterAccount(std::vector<logpass>&admins) {
	system("cls");
	bool access = true;
	bool exit = false;
	do {
		if (access) {
			this->human.login=login(1, access, exit);
		}
		else {
			this->human.login=login(2, access, exit);
		};
		if (exit) {
			break;
		};
		this->human.password=password(exit);
		if (exit) {
			break;
		};
		access = true;
		logpass check(human.login,human.password);
		if (std::find(admins.begin(), admins.end(), check) == admins.end())
			access = false;

	} while (!access);
	if (exit) {
		menu();
	};
	if (access) {
		adminMenu(admins);
	}

};
void Admin::adminMenu(std::vector <logpass>& admins) {
	system("cls");
	int a,b,c,d,e;
	bool check;
	bool run = true;
	bool run1 = true;
	bool run2 = true;
	bool run3 = true;
	while (run) {
		a = getInt(" ���� ��������������  \n  �������: \n 1.��������� ����� �������. \n 2.�������������� ���������� � ������������. \n 3.�������� ������������.  \n 4.�������� ���� ������ � ��������� �����. \n 5.����� � ���������� ������. \n 6.���������� ������ � ������ ������ ������������. \n 7.����� � ������� ����.");
		run = false;
		switch (a) {
		case 1:
			system("cls");
			std::string choise = yes_no("������ ����� ����� � ������? ������� yes ��� no.");
			if (choise == "yes") {
				check=check_login_once();
				if (!check) {
					addlogpass();
				}
			}
			else {
				addlogpass();
			}

			//add_user_information(admins);

			break;
			

		}
	}
}
void Admin::add_user_information(std::vector <logpass>& admins) {
	bool neban = true;
    std::vector<information>userss;
	data_client_file(userss);
	std::vector<information> passport;
	data_passport_file(passport);
	getchar();
	do {
		this->user.client_code = client_code("������� ��� �������.������� exit, ���� ������ ��������� � ������� ����.");
		neban = true;
		information check(user.client_code);
		if (std::find(passport.begin(), passport.end(), check) != passport.end()) {
			std::cout << "����� ������������������ ����� ��� ����������." << std::endl;
			neban = false;
		};
		if (this->user.client_code == "exit") {
			adminMenu(admins);
			break;
		}
	} while (!neban);
	
	this->user.telephone_number = telephone_number("������� ����� �������� �������.������� exit, ���� ������ ��������� � ������� ����.");
	if (this->user.telephone_number == "exit") {
		adminMenu(admins);
	}
	this->user.country = ccs("������� ������ ����������.������� exit, ���� ������ ��������� � ������� ����");
	if (this->user.country == "exit") {
		adminMenu(admins);
	}
	this->user.city = ccs("������� ����� ����������.������� exit, ���� ������ ��������� � ������� ����");
	if (this->user.city == "exit")
	this->user.street = ccs("������� ����� ����������.������� exit, ���� ������ ��������� � ������� ����");
	if (this->user.street == "exit") {
		adminMenu(admins);
	}
	this->user.housenumber = hf("������� ����� ����.������� exit, ���� ������ ��������� � ������� ����");
	if (this->user.housenumber == "exit") {
		adminMenu(admins);
	}
	this->user.flatnumber = hf("������� ����� ��������. ������� 0, ���� ������ ��������� � ������� ����.������� exit, ���� ������ ��������� � ������� ����");
	if (this->user.flatnumber == "exit") {
		adminMenu(admins);
	}
	
}
void Admin::addlogpass() {
	std::cout << "�������� ������������" << std::endl;
}