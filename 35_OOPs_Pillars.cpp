#include<iostream>
using namespace std;

// Encapsulation
class Student {
    private: 
        string name;
        int age;
        int height;

    public:
        int getAge() {
            return this->age;
        }
};

// Inheritance
class Human {
    protected:
        int height;

    public:
        int weight;

    private:    
        int age;
    
    public:
        int getAge() {
            return this->age;
        }
    void setWeight(int w) {
        this->weight = w;
    }
};

class Male: private Human {
    public:
        string color;
    
        void sleep() {
            cout << "Male Sleeping" << endl;
        }

    int getHeight() {
        return this->height;
    }
};

/*
Types of Inheritance
1. Single Inheritance => when a class has only one child/derived class
2. MultiLevel => parent -> child -> child -> child ...
3. Multiple => when a class inherit more than one one class, means it has more than one parents
4. Hierarchical => a single parent class have more than one child
5. Hybrid => Combination of more than one type of inheritance
*/

/*
// 3. Multiple inheritance
class Animal {
    public:
        int age;
        int weight;

    public:
        void bark() {
            cout << "Barking" << endl;
        }
};

class Human {
    public:
        string color;

    public:
        void speak() {
            cout << "Speaking" << endl;
        }
};

class Hybrid: public Animal, public Human {

};
*/

/*
// 4.Hierarchical Inheritance
class A {
    public:
        void func1() {
            cout << "Inside function 1" << endl;
        }
};

class B: public A {
    public:
        void func2() {
            cout << "Inside function 2" << endl;
        }
};

class C: public A {
    public:
        void func3() {
            cout << "Inside function 3" << endl;
        }
};
*/

/*
// Ambiguity Inheritance
class A {
    public:
        void func() {
            cout << "I am A" << endl;
        }
};

class B {
    public:
        void func() {
            cout << "I am B" << endl;
        }
};

class C: public A, public B {

};
*/

// Polymorphism
// PolyMorphism types
// 1. Compile time Polymorphism  ==> Static Polymorphism
// 2. Run time Polymorphism ==> Dynamic Polymorphism

// 1. Compile time polymorphism and its types
// --> Function Overloading
// --> Operator Overloading

// --> Function Overloading
class A {
    public:
        void sayHello() {
            cout << "Hello Avinash Thakur" << endl;
        }

        // int sayHello(string name, int n) { // just changing the return type doesn't perform function overloading so we need to change the parameter
        int sayHello(char name) {
            cout << "Hello " << name << endl;
            return 1;
        }

        void sayHello(string name) {
            cout << "Hello " << name << endl;
        }
};

// --> Operator Overloading
class B {
    public:
        int a;
        int b;

    public:
        int add() {
            return a+b;
        }

        void operator+ (B &obj){
            /*
            int value1 = this->a;
            int value2 = obj.a;
            cout << "output: " << value2 -value1 << endl;
            */
           cout << "Hello Avinash" << endl;
        }

        void operator() () {
            cout << "I am Bracket" << this->a << endl;
        }
};

// 2. Run time Polymorphism
class Animal {
    public:
        void speak() {
            cout << "Speaking" << endl;
        }
};

class Dog: public Animal {
    public:
        void speak() {
            cout << "Barking" << endl;
        }
};

// Abstraction
// Synonym -> Implementation Hiding

int main() {
    /*
    Student first;
    */

    /*
    Male object1;
    cout << object1.age << endl; // inaccessible
    cout << object1.weight << endl;
    cout << object1.height << endl;
    
    cout << object1.color << endl;

    object1.sleep();
    object1.setWeight(85);
    cout << object1.weight << endl;
    */

    /*
    Male m1;
    cout << m1.getHeight() << endl;
    */

    /*
    // Multiple inheritance
    Hybrid obj1;
    obj1.speak();
    obj1.bark();
    */

    /*
    // Hierarchical Inheritance
    A object1;
    object1.func1();

    B object2;
    object2.func1();

    C object3;
    object3.func1();
    object3.func3();
    */

    /*
    // Ambiguity Inheritance
    C obj;
    // obj.func();

    obj.A::func();
    obj.B::func();
    */

    // 1. Compile time Polymorphism
    A obj;
    obj.sayHello();
    obj.sayHello();

    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();

    // 2. Run time polymorphism
    Dog obj3;
    obj3.speak();

    return 0;
}