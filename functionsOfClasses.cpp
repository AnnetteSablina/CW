#include"Header.h"
logpass::logpass(std::string login, std::string password) {
	this->login = login;
	this->password = password;
}
bool logpass::operator==(logpass human) {
	if (this->login == human.login && this->password == human.password)
		return true;
	else
		return false;
};
logpass::logpass() {
}
std::string getString(std::string p)
{
	system("cls");
	std::string mystring;
	std::cout << p << std::endl;
	std::getline(std::cin, mystring);
	return mystring;
}
int getInt(std::string massage) {
	int c;
	std::cout << massage << std::endl;;
	while (true) {
		std::cin >> c;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			system("cls");
			std::cout << "Используй целое число:" << std::endl;
			continue;

		}

		break;
	};
	return c;
}
information::information(std::string client_code, std::string telephone_number, std::string country, std::string city, std::string street, std::string housenumber, std::string flatnumber) {
	this->client_code = client_code;
	this->telephone_number = telephone_number;
	this->country = country;
	this->city = city;
	this->street = street;
	this->housenumber = housenumber;
	this->flatnumber = flatnumber;
}
information::information(){
}
information::information(std::string client_code) {
	this->client_code = client_code;
}
bool information::operator==(information user) {
	if (this->client_code == user.client_code)
		return true;
	else
		return false;
};
data::data(std::string data) {
	if (data.size() == 8) {
		day += data[0];
		day += data[1];
		month += data[2];
		month += data[3];
		year += data[4];
		year += data[5];
		year += data[6];
		year += data[7];
	}
}
data::data() {

}
std::string Client::client_code(std::string massage) {
	std::string client_code;
	for (int k = 0;;) {
		std::cout << massage << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, client_code);
		system("cls");
		if (client_code == "exit")
		break;
		for (unsigned int i = 0; i < client_code.size(); i++) {
			if (client_code.size() != 8) {
				s++;
				std::cout << "Код клиента должен содержать 8 символов." << std::endl;
				break;
			}
			if (client_code[i] == ' ') {
				s++;
				std::cout << " Введите без пробелов" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < client_code.size(); i++) {

				if (client_code[i] >= 'a' && client_code[i] <= 'z' || client_code[i] >= '0' && client_code[i] <= '9' || client_code[0] >= 'A' && client_code[0] <= 'Z')
					u++;
				else {
					std::cout << "Используйте буквы латинского алфавита и цифры и  для ввода" << std::endl;
					u = 0;
					break;


				}
				if (u == 0)
					break;
				if (u == client_code.size()) {
					break;

				}
			}
		}
		
			
		if (u == client_code.size()) {
			break;

		}
	}
	return client_code;
}
std::string Client::ccs(std::string massage)
{std::string ccs;
	for (int k = 0;;) {
		std::cout << massage << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, ccs);
		system("cls");
		if (ccs == "exit")
			break;
		for (unsigned int i = 0; i < ccs.size(); i++) {

			if (ccs[i] == ' ') {
				s++;
				std::cout << " Введите без пробелов" << std::endl;
				break;
			}

		}
		if (s == 0) {
			for ( unsigned int i = 0; i < ccs.size(); i++) {
				if (ccs.size() < 3) {
					std::cout << " Введите еще раз. Недостаточно символов. Минимум 3 символа." << std::endl;
					break;
				}
				if (ccs[0] >= 'A' && ccs[0] <= 'Z')
					i = 1;
				else
				{
					std::cout << "Используйте буквы латинского алфавита. Первый символ должен быть заглавной буквой.Введите еще раз\n" << std::endl;
					break;
				}

				for (i; i < ccs.size(); i++) {
					if (ccs[i] >= 'a' && ccs[i] <= 'z')
						u++;

					else {
						std::cout << " Используйте буквы латинского алфавита .\n Остальные символы - строчные буквы.Введите еще раз." << std::endl;
						u = 0;
						break;
					}

				}

				if (u == 0)
					break;
				if (u == ccs.size() - 1) {
					break;
				}

			}
		}

		if (u == ccs.size() - 1)
			break;
	}
	return ccs;
}
std::string Client::telephone_number(std::string massage) {
	std::string telephone_number;
	for (int k = 0;;) {
		std::cout << massage << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, telephone_number);
		system("cls");
		if (telephone_number == "exit")
			break;
		for (unsigned int i = 0; i < telephone_number.size(); i++) {
			if (telephone_number.size() != 9) {
				s++;
				std::cout << "Номер телефона должен содержать 9 символов." << std::endl;
				break;
			}
			if (telephone_number[i] == ' ') {
				s++;
				std::cout << " Введите без пробелов" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < telephone_number.size(); i++) {

				if (telephone_number[i] >= '0' && telephone_number[i] <= '9')
					u++;
				else {
					std::cout << "Используйте цифры для ввода" << std::endl;
					u = 0;
					break;


				}
				if (u == 0)
					break;
				if (u == telephone_number.size()) {
					break;

				}
			}
		}
		if (u == telephone_number.size()) {
			break;

		}
	}
	return telephone_number;
}
std::string Client::hf(std::string massage) {
	std::string hf;
	for (int k = 0;;) {
		std::cout << massage << std::endl;
		int u = 0;
		int s = 0;
		std::getline(std::cin, hf);
		system("cls");
		if (hf == "exit")
			break;
		for (unsigned int i = 0; i < hf.size(); i++) {
			if (hf.size() > 3) {
				s++;
				std::cout << "Максимум 3 символа." << std::endl;
				break;
			}
			if (hf[i] == ' ') {
				s++;
				std::cout << " Введите без пробелов" << std::endl;
				break;
			}
		}
		if (s == 0) {
			for (unsigned int i = 0; i < hf.size(); i++) {

				if (hf[i] >= '0' && hf[i] <= '9')
					u++;
				else {
					std::cout << "Используйте цифры для ввода" << std::endl;
					u = 0;
					break;


				}
				if (u == 0)
					break;
				if (u == hf.size()) {
					break;

				}
			}
		}
		if (u == hf.size()) {
			break;

		}
	}
	return hf;
}
