#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

bool is_not_word(char ch)
{
	char good_symbols[] = ",!?;:\"'() \n\r";

	for (size_t i = 0; i < strlen(good_symbols); i++)
		if (ch == good_symbols[i])
			return true;

	return false;
}

char* read_text(int& text_len)
{
	ifstream fin("text.txt");

	if (!fin.is_open())
	{
		cout << "File open error" << endl;
		return nullptr;
	}

	fin.seekg(0, ios_base::end);
	text_len = fin.tellg();
	fin.seekg(0, ios_base::beg);

	char* text = new char[text_len + 1];
	fin.get(text, text_len + 1);

	fin.close();

	return text;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// чтение текста
	int text_len = 0;
	char* text = read_text(text_len);

	if (text == nullptr)
	{
		cout << "File read error" << endl;
		return -1;
	}

	// ввод искомого слова
	char* word = new char[64];
	cout << "Введите слово: ";
	cin >> word;

	// поиск слов
	char* context;

	while (char* part = strtok_s(text, ".", &context))
	{
		for (size_t i = 0; i < strlen(part); i++)
		{
			if (part[i] == word[0])
			{
				bool contains = true;

				for (size_t j = 1; j < strlen(word); j++)
				{
					if (part[i + j] != word[j])
					{
						contains = false;
						break;
					}
				}

				if (contains && i > 0 && i < strlen(part) - 1)
					contains == is_not_word(part[i - 1]) && is_not_word(part[i + strlen(word)]);
				
				if (contains)
				{
					cout << part << endl;
					break;
				}
			}
		}

		text = nullptr;
	}

	return 0;
}