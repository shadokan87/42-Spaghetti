#include <functional>  // for function
#include <iostream>  // for basic_ostream::operator<<, operator<<, endl, basic_ostream, basic_ostream<>::__ostream_type, cout, ostream
#include <string>	 // for string, basic_string, allocator
#include <vector>	 // for vector
#include <unistd.h>
#include <filesystem>
#include <fstream>
#include <sys/wait.h>
#include <string.h>
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
#define COLOR(C, c) C << c << RESET

#include "ftxui/component/captured_mouse.hpp"	   // for ftxui
#include "ftxui/component/component.hpp"		   // for Menu
#include "ftxui/component/component_options.hpp"   // for MenuOption
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

typedef std::string str;

struct pages
{
	std::vector<std::string> home = {
		"1 -> Run",
		"2 -> Create",
	}; // main page
	std::vector<std::string> Run = {
		"1 -> Makefile",
		"2 -> Clang/gcc",
	}; // main page
};

int	newMenu(std::vector<std::string> &entries)
{
	using namespace ftxui;
	auto screen = ScreenInteractive::TerminalOutput();
	int selected = 0;

	MenuOption option;
	option.on_enter = screen.ExitLoopClosure();
	auto menu = Menu(&entries, &selected, &option);
	screen.Loop(menu);
	return (selected);
}

class execError : public std::exception { const char	*what() const throw() {return ("Exec error.");} };
class forkError : public std::exception { const char	*what() const throw() {return ("Fork error exiting now.");} };
class noMakefile : public std::exception { const char	*what() const throw() {return ("No makefile found !");} };
class FailedToOpenMakefile : public std::exception { const char	*what() const throw() {return ("Failed to open Makefile for reading !");} };

std::string getFileNameFromPath(std::string path)
{
	std::string ret = "";
	std::string pathCopy = path;
	reverse(pathCopy.begin(), pathCopy.end());
	ret = pathCopy;
	ret = ret.substr(0, pathCopy.find("/"));
	reverse(ret.begin(), ret.end());
	return (ret);
}

int	is_rule(str current, str &dst)
{
	str regex = {' ', '$', '"', '#', '.'};
	str reverseCurrent = current;
	reverse(reverseCurrent.begin(), reverseCurrent.end());
	for (str::iterator s = current.begin();s != current.end();s++)
	{
		if (*s == ':')
		{
			dst = current.substr(0, current.find(':'));
			return (1);
		}
		for (str::iterator rs = regex.begin();rs != regex.end();rs++)
		{

			if (*rs == *s)
				return (0);
		}
		//usleep(50000); for testing
	}
	return (0);
}

std::vector<std::string> getMakefileRules(std::string path)
{
	using namespace ftxui;
	std::vector<std::string> rules;
	std::ifstream src(path);
	if (src.fail() || !src.is_open())
		throw (FailedToOpenMakefile());
	str current = "";
	str ret = "";
	/* for testing
	while (std::getline(src, current))
	{
		if (is_rule(current, ret) == 1)
			std::cout << COLOR(GREEN, current) << std::endl;
		else
			std::cout << COLOR(YELLOW, current) << std::endl;
	}
	*/
	while (std::getline(src, current))
	{
		if (is_rule(current, ret) == 1)
			rules.push_back(ret);
	}
	return (rules);
}

std::vector<std::string> get_fields(void)
{
	std::string pwd = std::filesystem::current_path();
	std::vector<std::string> ret;
	std::string path = pwd;
	for (const auto & entry : std::filesystem::directory_iterator(path))
	{
		if (getFileNameFromPath(entry.path()) == "Makefile")
			return (getMakefileRules(entry.path()));
	}
	throw (noMakefile());
}

void	printSplit(char **split)
{
	int i = 0;
	while (split[i])
	{
		std::cout << COLOR(GREEN, split[i]) << std::endl;
		i++;
	}
}

#define LOG(X) std::cout << X << std::endl;
char	**vectorToSplit(std::vector<str> &vec)
{
	if (vec.size()  == 0)
		return (NULL);
	char **ret = new char *[vec.size() + 1];
	int i = 0;
	for (std::vector<str>::iterator begin = vec.begin();begin != vec.end();begin++)
	{
		ret[i] = new char [begin->size() + 1];
		copy(begin->begin(), begin->end(), ret[i]);
		ret[i][begin->size()] = '\0';
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
str	vectorToString(std::vector<str> vec)
{
	str ret = "";
	for (std::vector<str>::iterator begin = vec.begin();begin != vec.end();begin++)
		ret += *begin;
	return (ret);
}

char	*vectorToChar(std::vector<str> vec)
{
	int	totalSize = 0;
	for (std::vector<str>::iterator begin = vec.begin();begin != vec.end();begin++)
		totalSize += begin->size();
	char *ret = new char[totalSize + 1];
	int i = 0;
	str conv = vectorToString(vec);
	copy(conv.begin(), conv.end(), ret);
	ret[totalSize] = '\0';
	return (ret);
}

void	execMakefile(int selected, std::vector<str> fields)
{
	std::vector<str> toExec;
	toExec.push_back("make ");
	toExec.push_back(fields[selected]);
	char **ret = vectorToSplit(toExec);
	int pid;
	if ((pid = fork()) < 0)
		throw  (forkError());
	if (pid == 0)
	{
		system(vectorToChar(toExec));
	}
	else
	{
		waitpid(pid, 0, 0);
	}
}

void	runMakefile(void)
{

	try{
		std::vector<std::string> fields = get_fields();
		int selected = newMenu(fields);
		execMakefile(selected, fields);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;	
		exit (5);
	}
}

int main(int argc, const char* argv[]) {
	using namespace ftxui;

	system("clear");
	pages page;
	int selected = newMenu(page.home);
	if (selected == 0)
	{
		system("clear");
		selected = newMenu(page.Run);
		switch (selected)
		{
			case 0:
				runMakefile();
				break;
		}
	}
}
