
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<list>
#include<ctime>
#include<conio.h>

using namespace std;

#define delimiter "\n-----------------------------------------------------------------------------------\n"
#define tab "\t"
#define TAKE_TIME int year, int month, int day, int hour, int minute
#define GIVE_TIME year, month, day, hour, minute

const std::map<int, std::string> crimenal =
{
	{0, "Другие правонарушения"},
	{1, "Превышение скорости"},
	{2, "Нетрезвая езда"},
	{3, "Прозд на красный"},
	{4, "Пересечение двойной сплошной"},
	{5, "Выезд на встречную полосу"},
	{6, "Проезд в запрещенном месте"},
	{7, "Парковка в неположенном месте"},
	{8, "Танировка"},	
	{9, "Отсутствие документов"},
	{10, "Дрифт на перекрестке"},
	{11, "Оскорбление офицера"},

};
class Crime
{
	int id;						//правонарушения статья
	tm time;					//время нарушения
	std::string place;			//место нарушения
public:

	int get_id()const
	{
		return  id;
	}
	const char* get_time()const
	{
		char* time = asctime(&this->time);
		time[strlen(time) - 1] = 0; //убераем перенос на новую строку
		return time;
	}
	int get_timestamp()const
	{
		tm time = this->time;
		return mktime(&time);
	}
	const std::string& get_place()const
	{
		return place;
	}

