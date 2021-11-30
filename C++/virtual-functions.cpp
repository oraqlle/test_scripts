#include <iostream>
#include <string>

class Ent
{
public:
	virtual std::string GetName() = 0; 
    // '= 0' at the end of virtual function means a child class has to create 
    // an implementation for the function, not the parent class. 
};

class Player : public Ent
{
private:
	std::string m_Name;

public:
	Player(const std::string& name) 
		: m_Name(name) {}

	std::string GetName() override { return m_Name; }
};

void printEnt(Ent* e)
{
	std::cout << e->GetName() << std::endl;
}

int main()
{
	Ent* e = new Player("y");
	printEnt(e);

	Player* p = new Player("Ty");
	printEnt(p);

	Ent* ent = p;
	printEnt(ent);

	std::cin.get();
	return 0;
}