/*
Run this script to compile the functors.cpp file into a shared library:

g++ functors.cpp -c -fPIC -o functors.o 
g++ -shared -o libfunctors.so functors.o 
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH:+$LD_LIBRARY_PATH:}`pwd`
*/


#include <exception>
#include <cassert>
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>

#include <souffle/SouffleInterface.h>

using souffle::RamDomain;
using souffle::SymbolTable;
using souffle::RecordTable;

using std::string;
using namespace std; 

// Should be sorted alphabetically!!!
enum irType {
    Any = 0,
    Bottom,
    Even,
    Negative,
    NonNegative,
    NonPositive, 
    Positive,  
    UnEven,
    Zero,
};

class Validator {
private:
    RamDomain _type1;
    RamDomain _type2;
    bool _isValid = false;
    shared_ptr<Validator> _v = nullptr;

protected:
    void setValidator(shared_ptr<Validator> v) {
        _v = std::move(v);
    }

    void setIsValid(bool isValid) {
        _isValid = isValid;
    }

    bool getIsValid() const {
        return _isValid;
    }

public:
    Validator(RamDomain type1, RamDomain type2) : _type1(type1), _type2(type2) {}

    shared_ptr<Validator> symRelHolds(RamDomain goalType1, RamDomain goalType2) {
        if(_v == nullptr) {
            _v = std::make_shared<Validator>(_type1, _type2);
            _v->setValidator(_v);
        }
    
        _v->setIsValid(_v->getIsValid() || 
                       ((_type1 == goalType1 && _type2 == goalType2) ||
                        (_type1 == goalType2 && _type2 == goalType1)));

        return _v;
    }
    
    shared_ptr<Validator> nonSymRelHolds(RamDomain goalType1, RamDomain goalType2) {
        if(_v == nullptr) {
            _v = std::make_shared<Validator>(_type1, _type2);
            _v->setValidator(_v);
        }
    
        _v->setIsValid(_v->getIsValid() || 
                       (_type1 == goalType1 && _type2 == goalType2));

        return _v;
    }

    bool evaluate() {
        return _v->getIsValid();
    }

};

extern "C" {
    RamDomain irTypeLub(SymbolTable* symbolTable, RecordTable* recordTable, RamDomain type1, RamDomain type2);
    RamDomain irTypeGlb(SymbolTable* symbolTable, RecordTable* recordTable, RamDomain type1, RamDomain type2);
    int stoi(const char * str);
    int stoiWithOp(const char * str, const char * op);
    int stoiWithUniOp(int num, const char * op);
    int stoiWithBinOp(int num1, int num2, const char * op);
    RamDomain unaryOpOnType(SymbolTable* st, int, RamDomain type, RamDomain op);
    RamDomain binaryOpOnTypes(SymbolTable* st, int, RamDomain type1, RamDomain type2, RamDomain op);
}

string typeToString(RamDomain type)
{
    switch (type) {
        case Any:
            return "Any";
        case Bottom:
            return "Bottom";
        case Negative:
            return "Negative";
        case NonNegative:
            return "NonNegative";
        case NonPositive:
            return "NonPositive";
        case Positive:
            return "Positive";
        case Zero:
            return "Zero";
        default:
            throw std::runtime_error("Error: Unsupported type in typeToString: " + typeToString(type));
    }
}

RamDomain negateType(RamDomain type)
{
    switch (type) {
            case Any:
                return Any;
            case Bottom:
                return Bottom;
            case Negative:
                return Positive;
            case NonNegative:
                return NonPositive;
            case NonPositive:
                return NonNegative;
            case Positive:
                return Negative;
            case Zero:
                return Zero;
            default:
                throw std::runtime_error("Error: Unsupported type in unaryOpOnType: " + typeToString(type));
        }
}