	void set_id(int id)
	{
		//if (crimenal.find(id) != crimenal.end())
		//	this->id = id;
		//else this->id = 0;
		this->id = crimenal.find(id) == crimenal.end() ? 0 : id;
	}
	void set_time(TAKE_TIME)
	{
		this->time = tm{};
		time.tm_year = year - 1900;
		time.tm_mon = month - 1;
		time.tm_mday = day;
		time.tm_hour = hour;
		time.tm_min = minute;
		this->time = time;
	}
	void set_timestamp(time_t time)
	{
		this->time = *localtime(&time);
	}
	tm* init_time()
	{
		const time_t time = mktime(&this->time);
		return localtime(&time);
	}
	void set_time(const std::string& time)
	{
		this->time = tm{};
		const int SIZE = 32;
		char buffer[SIZE]{};
		strcpy(buffer, time.c_str()); //метод const char* c_str()const возвращает RAW-строку, которую обварачивает обьект класса 'std'
		int part[5] = {};
		const char delimiters[] = ". /:";
		int n = 0;
		for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
			part[n++] = std::stoi(pch);
		this->time.tm_year = part[0] - 1900;
		this->time.tm_mon = part[1] - 1;
		this->time.tm_mday = part[2];
		this->time.tm_hour = part[3];
		this->time.tm_min = part[4];
		this->time = *init_time();
	}
	void set_place(const std::string& place)
	{
		this->place = place;
	}
	//				Constructor
	Crime(int id, const std::string& time, const std::string& place)
	{

		set_id(id);
		set_time(time);
		set_place(place);
	}
	~Crime() {};
};

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	os << obj.get_time() << " | ";
	os.width(25);
	os << std::left;
	os << obj.get_place() << " | ";
	os << crimenal.at(obj.get_id());

	return os;
}
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{
	ofs << obj.get_timestamp() << " ";
	ofs << obj.get_id() << " ";
	ofs << obj.get_place();
	return ofs;
}
std::istream& operator>>(std::istream& is, Crime& obj)
{
	int id;
	std::string date;
	std::string time;
	std::string place;
	cout << "Введите нарушение: "; is >> id;
	is.ignore();

	cout << R"(
		\
		0 - Ввести время вручную;\n
        1 - использовать текущее время;
	
			)";
	bool current_time;
	cin >> current_time;
	if (current_time)
	{
		obj.set_timestamp(std::time(NULL));
		is.ignore();
	}
	else
	{
		std::getline(is, date, ' ');
		std::getline(is, time, ' ');
		obj.set_time(date + " " + time);
	}
	
	cout << "Введите место проишествия: ";
	
	SetConsoleCP(1251);
	std::getline(is, place);
	SetConsoleCP(866);

	obj.set_id(id);
	//obj.set_time(date + " " + time);
	obj.set_place(place);
	return is;

}
std::ifstream& operator>>(std::ifstream& ifs, Crime& obj)
{
	int id;
	time_t timestamp;
	std::string place;
	ifs >> id >> timestamp;
	std::getline(ifs, place, ',');
	obj.set_id(id);
	obj.set_timestamp(timestamp);
	return ifs;
}
void print(const std::map < std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);
void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename);
void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, NULL);

	setlocale(LC_ALL, "");
	//Crimenal crime( 1, "2023.06.21 21:30", "Ул. Ленина");
	//cout << crime;

	std::map<std::string, std::list<Crime>> base/* =
	{
		{
			"aa777bb", std::list<Crime>
			{
				Crime(1, "2023.06.21 12:05", "ул. Ленина"),
				Crime(2, "2023.06.21 12:05", "ул. Ленина"),
				Crime(11, "2023.06.21 12:05", "ул. Ленина")
			}
		},

		{
			"aa123bb", std::list<Crime>
			{
				Crime(5, "2023.06.21 18:05", "ул. Октябрьская"),
				Crime(6, "2023.06.21 18:10", "ул. Октябрьская"),
			}
		},

		{
			"mm111ab", std::list<Crime>
			{
				Crime(2, "2023.06.21 18:30", "ул. Парижской коммуны")
			}
		},

		{
			"ab344ab", std::list<Crime>
			{
				Crime(7, "2023.06.22 11:22", "ул. Ворошилова"),
				Crime(8, "2023.06.22 11:22", "ул. Ворошилова")
			}
		},
	}*/;
	char key;
	do
	{
		cout << "1. Paccпечатка базы данных: " << endl;
		cout << "2. Paccпечатка данных по заданому номеру: " << endl;
		cout << "3. Paccпечатка данных по диапозону номеров: " << endl;
		cout << "4. Сохранение базы в файл: " << endl;
		cout << "5. Загрузка базы из файла: " << endl;
		cout << "6. Добавление записи в базу:" << endl;
		cout << "0. Выход из программы: " << endl;

		key = _getch();
		switch (key)
		{
		case '1': print(base); break;
		case '4': save(base, "base.txt"); break;
		case '5': load(base, "base.txt"); break;
		case '6': 
			for (std::pair<int, std::string> i : crimenal) cout << "\t" << i.first << "\t" << i.second << endl;
			std::string licence_plate;
			Crime crime(0, "2000.01.01 00:00", "");
			cout << "Введите номер автомобиля: " ; cin >> licence_plate;
			cout << "Введите правонарушения: " ; cin >> crime;
			base[licence_plate].push_back(crime);
			break;
		}
	} while (key != 27 && key != '0');

	save(base, "base.txt");



}
void print(const std::map < std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>> ::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first + ":\n";
		for (std::list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); ++l_it)
		{
			cout << "\t" << *l_it << endl;
		}
		cout << delimiter << endl;
	}
}
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::map<std::string, std::list<Crime>> ::const_iterator it = base.begin(); it != base.end(); ++it)
	{
	fout << it->first + ":\t";
		for (std::list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); ++l_it)
		{
			fout  << *l_it << ", ";
		}
		fout << endl;
	}
	fout.close();
	std::string command = "start notepad " + filename;
	system(command.c_str());
}
void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	base.clear();
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		//TODO: read file
		while (!fin.eof())
		{
			std::string licence_plate;
			std::string all_crimes;
			std::getline(fin, licence_plate, ':');
			fin.ignore(); //пропускаем двоеточие

			std::getline(fin, all_crimes);
			int all_crimes_size = all_crimes.size() + 1;
			char* sz_all_crimes = new char[all_crimes_size] {};
			std::strcpy(sz_all_crimes, all_crimes.c_str());
			Crime crime(0, "2000.01.01 00:00", "somewere");
			for (char* pch = strtok(sz_all_crimes, ","); pch; pch = strtok(NULL, ","))
			{
				if (strcmp(pch, " ") == 0)continue;
				time_t timestamp = std::stoi(pch);
				while (pch[0] == ' ')for (int i = 0; pch[i]; i++)pch[i] = pch[i + 1];
				pch = strchr(pch, ' ') + 1;
				int id = std::stoi(pch);
				pch = strchr(pch, ' ') + 1;
				crime.set_id(id);
				crime.set_timestamp(timestamp);
				crime.set_place(pch);
				base[licence_plate].push_back(crime);

				//elements[n++] = pch;
			}

			delete[] sz_all_crimes;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	cout << "База загружена" << endl;
	system("PAUSE");
}