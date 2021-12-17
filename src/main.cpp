#include <functional>  // for function
#include <iostream>  // for basic_ostream::operator<<, operator<<, endl, basic_ostream, basic_ostream<>::__ostream_type, cout, ostream
#include <string>    // for string, basic_string, allocator
#include <vector>    // for vector
#include <unistd.h>
#include <filesystem>
#include <fstream>
 
#include "ftxui/component/captured_mouse.hpp"      // for ftxui
#include "ftxui/component/component.hpp"           // for Menu
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
				str regex = {' ', '$', '"', '#'};
				str reverseCurrent = current;
	//			reverse(reverseCurrent.begin(), reverseCurrent.end());
				std::cout << reverseCurrent << std::endl;
				for (str::iterator s = current.begin();s != current.end();s++)
				{
								if (*s == ':')
								{
												dst = current.substr(0, current.size() - 1);
												return (1);
								}
								for (str::iterator rs = regex.begin();rs != regex.end();rs++)
								{
												
												if (*rs == *s)
												{
													//			std::cout << "err: [" << *s << "]" << std::endl;
																return (0);
												}
								}
								sleep(1);
				}
				return (0);
}

std::vector<std::string> getMakefileRules(std::string path)
{
				using namespace ftxui;
				std::vector<std::string> rules;
				rules.push_back("Rule: test");
				std::ifstream src(path);
				if (src.fail() || !src.is_open())
								throw (FailedToOpenMakefile());
				str current = "";
				str ret = "";
				int i = 0;
				rules.push_back("test: ");
				/*
				rules.push_back("test $(test): ");
				std::cout << is_rule(rules[0], ret) << std::endl;
				std::cout << is_rule(rules[1], ret) << std::endl;
				*/
				while (std::getline(src, current))
				{
								if (is_rule(current, ret) == 1)
								std::cout << current << std::endl;
												//rules.push_back(ret);
				}
				//std::cout << path << std::endl;
				return (rules);
}

std::vector<std::string> get_fields(void)
{
				std::string pwd = std::filesystem::current_path();
				std::vector<std::string> ret;
				//std::cout << "pwd: " << pwd << std::endl;
				std::string path = pwd;
					    for (const auto & entry : std::filesystem::directory_iterator(path))
							{
								if (getFileNameFromPath(entry.path()) == "Makefile")
												return (getMakefileRules(entry.path()));
							}
				throw (noMakefile());
}

void	runMakefile(void)
{

				try{
				std::vector<std::string> fields = get_fields();
				int selected = newMenu(fields);
				}
				catch (const std::exception &e)
				{
								std::cerr << e.what() << std::endl;	
								exit (0);
				}
				std::vector<std::string> fields = get_fields();
				std::cout << fields[0] << std::endl;
}

int main(int argc, const char* argv[]) {
  using namespace ftxui;

	system("clear");
  pages page;
	std::vector<std::string> entries = {"test1", "test2"};
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