RamDomain binaryOpOnTypes(SymbolTable* st, int, RamDomain type1, RamDomain type2, RamDomain op)
{
    Validator validator(type1, type2);
    string opStr = st->decode(op);

    if(validator.symRelHolds(Even, UnEven)
                ->symRelHolds(UnEven, Bottom)
                ->symRelHolds(Even, Bottom)
                ->symRelHolds(Even, Even)
                ->symRelHolds(UnEven, UnEven)->evaluate()) {
        if(opStr == "*") 
        {
            if(type1 == Even || type2 == Even) {
                return Even;
            }
            return UnEven;
        }
        if(opStr == "+" || opStr == "-")
        {
            if(type1 == Even && type2 == Even) {
                return Even;
            }
            if(type1 == UnEven && type2 == UnEven) {
                return UnEven;
            }
            return UnEven;
        }
        if(opStr == "^" || opStr == "/")
        {
            return Bottom; 
        }
    }

    if(opStr == "+" || opStr == "-")
    {
        if(opStr == "-")
        {
            type2 = negateType(type2);
            validator = Validator(type1, type2);
        }
        if(type1 == type2) {
            return type1;
        }
        if(type1 == Zero) {
            return type2;
        }
        if(type2 == Zero) {
            return type1;
        }
        if(type1 == Any || type2 == Any) {
            return Any;
        }
        if(type1 == Bottom || type2 == Bottom) {
            return Bottom;
        }
        if(validator.symRelHolds(Positive, Negative)
                    ->symRelHolds(NonNegative, Negative)
                    ->symRelHolds(NonPositive, Positive)->evaluate()) {
            return Bottom;
        }
        if(validator.symRelHolds(NonPositive, Negative)->evaluate()) {
            return Negative;
        }
        if(validator.symRelHolds(NonNegative, Positive)->evaluate()) {
            return Positive;
        }
     
        throw std::runtime_error("Error: Unsupported types in binaryOpOnTypes: " + 
                                 typeToString(type1) + " " + opStr + " " + typeToString(type2));
    }
    if(opStr == "*" || opStr == "/")
    {
        if(opStr == "/") {
            if(type2 == Zero || type2 == Any || type2 == NonNegative || type2 == NonPositive) {
                throw std::runtime_error("Error: Division by zero in binaryOpOnTypes");
            }
        }
        if(type1 == type2) {
            return type1;
        }
        if(type1 == Zero || type2 == Zero) {
            return Zero;
        }
        if(type1 == Any || type2 == Any) {
            return Any;
        }
        if(type1 == Bottom || type2 == Bottom) {
            return Bottom;
        }
        if(type1 == Negative) {
            return negateType(type2);
        }
        if(type2 == Negative) {
            return negateType(type1);
        }
        if(type1 == Positive) {
            return type2;
        }
        if(type2 == Positive) {
            return type1;
        }
        if(validator.symRelHolds(NonNegative, NonPositive)->evaluate()) {
            return NonNegative;
        }
        if(validator.symRelHolds(NonNegative, NonNegative)
                    ->symRelHolds(NonPositive, NonPositive)->evaluate()) {
            return NonPositive;
        }
     
        throw std::runtime_error("Error: Unsupported types in binaryOpOnTypes: " +
                                 typeToString(type1) + " " + opStr + " " + typeToString(type2));
    }
    if(opStr == "^")
    {
        // Can't know. Need to know the evenness of the exponent 
        // (Positiveness analysis).

    }
 
 
    throw std::runtime_error("Error: Unsupported operator in binaryOpOnTypes: " + opStr);
}


RamDomain unaryOpOnType(SymbolTable* st, int, RamDomain type, RamDomain op)
{
    string opStr = st->decode(op);

    if(type == Even || type == UnEven)
    {
        return type;
    }

    if(opStr != "+" && opStr != "-")
    {
        throw std::runtime_error("Error: Unsupported operator in unaryOpOnType: " + opStr);
    }
    
    if(opStr == "-")
    {
        return negateType(type);
    }

    return type;
}

