#include <iostream>
#include <list>
using namespace std;

class Element;
class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
    virtual void VisitConcreteElementA(ConcreteElementA* ca) = 0;
    virtual void VisitConcreteElementB(ConcreteElementB* cb) = 0;
};

class ConcreteVisitorA : public Visitor {
public:
    void VisitConcreteElementA(ConcreteElementA* ca);
    void VisitConcreteElementB(ConcreteElementB* cb);
};

class ConcreteVisitorB : public Visitor {
public:
    void VisitConcreteElementA(ConcreteElementA* ca);
    void VisitConcreteElementB(ConcreteElementB* cb);
};

class ConcreteVisitorC : public Visitor {
public:
    void VisitConcreteElementA(ConcreteElementA* ca);
    void VisitConcreteElementB(ConcreteElementB* cb);
};

class Element {
public:
    virtual void Accept(Visitor* visitor) = 0;
};

class ConcreteElementA : public Element {
public:
    void Accept(Visitor* visitor);
    void OperationA();
};

class ConcreteElementB : public Element {
public:
    void Accept(Visitor* visitor);
    void OperationB();
};