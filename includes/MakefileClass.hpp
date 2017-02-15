/*
** MakefileClass.hpp for Epitech-makefile-generator in /home/loens_g/rendu/MyWork/Epitech-makefile-generator/includes/MakefileClass.hpp
**
** Made by Gregoire LOENS
** Login   <gregoire.loens@epitech.eu>
**
** Started on  Tue Feb 14 16:12:47 2017 Gregoire LOENS
** Last update Tue Feb 14 16:12:47 2017 Gregoire LOENS
*/

#ifndef _MAKEFILECLASS_HPP
#define _MAKEFILECLASS_HPP

#include <iostream>
#include <string>

namespace Mkf
{
  typedef struct s_user
  {
    std::string	login;
    std::string	comp;
    std::string	fileType;
    std::string	project;
  }		s_user;

  class MakefileClass
  {
  private:
    s_user usrInfo;

  public:
    void	buildMakefile();
    void	printVar(std::ofstream &file);
    void	printRules(std::ofstream &file);
  public:
    void	setUsrInfo();

  public:
    MakefileClass() {};
    ~MakefileClass() {};
  };
}
#endif // _MAKEFILECLASS_HPP
