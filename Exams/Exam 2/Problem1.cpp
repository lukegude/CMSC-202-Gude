/*expected output 

Box cannot flower yet.
Box has started to flower!
Oak grows. Oak now towers over other plants.



Given the following output and main function and write the class definitions for the Plant, Tree, and Bush classes. 
Tree and Bush inherit from Plant. Write the three classes and all function definitions. 
Plant should have two private members : a boolean called m_isMature, and a string called m_name. 
It should have a constructor, a getter and setter for name, a function isMature() (the getter for m_isMature), 
and a void function called beginFlowering(), which will set m_isMature to true and print “PLANTNAME " has started to flower!” 
where PLANTNAME is the name of the plant (m_name). The Tree class should have one void function called grow that prints out a message
like “A tree now towers over other plants.” The Bush should have a similar function called grow, that prints out a message depending 
on the value of isMature – one that it can’t flower yet and one if it displays its flowers.
 */

#include <iostream>
#include <string>
using namespace std;
//Write Plant, Tree, and Bush here:

class Plant
{

public:
    Plant()
    {
        m_isMature = false;
    }

    bool isMature()
    {
        return m_isMature;
    }

    string getName()
    {
        return m_name;
    }

    void setName(string name)
    {
        m_name = name;
    }

    void beginFlowering()
    {
        m_isMature = true;
        cout << m_name << " has started to flower!" << endl;
    }

private:
    bool m_isMature;
    string m_name;
};

class Tree : public Plant
{
public:
    Tree() {}
    void grow()
    {
        cout << Tree::getName() << " grows. ";
        cout << Tree::getName() << " now towers over other plants." << endl;
    }
};

class Bush : public Plant
{
public:
    Bush() {}
    void grow()
    {
        if (Bush::isMature())
        {
            cout << Bush::getName() << " grows. ";
        }
        else
        {
            cout << Bush::getName() << " cannot flower yet." << endl;
        }
    }
};

int main()
{
    Tree plant1;
    Bush plant2;

    plant1.setName("Oak");
    plant2.setName("Box");
    plant2.grow();
    plant2.beginFlowering();

    plant1.grow();
    return 0;
}
