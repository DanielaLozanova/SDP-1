#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<fstream>
using namespace std;

class Izraz {
private:
	stack<unsigned long long int> stI;
	stack<char> stC;

	unsigned long long int fact(unsigned long long int x);
	unsigned long long int f(unsigned long long int x);
	unsigned long long int g(unsigned long long int x);
	unsigned long long int m(unsigned long long int x, unsigned long long int y);
	string::const_iterator & charToInt(string::const_iterator& it, const string s);
	bool read(const string);
	void calculate();
public:
	Izraz() {};
	void r(const string& path);
};

void Izraz::calculate() {
	char c = stC.top();
	stC.pop();

	unsigned long long int x, z;
	x = stI.top();
	stI.pop();

	if (c == 'm')
	{
		unsigned long long y = stI.top();
		stI.pop();
		z = m(x, y);
	}
	if (c == 'g')
	{
		z = g(x);
	}
	if (c == 'f')
	{
		z = f(x);
	}
	stI.push(z);
}

void Izraz::r(const string & path)
{
	ifstream file(path);
	if (!file)
	{
		cout << "Error file cannot be opened " << endl;
		return;
	}
	unsigned int n = 0,cnt = 0;
	file >> n;
	file.get();
	while (cnt < n)
	{
		string str;
		getline(file, str);
		read(str);
		++cnt;
	}
	file.close();
}

unsigned long long int Izraz::fact(unsigned long long int x)
{
	unsigned long long int factorial = 1;
	for (unsigned long long int i = 2; i <= x; ++i)
	{
		factorial = factorial * i;
	}
	return factorial;
}

unsigned long long int Izraz::f(unsigned long long int x)
{
	return (x * x) % 100;
}

unsigned long long int Izraz::g(unsigned long long int x)
{
	unsigned long long int t = x % 5;
	unsigned long long int s = fact(t);
	return s;
}

unsigned long long int Izraz::m(unsigned long long int x, unsigned long long int y)
{
	if (x < y) return x;
	else return y;
}

string::const_iterator & Izraz::charToInt(string::const_iterator & it, const string s)
{
	int cToI, in = 0;
	while (*it >= '0' && *it <= '9')
	{
		cToI = *it - '0';
		in = 10 * in + cToI;
		++it;
	}
	stI.push(in);
	it--;
	return it;
}

bool Izraz::read(const string s)
{
	unsigned long long int x, y, z;
	unsigned int cntB = 0;
	for (string::const_iterator it = s.begin(); it != s.end(); ++it)
	{
		char c;
		if (*it == '(') ++cntB;
		if (*it == 'm' || *it == 'g' || *it == 'f') stC.push(*it);
		if (*it >= '0' && *it <= '9') charToInt(it, s);
		if (*it == ')')
		{
			--cntB;
			calculate();
		}
	}
	if (cntB == 0)
	{
		x = stI.top();
		stI.pop();
		cout << s <<"  =  " << x << endl;
		return true;
	}
	else
	{
		cout << s << "Error invalid string" << endl;
		while (stC.empty()!=true)
		{
			stC.pop();
		}
		while (stI.empty() != true)
		{
			stI.pop();
		}
		return false;
	}
}

int main()
{
	Izraz s;
	s.r("file.txt");
	return 0;
}
