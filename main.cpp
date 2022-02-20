#include <iostream>
#include "CPlusPlusUnits.h"
#include "ICodeGenerator.h"
#include "CPlusPlusCodeGenerator.h"

std::string generateCode(const std::shared_ptr<ICodeGenerator>& generator)
{
    auto classUnit = generator->createClassUnit("MyClass", ClassUnit::PUBLIC | ClassUnit::FINAL);
    if(classUnit)
    {
        auto functionUnit1 = generator->createMethodUnit("testFunc1", "void");
        classUnit->add(functionUnit1, ClassUnit::PUBLIC);

        auto functionUnit2 = generator->createMethodUnit("testFunc2", "void", MethodUnit::INTERNAL);

        classUnit->add(functionUnit2, ClassUnit::PRIVATE);

        auto functionUnit3 = generator->createMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST);

        classUnit->add(functionUnit3, ClassUnit::PUBLIC);


        auto functionUnit4 = generator->createMethodUnit("testFunc4", "void", MethodUnit::STATIC);

        if (functionUnit4)
        {
            auto printUnit = generator->createPrintOperatorUnit(R"(Hello, world!\n)");
            functionUnit4->add(printUnit);
        }

        classUnit->add(functionUnit4, ClassUnit::PROTECTED);
    }
    //вернуть итоговую строку для класса и методов внутри
    return classUnit->compile();
}

int main()
{
    std::cout << generateCode(std::make_shared<CPlusPlusCodeGenerator>()) << std::endl;
    return 0;
}
