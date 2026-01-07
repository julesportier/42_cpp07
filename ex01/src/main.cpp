#include "iter.h"
#include <iostream>

template <typename T>
void print_generic(T& s)
{
	std::cout << s << '\n';
};

static void inc_int(int &i)
{
	++i;
}

static void hello_string(std::string &str)
{
	str.insert(0, "hello ");
}

static void print_bold(std::string str)
{
	std::cout << "\e[1m" << str << "\e[0m\n";
}

int main(void)
{
	print_bold("NULL array address");
	try {
		iter<int>(NULL, 3, print_generic);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}

	print_bold("mutable int array");
	int i[3] = {22, 33, 44};
	iter(i, 3, print_generic);
	iter(i, 3, inc_int);
	iter(i, 3, print_generic);

	print_bold("\nimmutable int array");
	const int x[3] = {22, 33, 44};
	iter(x, 3, print_generic<const int>);
	iter(x, 3, print_generic);
	// doesn't compile because it drops const qualifier
	// iter(x, 3, inc_int);

	print_bold("\nmutable std::string array");
	std::string s[3] = {"aet", "dskfjh", "kajhfa"};
	iter(s, 3, print_generic);
	iter(s, 3, hello_string);
	return (0);
}
