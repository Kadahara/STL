
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<list>
#include<ctime>

using namespace std;

#define delimiter "\n------------------------------------------\n"
#define tab "\t"
#define TAKE_TIME int year, int month, int day, int hour, int minute
#define GIVE_TIME year, month, day, hour, minute

const std::map<int, std::string> crimenal =
{
	{1, "���������� ��������"},
	{2, "��������� ����"},
	{3, "����� �� �������"},
	{4, "����������� ������� ��������"},
	{5, "����� �� ��������� ������"},
	{6, "������ � ����������� �����"},
	{7, "�������� � ������������ �����"},
	{8, "���������"},
	{9, "���������� ����������"},
	{10, "����� �� �����������"},
	{11, "����������� �������"},
	
};
class Crimenal
{
	std::string licence_plate;	//�������� ���� ������
	int id;						//�������������� ������
	tm time;					//����� ���������
	std::string place;			//����� ���������
public:
	const std::string get_licence_plate()const
	{
		return licence_plate;
	}
	int get_id()const
	{
		return  id;
	}
	const char* get_time()const
	{
		char* time = asctime(&this->time);
		time[strlen(time) - 1] = 0; //������� ������� �� ����� ������
		return time;
	}
	const std::string& get_place()const
	{
		return place;
	}
	void set_licence_plate(const std::string& licence_plate)
	{
		this->licence_plate = licence_plate;
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
		strcpy(buffer, time.c_str()); //����� const char* c_str()const ���������� RAW-������, ������� ������������ ������ ������ 'std'
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
	Crimenal(const std::string& licence_plate, int id, const std::string& time, const std::string& place)
	{
		set_licence_plate(licence_plate);
		set_id(id);
		set_time(time);
		set_place(place);
	}
	~Crimenal() {};
};

std::ostream& operator<<(std::ostream& os, const Crimenal& obj)
{
	return os << obj.get_licence_plate() << " " << obj.get_id() << " " << obj.get_time() << " " << obj.get_place();
}
void main()
{
	setlocale(LC_ALL, "");
	Crimenal crime("aa777bb", 1, "2023.06.21 21:30", "��. ������");
	cout << crime;
}