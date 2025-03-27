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

		int i = 0; //�����е�ָ��
		int j = 0; //�Ӵ��е�ָ��
		while (i < string.length())
		{
			if (string[i] == patt[j]) //���ƥ�䣬��������һλ
				i++, j++;
			else if (j > 0) //���ƥ��ʧ�ܣ�����next���������Ӵ��е�һ����
				j = next[j - 1];
			else //���һ��ʼ�Ͳ�ƥ�䣬��i������
				i++;

			if (j == patt.length()) //�ҵ��Ӵ�
				return i - j;
		}

		return -1;//δ�ҵ��Ӵ�
	}

	std::vector<int> Next(const std::string& patt)
	{
		std::vector<int> next;
		next.push_back(0); //next�����һ��Ԫ��һ����0

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