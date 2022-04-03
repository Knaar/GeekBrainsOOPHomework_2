#include <iostream>
#include <string>
using namespace std;
//Hi there!
/*1. Создать класс Person (человек) с полями: имя, возраст, пол и вес.
Определить методы переназначения имени, изменения возраста и веса.
Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения.
Создать счетчик количества созданных студентов. В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.*/
static int Students;
class Person
{
private:
	string Name;
	unsigned int Age, Gender;
	double Weight;

public:
	Person(string MakeName="", int InitAge=0, int Gender=0, double SetWeight=0) :Name(MakeName), Age(InitAge), Gender(Gender), Weight(SetWeight)
	{	}
	void SetName(string MakeName) { this->Name = MakeName; }
	void SetAge(int InitAge) { this->Age = InitAge; }
	void SetWeight(float SetWeight) { this->Weight = SetWeight; }

	string const GetName() { return Name; }
	int const GetAge() { return Age; }
	int const GetGender() { return Gender; }
	double const GetWeight() { return Weight; }

	void Print() {
		
		cout <<"Name: " << GetName() << ", Age: " << GetAge() << ", Gender :";

		GetGender() == 0 ? cout << " Female" : cout<<" Male";

		cout << ", Weight: " << GetWeight() <<endl;
	}
};
class Student :public Person
{
private:
	int Course;

public:
	Student(string MakeName = "", int InitAge = 0, int Gender = 0, double SetWeight = 0, int SetCourse = 0) :Person(MakeName, InitAge, Gender, SetWeight), Course(SetCourse){++Students;}

	void SetCourse(int Course) { this->Course = Course; }
	int GetCourse() { return Course; }
	
	static int ObjCount() { return Students; }


	void Print() {
		cout  << "Name: " << GetName() << ", Age: " << GetAge() << ", Gender :";
		GetGender() == 0 ? cout << " Female" : cout << " Male";//Вывод пола сделал через if. Можно через булевую
		cout << ", Weight: " << GetWeight() <<" Course: "<<GetCourse()  << endl;
	}
	

	~Student() { --Students; }
};
void HowManyStudents() { cout << "We got " << Student::ObjCount()<<" students"<<endl<<endl; }



/*2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
У Fruit есть две переменные-члена: name (имя) и color (цвет).
Добавить новый класс GrannySmith, который наследует класс Apple.*/


class Fruit
{
private:
	string Name, Color;
public:
	Fruit(string FruitName, string FruitColour) :Name(FruitName), Color(FruitColour)
	{	}
	string getName() const { return Name; }
	string getColor() const { return Color; }
};

class Apple:public Fruit
{
public:
	Apple( string FruitColour, string FruitName="apple") :Fruit( FruitColour,FruitName){}
};

class GrannySmith :public Apple{
public:
	GrannySmith(string FruitName = "Granny Smith Apple", string FruitColour = "green") :Apple(FruitName, FruitColour) {}
};

class Banana :public Fruit
{
public:
	Banana(string FruitName="Banana", string FruitColour = "yellow") :Fruit(FruitName, FruitColour){}
};




int main()
{
	/*1. Создать класс Person (человек) с полями: имя, возраст, пол и вес.
	Определить методы переназначения имени, изменения возраста и веса.
	Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения.
	Создать счетчик количества созданных студентов. В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.*/
	Person SomePerson("Knaar", 32, 1, 90.3);
	SomePerson.Print();


	Student HeDontReady("Boris", 22, 1, 44.5, 3);
	Student DidntLearn("Petya", 22, 1, 55.44, 3);
	Student Overslept("Tatyana", 21, 0, 48, 3);
	HeDontReady.Print();
	DidntLearn.Print();
	Overslept.Print();
	HowManyStudents();
	/*2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
	У Fruit есть две переменные-члена: name (имя) и color (цвет).
	Добавить новый класс GrannySmith, который наследует класс Apple.*/
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}
/*3. Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование.
Сколько будет классов в программе? Какие классы будут базовыми, а какие производными?
Продумать реализацию игры с помощью классов и записать результаты в виде комментария в основном файле сдаваемой работы.*/

/*
* 1. класс будет "Card". Это стопка от которой будет получать и игроки и дилер
*		Карта будет иметь номинал.Будет иметь возможность вызываться, и может повторяться(т.к.8 колод карт).
*		Я бы хотел реализовать возможность получать рандомную карту.
* 2. класс будет "Hand". Он будет унастледоваться дочерними классами "Dealer" и "Players". А "Players" будет подразделаться дополнительно на случай, если игроков несколько.
*		По идее игроков может быть до 7чел. Это отличная возможность попрактиковаться.
*		Все игроки(в т.ч. дилер) будут получать карты и принимать решение поочереди.
*		У игрока будет Имя, 2 выпавшие карты, сумма номинала и возможность попросить еще карту или остановить набор
* 3. Можно усложнить и сделать ставки.
*		добавить класс Кошелёк, который унаследуют все игроки. Как реализовать-пока не понимаю. Через векторный массив.
* 4  Можно сделать ещё интереснее и создать реальную колоду карт 
*/