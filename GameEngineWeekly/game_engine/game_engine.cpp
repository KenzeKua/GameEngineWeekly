#include <iostream>
#include <Windows.h>
#include <List>
#include <Vector>

// Week 2A Exercise
class BitData
{
public:
    unsigned char m_data;

    BitData()
    {
        reset();
    }

    void reset()
    {
        m_data = 0;
        std::cout << "m_data set to 0\n\n";
    }
    void set(int location, bool flag)
    {
        /*if (flag)
        {
            m_data |= flag << location;
        }
        else if (!flag)
        {
            m_data |= ~(flag << location);
        }*/

        if (get(location) != flag)
        {
            m_data ^= 1 << location;
        }
    }
    bool get(int location)
    {
        return (m_data >> location) & 1;
    }
};

void Week1A()
{
    int num1 = 5;
    int num2 = 3;
    int num3 = 2;
    int* num4 = &num1;
    int& num5 = num2;
    int* num6 = num4;

    //test 1
    //std::cout << num1 << ", " << num4 << std::endl;

    //test 2
    //num1 = 10;
    //std::cout << num1 << ", " << num4 << std::endl;

    //test 3
    //num4 = 5675;
    //std::cout << num1 << ", " << num4 << std::endl;

    //test 4
    //std::cout << num1 << ", " << num5 << std::endl;

    //test 4b
    //num5 = 99;
    //std::cout << num1 << ", " << num5 <<", "<< num2 <<std::endl;

    //test 5
    //num6 = 200;
    //std::cout << *num6 << ", " << *num4 << ", " << num1 << std::endl;

    //test 6
    int** num7 = &num4;
    //std::cout<<&num4<<" ,"<<num4<<std::endl;
    std::cout << num7 << ", " << num4 << ", " << *num7 << ", " << &num1 << std::endl;

    system("pause");
}

void Week1B()
{
    std::list<int> listContainer;
    listContainer.push_back(100);
    listContainer.push_back(200);
    listContainer.push_back(300);
    listContainer.push_back(400);

    std::list<int>::iterator iter = listContainer.begin();
    std::list<int>::iterator iter3;
    while (iter != listContainer.end())
    {
        if (*iter == 300)
        {
            //iter3 = iter;
            iter = listContainer.erase(iter);
        }
        else
        {
            std::cout << *iter << std::endl;
            iter++;
        }
    }
    std::cout << *iter3 << std::endl;
}

void Week2A()
{
    // Using | and & operator to convert decimal to binary and then reading the value
    // Using bit shift, bit shifts are these: << and >>
    // Using bitwise negation (~)
    int a = 7;
    int b = 1;
    int c = a >> b;

    std::cout << c << std::endl;
}

void Week2AExercise()
{
    // Using the BitData class
    BitData dat;

    dat.set(0, true);
    dat.set(1, false);
    dat.set(2, true);
    dat.set(3, true);
    dat.set(3, false);

    for (int i = 0; i < 4; i++)
    {
        std::cout << (int)dat.get(i) << std::endl;
    }
}

int main(void)
{
    Week2A();

    return 0;
}