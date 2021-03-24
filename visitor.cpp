#pragma(once)

#include <iostream>
#include <list>
#include "visitor.h"

using namespace std;

void ConcreteVisitorA::VisitConcreteElementA(ConcreteElementA* ca) {
    cout << "ConcreteVisitorA::VisitConcreteElementA" << endl;
    ca->OperationA();
}
void ConcreteVisitorA::VisitConcreteElementB(ConcreteElementB* cb) {
    cout << "ConcreteVisitorA::VisitConcreteElementB" << endl;
    cb->OperationB();
}


void ConcreteVisitorB::VisitConcreteElementA(ConcreteElementA* ca) {
    cout << "ConcreteVisitorB::VisitConcreteElementA" << endl;
    ca->OperationA();
}
void ConcreteVisitorB::VisitConcreteElementB(ConcreteElementB* cb) {
    cout << "ConcreteVisitorB::VisitConcreteElementB" << endl;
    cb->OperationB();
}


void ConcreteVisitorC::VisitConcreteElementA(ConcreteElementA* ca) {
    cout << "ConcreteVisitorC::VisitConcreteElementA" << endl;
}
void ConcreteVisitorC::VisitConcreteElementB(ConcreteElementB* cb) {
    cout << "ConcreteVisitorC::VisitConcreteElementB" << endl;
}


void ConcreteElementA::Accept(Visitor* visitor) {
    cout << "ConcreteElementA: ";
    visitor->VisitConcreteElementA(this);
}
void ConcreteElementA::OperationA() {
    cout << "OperationA" << endl;
}

void ConcreteElementB::Accept(Visitor* visitor) {
    cout << "ConcreteElementB: ";
    visitor->VisitConcreteElementB(this);
}
void ConcreteElementB::OperationB() {
    cout << "OperationB" << endl;
}