#include "visitor.h"

class ObjectStructure {
private:
	list<Element* > elements;
public:
	void Attach(Element* element) {
		elements.push_back(element);
	}
	void Detach(Element* element) {
		elements.remove(element);
	}
	void Accept(Visitor* visitor) {
		for (auto e = elements.begin(); e != elements.end(); e++) {
			(*e)->Accept(visitor);
		}
	}
};

int main() {
	ObjectStructure* o = new ObjectStructure();

	ConcreteElementA* ca = new ConcreteElementA();
	ConcreteElementB* cb = new ConcreteElementB();

	o->Attach(ca);
	o->Attach(cb);

	ConcreteVisitorA* cv1 = new ConcreteVisitorA();
	ConcreteVisitorB* cv2 = new ConcreteVisitorB();
	ConcreteVisitorC* cv3 = new ConcreteVisitorC();

	o->Accept(cv1);
	// ConcreteElementA: ConcreteVisitorA::VisitConcreteElementA
	// ConcreteElementB: ConcreteVisitorA::VisitConcreteElementB
	o->Accept(cv2);
	// ConcreteElementA: ConcreteVisitorB::VisitConcreteElementA
	// ConcreteElementB: ConcreteVisitorB::VisitConcreteElementB
	o->Accept(cv3);
	// ConcreteElementA: ConcreteVisitorC::VisitConcreteElementA
	// ConcreteElementB: ConcreteVisitorC::VisitConcreteElementB
	delete ca;
	delete cb;
	delete cv1;
	delete cv2;
	delete cv3;
	delete o;

	return 0;
}