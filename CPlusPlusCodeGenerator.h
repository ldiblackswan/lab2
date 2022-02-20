#ifndef CPLUSPLUSCODEGENERATOR_H
#define CPLUSPLUSCODEGENERATOR_H
#include "Units.h"
#include "CPlusPlusUnits.h"
#include "ICodeGenerator.h"

class CPlusPlusCodeGenerator : public ICodeGenerator
{
public:

    explicit CPlusPlusCodeGenerator() {}
    ~CPlusPlusCodeGenerator() {}
    // ICodeGenerator interface
    std::shared_ptr<ClassUnit> createClassUnit(std::string name, uint32_t modifier = ClassUnit::NONE) const override {
        return std::make_shared<CPlusPlusClassUnit>(name, modifier);
    }
    std::shared_ptr<MethodUnit> createMethodUnit(std::string name, std::string returnType,
                                                 uint32_t flags = MethodUnit::NONE) const override {
        return std::make_shared<CPlusPlusMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(std::string text) const override {
        return std::make_shared<CPlusPlusPrintOperatorUnit>(text);
    }
};

#endif // CPLUSPLUSCODEGENERATOR_H
