#include<iostream>
#include<map>
#include<list>
#include<ctime>

using namespace std;

#define delimiter "\n------------------------------------------\n"
#define tab "\t"

//class time
//{
//	int год;
//	int месяц;
//	int день;
//	int час;
//	int минаты;
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
		//int tm_sec;   // секунды
		//int tm_min;   // минуты
		//int tm_hour;  // часы
		//int tm_mday;  // дни
		//int tm_mon;   // месяца
		//int tm_year;  // года
		//int tm_wday;  // дни недели
		//int tm_yday;  // дней в году
		//int tm_isdst; // флаг летнего времени ---- не нужно
	}

	Crimenal(int article, const std::string& guilty, время ? )
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
		{0, "Превышение скорости"},
		{1, "Нетрезвая езда"},
		{2, "Прозд на красный"},
		{3, "Пересечение двойной сплошной"},
		{4, "Выезд на встречную полосу"},
		{5, "Проезд над кирпичь"},
		{6, "Парковка на месте для инвалидов"},
		{7, "Танировка"},
		{8, "Отсутствие документов"},
	};
}