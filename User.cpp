#include"Header.h"
int user_login(std::vector <logpass>& users) {
	return 0;
}
void User_haveAccount() {
	int a;
	bool run = true;
	Client user;
	std::vector <logpass> users;
	data_user_file(users);
	while (true) {
		while (run) {
			a = getInt("У вас есть аккаунт? \n Нажмите: \n 1.Да.\n 2.Нет.");
			run = false;
			switch (a) {
			case 1:
				system("cls");
				user.enterAccount(users);
				break;
			case 2:
				system("cls");
				std::cout << "Обратитесь к админестратору,чтобы зарегистрироваться." << std::endl;
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

void data_user_file(std::vector<logpass>& users) 
	{
		std::ifstream file("users.txt");
		while (file)
		{
			logpass temp;
			getline(file, temp.login);
			getline(file, temp.password);
			users.push_back(temp);
		}
		if (!users.empty()) users.erase(users.end() - 1);
		file.close();

	}
void data_passport_file(std::vector<information>&passport) {
	std::ifstream file("passport.txt");
	while (file)
	{
		information temp;
		std::getline(file, temp.client_code);
		passport.push_back(temp);
	}
	if (!passport.empty()) passport.erase(passport.end() - 1);
	file.close();
}

void Client::enterAccount(std::vector<logpass>& users) {
	system("cls");
	bool access = true;
	bool exit = false;
	do {
		if (access) {
			login(1, access, exit);
		}
		else {
			login(2, access, exit);
		};
		if (exit) {
			break;
		};
		password(exit);
		if (exit) {
			break;
		};
		access = true;
		logpass check(human.login, human.password);
		if (std::find(users.begin(), users.end(), check) == users.end())
			access = false;

	} while (!access);
	if (exit) {
		menu();
	};
	if (access) {
		Sleep(3000);
		userMenu(users);
	}


};
void Client::login(int type, bool& access, bool& exit) {
	bool run = true;
	int u=0;
	switch (type) {
	case 1:
		system("cls");
		if (access) {
			this->human.login = getString("Введите логин. Для выхода введите menu.");
		}
		else {
			this->human.login = getString("Введите логин еще раз. Для выхода введите menu.");
		};
		break;
	case 2:
		system("cls");
		this->human.login = getString("Вы ввели неверные логин или пароль. Введите логин еще раз. Для выхода введите menu.");
		break;
	case 3:
		system("cls");
		this->human.login = getString("Такой логин уже существует. Для выхода введите menu.");
		break;
	};
	
	do
	{
		u = 0;
		if (this->human.login == "menu")
		{
			exit = true;
			break;
		}

		if (this->human.login.size() < 5)
		{
			
			this->human.login = getString("Введите логин из 5 или более символов. Для выхода введите menu.");
			continue;
		}

		for (unsigned int i = 0; i < this->human.login.size(); ++i)
			if (!((this->human.login[i] >= 'a' && this->human.login[i] <= 'z')
				|| (this->human.login[i] >= 'A' && this->human.login[i] <= 'Z')
				|| (this->human.login[i] >= '0' && this->human.login[i] <= '0')))
			{
				this->human.login = getString("Логин содержит недопустимые символы. Для выхода введите menu.");
				break;
			}
			else {
				u++;
			}
		if (u == human.login.size()) {
			break;
		}

	} while (true);
};

void Client::password(bool& exit) {
	int u = 0;
	this->human.password = getString("Введите пароль. Для выхода введите menu.");
	do {
		u = 0;
		if (this->human.password == "menu")
		{
			exit = true;
			break;
		}
		if (this->human.password.size() <= 8 && this->human.password.size() >= 12)
		{
			this->human.password = getString("Пароль должен содержать  от 8 до 12 символов. Для выхода введите menu.");
		}

		for (auto a : this->human.password) {
			if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')))
			{
				this->human.password = getString("Пароль содержит недопустимые символы. Для выхода введите menu.");
				break;
			}
			else {
				u++;
			}
		}
		if (u == this->human.password.size()) {
			break;
		}

	} while (true);
};

void Client::userMenu(std::vector<logpass>& users) {
	system("cls");
	std::cout << "user menu" << std::endl;
}
void data_client_file(std::vector<information>& userss) {
	std::ifstream file("data.txt");
	while (file) {
		information temp;
		getline(file, temp.client_code);
		getline(file, temp.telephone_number);
		getline(file, temp.country);
		getline(file, temp.city);
		getline(file, temp.street);
		getline(file, temp.housenumber);
		getline(file, temp.flatnumber);
		if(!userss.empty()) userss.erase(userss.end() - 1);
		file.close();
	}
}
void rewrite_user_file(std::vector<logpass>&users)
{
	std::ofstream file("users.txt", std::ios::trunc);

	for (auto i : users)
		file << i.login << std::endl << i.password << std::endl;

	file.close();
}




