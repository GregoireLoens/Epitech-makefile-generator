/*
** main.cpp for Epitech-makefile-generator in /home/loens_g/rendu/MyWork/Epitech-makefile-generator/sources/main.cpp
**
** Made by Gregoire LOENS
** Login   <gregoire.loens@epitech.eu>
**
** Started on  Tue Feb 14 16:10:29 2017 Gregoire LOENS
** Last update Tue Feb 14 16:10:29 2017 Gregoire LOENS
*/

#include "MakefileClass.hpp"

int		main()
{
  Mkf::MakefileClass	make;

  make.setUsrInfo();
  make.buildMakefile();
  return 0;
}