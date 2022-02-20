#pragma once
#include <string>
#include <memory>
#include <vector>

class Unit
{
public:
    using Flags = unsigned int;

    virtual void add(const std::shared_ptr< Unit >&, Flags);
    virtual std::string compile(unsigned int level = 0) const = 0; //возвращает строку сгенирированного кода
    virtual ~Unit() {}
protected:
    // отсуп вложенности
    virtual std::string generateShift(unsigned int level) const;
};


class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC = 0,
        PROTECTED = 1,
        PRIVATE = 1 << 1,
        ABSTRACT = 1 << 2,
        FINAL = 1 << 3,
        INTERNAL = 1 << 4,
        NONE
    };

    explicit ClassUnit(const std::string& name, Flags modifier = AccessModifier::NONE);
    virtual ~ClassUnit() {}
    // добавить unit к классу
    void add(const std::shared_ptr< Unit >& unit, Flags flags) override;

protected:
    using Fields = std::vector< std::shared_ptr<Unit> >;

    std::string m_name;
    Flags m_modifier; //модификаторы доступа для класса
    std::vector<Fields> m_fields; //список методов класса
    //список полей для модификатора доступа
    static const std::vector< std::string > ACCESS_MODIFIERS;
};

class MethodUnit : public Unit
{
public:
    // модификаторы доступа для методов
    enum AccessModifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        ABSTRACT = 1 << 3,
        FINAL = 1 << 4,
        INTERNAL = 1 << 5,
        NONE = 0 //нет модификаторов
    };

    MethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    virtual ~MethodUnit() = default;

    //добавить дочернюю языковую конструкцию
    void add(const std::shared_ptr< Unit >& unit, Flags = AccessModifier::NONE) override;

protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit> > m_body;
};

class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit(const std::string& text);
    virtual ~PrintOperatorUnit() = default;
protected:
    std::string m_text;
};