int stoiWithBinOp(int num1, int num2, const char * op)
{
    if(op[0] == '+')
    {
        return num1 + num2;
    }
    else if(op[0] == '-')
    {
        return num1 - num2;
    }
    else if(op[0] == '*')
    {
        return num1 * num2;
    }
    else if(op[0] == '/')
    {
        if(num2 == 0) {
            throw std::runtime_error("Error: Division by zero in stoiWithBinOp");
        }
        return num1 / num2;
    }
    
    throw std::runtime_error("Error: Unsupported operator in stoiWithBinOp: " + string(op));
    
}

int stoi(const char * str)
{
    return std::stoi(str);
}

int stoiWithUniOp(int num, const char * op)
{
    if(op[0] == '-')
    {
        return -num;
    }
    else if(op[0] != '+')
    {
        throw std::runtime_error("Error: Unsupported operator in stoiWithUniOp: " + string(op));
    }
    
    return num;
}

RamDomain irTypeLub(SymbolTable* symbolTable, RecordTable* recordTable, RamDomain type1, RamDomain type2)
{
    if(type1 == type2) {
        return type1;
    }
    if(type1 == Any || type2 == Any) {
        return Any;
    }
    if(type1 == Bottom) {
        return type2;
    }
    if(type2 == Bottom) {
        return type1;
    }

    Validator validator(type1, type2);
    
    if(validator.symRelHolds(Even, UnEven)->evaluate()) {
        return Any;
    }

    if(validator.symRelHolds(Zero, Negative)
                ->symRelHolds(Zero, Positive)
                ->symRelHolds(Positive, Negative)
                ->symRelHolds(Positive, NonPositive)
                ->symRelHolds(Negative, NonNegative)->evaluate()) {
        return Any;
    }
    if(validator.symRelHolds(Positive, NonNegative)->evaluate()) {
        return NonNegative;
    }
    if(validator.symRelHolds(Negative, NonPositive)->evaluate()) {
        return NonPositive;
    }
    if(validator.symRelHolds(NonNegative, NonPositive)->evaluate()) {
        return Any;
    }
    if(validator.symRelHolds(Zero, NonNegative)->evaluate()) {
        return NonNegative;
    }
    if(validator.symRelHolds(Zero, NonPositive)->evaluate()) {
        return NonPositive;
    }
    
    throw std::runtime_error("Error: Unexpected type combination in irTypeLub: " + 
                             std::to_string(type1) + ", " + std::to_string(type2));
}

RamDomain irTypeGlb(SymbolTable* symbolTable, RecordTable* recordTable, RamDomain type1, RamDomain type2)
{
    if(type1 == type2) {
        return type1;
    }
    if(type1 == Any)
    {
        return type2;
    }
    if(type2 == Any)
    {
        return type1;
    }
    if(type1 == Bottom || type2 == Bottom) {
        return Bottom;
    }

    Validator validator(type1, type2);

    if(validator.symRelHolds(Even, UnEven)->evaluate()) {
        return Bottom;
    }

    if(validator.symRelHolds(Zero, Negative)
                ->symRelHolds(Zero, Positive)
                ->symRelHolds(Positive, Negative)
                ->symRelHolds(Positive, NonPositive)
                ->symRelHolds(Negative, NonNegative)->evaluate()) {
        return Bottom;
    }
    if(validator.symRelHolds(Positive, NonNegative)->evaluate()) {
        return Positive;
    }
    if(validator.symRelHolds(Negative, NonPositive)->evaluate()) {
        return Negative;
    }
    if(validator.symRelHolds(NonNegative, NonPositive)->evaluate()) {
        return Zero;
    }
    if(validator.symRelHolds(Zero, NonNegative)
                ->symRelHolds(Zero, NonPositive)->evaluate()) {
        return Zero;
    }
    
    throw std::runtime_error("Error: Unexpected type combination in irTypeGlb: " + 
                             std::to_string(type1) + ", " + std::to_string(type2));
}