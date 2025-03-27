#include <iostream>
#include <vector>
#include <string>

class KMP
{
private:
	std::string string;
	std::string patt;
public:
	KMP()
	{

	}

	KMP(const std::string& string, const std::string& patt)
		:string(string), patt(patt)
	{

	}

	int kmp_search(const std::string& string, const std::string& patt)
	{
		std::vector<int> next = Next(patt);

		int i = 0; //主串中的指针
		int j = 0; //子串中的指针
		while (i < string.length())
		{
			if (string[i] == patt[j]) //如果匹配，则往后移一位
				i++, j++;
			else if (j > 0) //如果匹配失败，根据next数组跳过子串中的一部分
				j = next[j - 1];
			else //如果一开始就不匹配，则i往后移
				i++;

			if (j == patt.length()) //找到子串
				return i - j;
		}

		return -1;//未找到子串
	}

	std::vector<int> Next(const std::string& patt)
	{
		std::vector<int> next;
		next.push_back(0); //next数组第一个元素一定是0

		for (int i = 1, j = 0; i < patt.length(); i++)
		{
			while (j > 0 && patt[i] != patt[j])
				j = next[j - 1];

			if (patt[i] == patt[j])
				j++;

			next.push_back(j);
		}

		return next;
	}
};

int main()
{
	std::string string = "ABABABC";
	std::string patt = "ABABC";
	KMP m_kmp(string, patt);

	int pos = m_kmp.kmp_search(string, patt);
	if (pos != -1)
	{
		std::cout << "Pattern found at position: " << pos << std::endl;
	}
	else
	{
		std::cout << "Pattern not found." << std::endl;
	}

	std::cin.get();
}