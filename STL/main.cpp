#include<iostream>
#include<array>
#include<stack>
#include<vector>
#include<list>
#include<forward_list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-----------------------------------------\n"

template<typename T>void vector_properties(const std::vector<T>& vec);

//#define STL_ARRAY
//#define STL_STACK
//#define STL_VECTOR
#define STL_DEQUE
//#define STL_LIST

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello STL" << endl;

#ifdef STL_ARRAY
	
	const int N = 5;
	std::array<int, N> arr = { 3,5,8 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_STACK
	std::stack<int> stack;
	stack.push(3);
	stack.push(5);
	stack.push(8);
	stack.push(13);
	stack.push(21);
	while (!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
#endif // STL_STACK

#ifdef STL_VECTOR

	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	try
	{
		for (int i = 0; i < vec.size() * 2; i++)
		{
			//cout << vec.operator[](i) << tab;
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	vector_properties(vec);
	vec.push_back(55);
	vector_properties(vec);
	vec.reserve(25);	
	vec.resize(8);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	vector_properties(vec);

	cout << delimiter << endl;
	cout << std::vector<int>().max_size() << endl;
	cout << std::vector<double>().max_size() << endl;

	//int index;
	//int value;
	//cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	//cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	//vec.insert(vec.begin() + index, value);
	//for (int i : vec)cout << i << tab; cout << endl;

	vec.insert(vec.begin() + 3, {1024,2048,3072});
	for (int i : vec)cout << i << tab; cout << endl;
	vec.erase(vec.begin() + 5);
	for (int i : vec)cout << i << tab; cout << endl;
	cout << vec.front() << endl;
	cout << vec.back() << endl;
#endif // STL_VECTOR

#ifdef STL_DEQUE
	//deque (Double-Ended queue двунаправлени€ очеред) - это контейнер которыйц хранит данные в виде
	//списка динамических массивов, следовательно, относительно быстро добавл€ет значени€ как в конец, 
	// так и в начало.
#endif // STL_DEQUE
#ifdef STL_LIST
	std::list<int> list = { 3, 5, 8, 13, 21 };
	//for (int i = 0; i < list.size(); i++)
	//{
	//	cout << list[i] << tab;
	//}
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	int index;
	int value;
	do
	{
		cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
		if (index > list.size())cout << "Error: out of range" << endl;
	} while (index>list.size());
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	std::list<int>::iterator position = list.begin();
	for (int i = 0; i < index; i++)position++;
	list.insert(position, value);
	for (int i : list)cout << i << tab; cout << endl;
#endif // STL_LIST

	std::forward_list<int> f_list = { 3,5,8,13,21 };
	for (int i : f_list)cout << i << tab; cout << endl;
	f_list.push_front(2);
	for (int i : f_list)cout << i << tab; cout << endl;
	int size = std::distance(f_list.begin(), f_list.end());
	int index;
	int value;
	do
	{
		cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
		if (index > size)cout << "Error: out of range" << endl;
	} while (index > size);
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	std::forward_list<int>::iterator position = f_list.before_begin();
	std::advance(position, index);
	f_list.insert_after(position, value);
	for (int i : f_list)cout << i << tab; cout << endl;

}

template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:\t " << vec.size() << endl;
	cout << "Max size:" << vec.max_size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
}