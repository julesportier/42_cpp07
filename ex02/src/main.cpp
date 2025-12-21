#include <iostream>
#include "Array.h"

void print_exception(const std::exception& e)
{
	std::cout << "Error: " << e.what() << '\n';
}

int main(void)
{
	Array<int> def;	
	try {
		std::cout << def[0] << '\n';
	} catch (const std::exception& e) {
		print_exception(e);
	}

	Array<int> i_arr(5);
	fill_array(i_arr, 3, 2);
	print_array(i_arr, "i_arr");

	Array<int> i_arr_cpy(i_arr);
	print_array(i_arr_cpy, "i_arr_cpy");

	fill_array(i_arr, -20, 5);
	print_array(i_arr, "i_arr");
	Array<int> a_arr = i_arr;
	print_array(a_arr, "a_arr");

	Array<std::string> s_arr(3);
	s_arr[0] = "foo";
	s_arr[1] = "bar";
	s_arr[2] = "2000";
	print_array(s_arr, "s_arr");
	Array<std::string> s_arr_cpy(s_arr);
	print_array(s_arr_cpy, "s_arr_cpy");
	Array<std::string> s_arr_a = s_arr;
	print_array(s_arr_a, "s_arr_a");

	return (0);
}
