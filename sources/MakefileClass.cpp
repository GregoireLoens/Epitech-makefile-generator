/*
** MakefileClass.cpp for Epitech-makefile-generator in /home/loens_g/rendu/MyWork/Epitech-makefile-generator/sources/MakefileClass.cpp
**
** Made by Gregoire LOENS
** Login   <gregoire.loens@epitech.eu>
**
** Started on  Tue Feb 14 16:27:57 2017 Gregoire LOENS
// Last update Tue Feb 28 09:51:09 2017 loens_g
*/

#include <fstream>
#include "MakefileClass.hpp"

void	Mkf::MakefileClass::printVar(std::ofstream &file)
{
  file << "INCLUDE\t\t=\t" << "\n\n";
  file << "RM\t\t=\trm -rf" << "\n\n";
  file << this->usrInfo.fileType << "FLAGS\t+=\t$(INCLUDE)\n\n"
       << this->usrInfo.fileType << "FLAGS\t+=\t -MD -MP" <<"\n\n";
  file << "LDFLAGS\t\t+=\t" << "\n\n";
  file << "CC\t\t=\t";
  file << this->usrInfo.comp << "\n\n";
  file << "DEBUG\t\t?=\t0" << "\n\n";
  file << "ifeq\t($(DEBUG), 1)\n\tCC\t=\t";
  file << this->usrInfo.comp << "\n\t";
  file << this->usrInfo.fileType << "FLAGS\t+=\t-g -ggdb3\nendif\n\n";
  file << "NAME\t\t=\t";
  file << this->usrInfo.project << "\n\n";
  file << "SRCS\t\t=\t\n\n";
  if (this->usrInfo.fileType == "C")
  {
    file << "OBJS\t\t=\t$(SRCS:.c=.o)\n\n";
    file << "DEPS\t\t=\t$(SRCS:.c=.d)\n\n\n";
  }
  else
  {
    file << "OBJS\t\t=\t $(SRCS:.cpp=.o)\n\n";
    file << "OBJS\t\t=\t $(SRCS:.cpp=.d)\n\n\n";
  }
}


void	Mkf::MakefileClass::printRules(std::ofstream &file)
{
  file << "all:\t$(NAME)\n\n$(NAME):\t$(OBJS)\n\t$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)\n\n";
  if (this->usrInfo.fileType == "C")
  {
    file << "%.o:\t%.c\n\t";
    file << "$(CC) -c -o $@ $< $(CFLAGS)\n\n";
  }
  else
  {
    file << "%.o:\t%.cpp\n\t";
    file << "$(CC) -c -o $@ $< $(CPPFLAGS)\n\n";
  }
  file << "clean:\n\t$(RM) $(OBJS) $(DEPS)\n\n";
  file << "fclean:\tclean\n\t$(RM) $(NAME) $(CLI)\n\n";
  file << "re:\tfclean\n\t@$(MAKE) all\n\n";
  file << ".PHONY:\t all clean fclean re\n\n";
  file << "-include\t$(DEPS)";
}

void	Mkf::MakefileClass::buildMakefile()
{
  std::ofstream		file("Makefile", std::ios::out);

  if (file)
  {
    this->printVar(file);
    this->printRules(file);
    file.close();
  }
}

void	Mkf::MakefileClass::setUsrInfo()
{
  std::cout << "Login (prenom.nom): " << "\n";
  std::cin >> this->usrInfo.login;
  std::cout << "Nom de projet: " << "\n";
  std::cin >> this->usrInfo.project;
  std::cout << "Compilateur (gcc, g++, clang): " << "\n";
  std::cin >> this->usrInfo.comp;
  std::cout << "Projet C ou CPP ?" << "\n";
  std::cin >> this->usrInfo.fileType;
}
