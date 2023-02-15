/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** OperandFactory.cpp
*/

#include "Factory.hpp"


std::array<IOperand * (*) (const std::string &), 6> Factory::operands = {
	Factory::createInt8,
	Factory::createInt16,
	Factory::createInt32,
	Factory::createFloat,
	Factory::createDouble,
	Factory::createBigDecimal
};

std::array<string, 6> Factory::toperands = { "int8", "int16", "int32", "float", "double", "bigdecimal" };

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{	
	return (operands[type])(value);
}

IOperand *Factory::createOperand(IOperand const *op)
{	
	return (operands[op->getType()])(op->toString());
}

IOperand *Factory::createOperand(string type, const string &value)
{	
	size_t i = 0;

	for (; i < 6; i++) {
		if (toperands[i] == type)
			break;
	}
	return (operands[i])(value);
}

IOperand * Factory::createInt8(const std::string &value)
{
	return (new Operand<int8_t>(INT8, value));
}

IOperand * Factory::createInt16(const std::string &value)
{
	return (new Operand<int16_t>(INT16, value));
}

IOperand * Factory::createInt32(const std::string &value)
{
	return (new Operand<int32_t>(INT32, value));
}

IOperand * Factory::createFloat(const std::string &value)
{
	return (new Operand<float>(FLOAT, value, 7));
}

IOperand * Factory::createDouble(const std::string &value)
{
	return (new Operand<double>(DOUBLE, value, 15));
}

IOperand * Factory::createBigDecimal(const std::string &value)
{
	return (new Operand<int64_t>(BIGDECIMAL, value, 200));
}