#ifndef JAVACODEGENERATOR_H
#define JAVACODEGENERATOR_H
#include "Units.h"
#include "JavaUnits.h"
#include "ICodeGenerator.h"

class JavaCodeGenerator : public ICodeGenerator
{
public:

    explicit JavaCodeGenerator() {}
    ~JavaCodeGenerator() {}
    // ICodeGenerator interface
    std::shared_ptr<ClassUnit> createClassUnit(std::string name, uint32_t modifier = ClassUnit::NONE) const override {
        return std::make_shared<JavaClassUnit>(name, modifier);
    }
    std::shared_ptr<MethodUnit> createMethodUnit(std::string name, std::string returnType,
                                                 uint32_t flags = MethodUnit::NONE) const override {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(std::string text) const override {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};
#endif // JAVACODEGENERATOR_H
