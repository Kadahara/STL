#include<iostream>
#include<map>
#include<list>
#include<ctime>

using namespace std;

#define delimiter "\n------------------------------------------\n"
#define tab "\t"

//class time
//{
//	int ���;
//	int �����;
//	int ����;
//	int ���;
//	int ������;
//};
class Crimenal
{
	int article;
	std::string guilty;
	tm time;
public:
	int get_article()const
	{
		return article;
	}
	const std::string& get_guilry()const
	{
		return guilty;
	}
	const char* get_time()const
	{
		return asctime(&time);
	}
	void set_article(int article)
	{
		this->article = article;
	}
	void set_guilty(const std::string& guilty)
	{
		this->guilty = guilty;
	}
	void set_time()const
	{
		//int tm_sec;   // �������
		//int tm_min;   // ������
		//int tm_hour;  // ����
		//int tm_mday;  // ���
		//int tm_mon;   // ������
		//int tm_year;  // ����
		//int tm_wday;  // ��� ������
		//int tm_yday;  // ���� � ����
		//int tm_isdst; // ���� ������� ������� ---- �� �����
	}

	Crimenal(int article, const std::string& guilty, ����� ? )
	{
		set_article(article);
		set_guilty(guilty);
		set_time(? ? ? );
	}
	~Crimenal() {};

	void print()
};
void main()
{
	setlocale(LC_ALL, "");
	std::map<int, std::string> crimenal =
	{
		{0, "���������� ��������"},
		{1, "��������� ����"},
		{2, "����� �� �������"},
		{3, "����������� ������� ��������"},
		{4, "����� �� ��������� ������"},
		{5, "������ ��� �������"},
		{6, "�������� �� ����� ��� ���������"},
		{7, "���������"},
		{8, "���������� ����������"},
	};
}