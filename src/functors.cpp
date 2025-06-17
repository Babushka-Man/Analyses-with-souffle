/*
Run this script to compile the functors.cpp file into a shared library:

g++ functors.cpp -c -fPIC -o functors.o 
g++ -shared -o libfunctors.so functors.o 
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH:+$LD_LIBRARY_PATH:}`pwd`
*/


#include <exception>
#include <cassert>

#include <souffle/SouffleInterface.h>

using souffle::RamDomain;
using souffle::SymbolTable;
using souffle::RecordTable;

using std::string;
using namespace std; 

extern "C" {
    RamDomain irTypeLub(SymbolTable* symbolTable, RecordTable* recordTable, RamDomain type1, RamDomain type2);
    RamDomain irTypeGlb(SymbolTable* symbolTable, RecordTable* recordTable, RamDomain type1, RamDomain type2);
}

enum irType {
    Any = 0,
    Positive, // non-negative 
    Negative,
    Bottom,
};

Class Validator {
private:
    RamDomain _type1;
    RamDomain _type2;
    bool _isValid = true;
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
            _v = std::make_shred<Validator>(_type1, _type2);
            _v->setValidator(_v);
        }
    
        _v->setIsValid(_v->getIsValid() && 
                       ((_type1 == goalType1 && _type2 == goalType2) ||
                        (_type1 == goalType2 && _type2 == goalType1)));

        return _v;
    }

    bool evaluate() {
        return _v->getIsValid();
    }

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

    if(validator.symRelHolds(Zero, Negative)
                .symRelHolds(Zero, Positive)
                .symRelHolds(Positive, Negative)
                .symRelHolds(Positive, NonPositive)
                .symRelHolds(Negative, NonNegative).evaluate()) {
        return Any;
    }
    if(validator.symRelHolds(Positive, NonNegative).evaluate()) {
        return NonNegative;
    }
    if(validator.symRelHolds(Negative, NonPositive).evaluate()) {
        return NonPositive;
    }
    if(validator.symRelHolds(NonNegative, NonPositive).evaluate()) {
        return Zero;
    }
    if(validator.symRelHolds(Zero, NonNegative)
                .symRelHolds(Zero, NonPositive).evaluate()) {
        return Zero;
    }
    
    throw std::runtime_error("Error: Unexpected type combination in irTypeLub");
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
    if((type1 == Positive && type2 == Negative) || (type1 == Negative && type2 == Positive)) {
        return Bottom;
    }
    if(type1 == Positive && type2 == Positive) {
        return Positive;
    }
    if(type1 == Negative && type2 == Negative) {
        return Negative;
    }
    throw std::runtime_error("Error: Unexpected type combination in irTypeGlb");
}