#ifndef ICODEGENERATOR_H
#define ICODEGENERATOR_H
#include "Units.h"

// интерфейс абстрактной фабрики
class ICodeGenerator
{
public:
    virtual std::shared_ptr<ClassUnit> createClassUnit(std::string name, uint32_t modifier = ClassUnit::NONE) const = 0;

    virtual std::shared_ptr<MethodUnit> createMethodUnit(std::string name, std::string returnType,
        uint32_t flags = MethodUnit::NONE) const = 0;
    virtual  std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(std::string text) const = 0;
    virtual ~ICodeGenerator() {};
};

#endif // ICODEGENERATOR_H
