/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Operand.cpp
*/

#include "Operand.hpp"

std::string precie(std::string string)
{
	if (string.find(".") != std::string::npos)
		while (string.back() == '0')
			string.pop_back();
	if (string.back() == '.')
		string.pop_back();
	return string;
}


template <typename T>
Operand<T>::Operand(eOperandType type, const std::string &value, int precision)
{

	this->type = type;
	this->value = value;
    this->_precision = precision;

	if (type != BIGDECIMAL) {
		double val = static_cast<double>(stod(value));

		double limit = getNumericLimit();

		if ((val > 0) && (limit) && (val > limit))
			throw BaseException("Constructor: Overflow !");
		if ((val < 0) && (limit) && (val < -limit - 1))
			throw BaseException("Constructor: Underflow !");
	}
}

template <typename T>
Operand<T>::~Operand()
{
}

template <typename T>
std::string Operand<T>::toString(void) const
{
	return precie(this->value);
}

template <typename T>
double Operand<T>::getNumericLimit(void) const
{

	return ((type == BIGDECIMAL) ? 0 : std::numeric_limits<T>::max());
}

template <typename T>
eOperandType Operand<T>::getType(void) const
{
	return this->type;
}

template <typename T>
int Operand<T>::getPrecision(void) const
{
	return _precision;
}

template <typename T>
IOperand *Operand<T>::operator+(IOperand const &target) const
{   
	std::string result = Utils::addStrings(this->value, target.toString());

	if (this->getPrecision() + target.getPrecision() < 1)
		result = result.substr(0, result.find(".", 0));

    return Factory::createOperand((this->getType() > target.getType()) ? this->getType() : target.getType(), result);
}

template <typename T>
IOperand *Operand<T>::operator-(IOperand const &target) const
{
	std::string result = Utils::subStrings(this->value, target.toString());

	if (this->getPrecision() + target.getPrecision() < 1)
		result = result.substr(0, result.find(".", 0));

    return Factory::createOperand((this->getType() > target.getType()) ? this->getType() : target.getType(), result);
}

template <typename T>
IOperand *Operand<T>::operator*(IOperand const &target) const
{
	std::string result = Utils::MulString(this->value, target.toString());

	if (this->getPrecision() + target.getPrecision() < 1)
		result = result.substr(0, result.find(".", 0));

    return Factory::createOperand((this->getType() > target.getType()) ? this->getType() : target.getType(), result);
}

template <typename T>
IOperand *Operand<T>::operator/(IOperand const &target) const
{
	if (!atof(target.toString().c_str()) || !atof(this->toString().c_str()))
    	throw MathException("Division by zero !");

	std::string result = Utils::DivString(this->value, target.toString());

	if (this->getPrecision() + target.getPrecision() < 1)
		result = result.substr(0, result.find(".", 0));

    return Factory::createOperand((this->getType() > target.getType()) ? this->getType() : target.getType(), result);
}

template <typename T>
IOperand *Operand<T>::operator%(IOperand const &target) const
{
	if (!atof(target.toString().c_str()) || !atof(this->toString().c_str()))
    	throw MathException("Modulo by zero !");
	if (this->getPrecision() > 0 || target.getPrecision() > 0)
        throw MathException("Modulo with floating value !");
	
	std::string result = Utils::ModString(this->value, target.toString());

	if (this->getPrecision() + target.getPrecision() < 1)
		result = result.substr(0, result.find(".", 0));

    return Factory::createOperand((this->getType() > target.getType()) ? this->getType() : target.getType(), result);
}

template <typename T>
bool Operand<T>::operator==(IOperand const &target) const
{
	return (this->toString() == target.toString());
}

template <typename T>
bool Operand<T>::operator!=(IOperand const &target) const
{
	return !(*this == target);
}