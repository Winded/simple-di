#include "simple-di.hpp"
#include <iostream>

typedef std::shared_ptr<smdi::container> cptr;

class idep
{
public:
    virtual std::string getData() const = 0;
};

class dep1 : public idep
{
public:
    dep1(const cptr &container)
    {
    }

    std::string getData() const override
    {
        return "Hello from dep1!";
    }
};

class dep2 : public idep
{
public:
    dep2(const cptr &container)
    {
        m_Dep1 = container->get<dep1>();
    }

    std::string getData() const override
    {
        return m_Dep1->getData() + " Also from dep2!";
    }

private:
    std::shared_ptr<dep1> m_Dep1;
};

class dep3 : public idep
{
public:
    dep3(const cptr &container)
    {
        m_Dep = container->get_existing<idep>();
    }

    std::string getData() const override
    {
        return m_Dep->getData() + " And from dep3!";
    }

private:
    std::shared_ptr<idep> m_Dep;
};

int main()
{
    auto container = std::make_shared<smdi::container>();

    auto d2 = container->get<dep2>();
    container->set<idep>(d2);
    auto d3 = container->get<dep3>();
    std::cout << d3->getData() << std::endl;
}
