#ifndef CSHARPCODEGENERATOR_H
#define CSHARPCODEGENERATOR_H
#include "Units.h"
#include "CSharpUnits.h"
#include "ICodeGenerator.h"

class CSharpCodeGenerator : public ICodeGenerator
{
public:

    explicit CSharpCodeGenerator() {}
    ~CSharpCodeGenerator() {}
    // ICodeGenerator interface
    std::shared_ptr<ClassUnit> createClassUnit(std::string name, uint32_t modifier = ClassUnit::NONE) const override {
        return std::make_shared<CSharpClassUnit>(name, modifier);
    }
    std::shared_ptr<MethodUnit> createMethodUnit(std::string name, std::string returnType,
                                                 uint32_t flags = MethodUnit::NONE) const override {
        return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(std::string text) const override {
        return std::make_shared<CSharpPrintOperator>(text);
    }
};
#endif // CSHARPCODEGENERATOR_H
