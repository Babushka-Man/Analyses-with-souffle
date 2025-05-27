
#include <exception>
#include <cassert>

#include <souffle/SouffleInterface.h>

using souffle::RamDomain;
using souffle::SymbolTable;
using souffle::RecordTable;

using std::string;

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
    if((type1 == Positive && type2 == Negative) || (type1 == Negative && type2 == Positive)) {
        return Any;
    }
    if(type1 == Positive && type2 == Positive) {
        return Positive;
    }
    if(type1 == Negative && type2 == Negative) {
        return Negative;
    }
    throw std::runtime_error("Unexpected type combination in irTypeLub");
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
    throw std::runtime_error("Unexpected type combination in irTypeGlb");
}