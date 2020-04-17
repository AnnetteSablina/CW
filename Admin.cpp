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
		a = getInt("Нажмите: \n 1.Вход от имени администратора. \n 2.Вход от имени пользователя.");
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
			std::cout << "Попробуйте ввести еще раз. Неверный ввод." << std::endl;
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
			a = getInt("Вы точно админестратор? \n Нажмите: \n 1.Да.\n 2.Нет.");
			run = false;
			switch (a) {
			case 1:
				system("cls");
				admin.enterAccount(admins);
				break;
			case 2:
				system("cls");
				std::cout << "Войдите как пользователь либо зарегистрируйтесь у админестратора"<< std::endl;
				Sleep(2000);
				menu();
			default:
				system("cls");
				std::cout << "Попробуйте ввести еще раз. Неверный ввод." << std::endl;
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
		a = getInt(" МЕНЮ АДМИНЕСТРАТОРА  \n  Нажмите: \n 1.Заключить новый договор. \n 2.Редактирование информации о пользователе. \n 3.Удаление пользователя.  \n 4.Просмотр всех данных в табличной форме. \n 5.Поиск и сортировка данных. \n 6.Добавление логина и пароля нового пользователя. \n 7.Выход в главное меню.");
		run = false;
		switch (a) {
		case 1:
			system("cls");
			std::string choise = yes_no("Клиент имеет логин и пароль? Введите yes или no.");
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
		this->user.client_code = client_code("Введите код клиента.Введите exit, если хотите вернуться в главное меню.");
		neban = true;
		information check(user.client_code);
		if (std::find(passport.begin(), passport.end(), check) != passport.end()) {
			std::cout << "Такой индентификационный номер уже существует." << std::endl;
			neban = false;
		};
		if (this->user.client_code == "exit") {
			adminMenu(admins);
			break;
		}
	} while (!neban);
	
	this->user.telephone_number = telephone_number("Введите номер телефона клиента.Введите exit, если хотите вернуться в главное меню.");
	if (this->user.telephone_number == "exit") {
		adminMenu(admins);
	}
	this->user.country = ccs("Введите страну проживания.Введите exit, если хотите вернуться в главное меню");
	if (this->user.country == "exit") {
		adminMenu(admins);
	}
	this->user.city = ccs("Введите город проживания.Введите exit, если хотите вернуться в главное меню");
	if (this->user.city == "exit")
	this->user.street = ccs("Введите улицу проживания.Введите exit, если хотите вернуться в главное меню");
	if (this->user.street == "exit") {
		adminMenu(admins);
	}
	this->user.housenumber = hf("Введите номер дома.Введите exit, если хотите вернуться в главное меню");
	if (this->user.housenumber == "exit") {
		adminMenu(admins);
	}
	this->user.flatnumber = hf("Введите номер квартиры. Введите 0, если клиент проживает в частном доме.Введите exit, если хотите вернуться в главное меню");
	if (this->user.flatnumber == "exit") {
		adminMenu(admins);
	}
	
}
void Admin::addlogpass() {
	std::cout << "Добавить пользователя" << std::endl;
}