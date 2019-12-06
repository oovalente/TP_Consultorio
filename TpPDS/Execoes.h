#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class Ex_LinhaVazia :public exception
{
public:
	virtual const char* what() const noexcept override;
};

class Ex_LinhaNaoEncontrada :public exception
{
public:
	virtual const char* what() const noexcept override;
};