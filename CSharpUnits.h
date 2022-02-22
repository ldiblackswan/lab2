#ifndef CSHARPUNITS_H
#define CSHARPUNITS_H
#include "Units.h"

class CSharpClassUnit : public ClassUnit
{
public:

    explicit CSharpClassUnit(const std::string& name,
                             Flags modifier = ClassUnit::PUBLIC);
    ~CSharpClassUnit();

    std::string compile(unsigned int level = 0) const;
};

class CSharpMethodUnit : public MethodUnit
{
public:

    explicit CSharpMethodUnit(const std::string& name,
                              const std::string& returnType,
                              Flags flags);
    ~CSharpMethodUnit();

    std::string compile(unsigned int level = 0) const;
};

class CSharpPrintOperator : public PrintOperatorUnit
{
public:

    explicit CSharpPrintOperator(const std::string& text);
    ~CSharpPrintOperator();

    std::string compile(unsigned int level = 0) const;
};

#endif // CSHARPUNITS_H
