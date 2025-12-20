#include "iter.h"
#include <iostream>

static void print_int(int const &i)
{
	std::cout << i << '\n';
}

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
	print_bold("mutable int array");
	int i[3] = {22, 33, 44};
	iter(i, 3, print_int);
	iter(i, 3, inc_int);
	iter(i, 3, print_int);

	print_bold("\nimmutable int array");
	const int x[3] = {22, 33, 44};
	iter(x, 3, print_int);
	// doesn't compile because it drops const qualifier
	// iter(x, 3, inc_int);
	// iter(x, 3, print_int);

	print_bold("\nmutable std::string array");
	std::string s[3] = {"aet", "dskfjh", "kajhfa"};
	iter(s, 3, print_generic<std::string>);
	iter(s, 3, hello_string);
	iter(s, 3, print_generic<std::string>);
	try {
		iter(s, -3, print_generic<std::string>);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << '\n';
	}
	return (0);
}
