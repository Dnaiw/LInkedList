#include <iostream>
#include "List.h"

int main()
{
    List<List<double>*> lst;
    List<double> tmp1;
    tmp1.push_back(1.0);
    tmp1.push_back(2.0);
    tmp1.push_back(3.0);
    tmp1.push_back(4.0);
    lst.push_back(&tmp1);

    List<double> tmp2;
    tmp2.push_back(5.0);
    tmp2.push_back(5.0);
    tmp2.push_back(5.0);
    tmp2.push_back(5.0);
    lst.push_back(&tmp2);

    List<double> tmp3;
    tmp3.push_back(1.0);
    tmp3.push_back(2.0);
    tmp3.push_back(3.0);
    tmp3.push_back(4.0);
    lst.push_back(&tmp3);


    for (Node<List<double>*>* ptr = lst.head; ptr != NULL; ptr = ptr->next)
    {
        for (Node<double>* ptr2 = ptr->Data->head; ptr2 != NULL; ptr2 = ptr2->next)
        {
            std::cout << ptr2->Data << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    lst.pop_back();

    for (Node<List<double>*>* ptr = lst.head; ptr != NULL; ptr = ptr->next)
    {
        for (Node<double>* ptr2 = ptr->Data->head; ptr2 != NULL; ptr2 = ptr2->next)
        {
            std::cout << ptr2->Data << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl << (*lst[0])[0] << std::endl;
    std::cout << std::endl;

    List<double> tmp4;
    tmp4.push_back(0.0);
    tmp4.push_back(0.0);
    tmp4.push_back(0.0);
    tmp4.push_back(0.0);
    tmp4.push_back(0.0);
    tmp4.push_back(0.0);
    tmp4.push_back(0.0);

    lst.insert(1, &tmp4);

    for (Node<List<double>*>* ptr = lst.head; ptr != NULL; ptr = ptr->next)
    {
        for (Node<double>* ptr2 = ptr->Data->head; ptr2 != NULL; ptr2 = ptr2->next)
        {
            std::cout << ptr2->Data << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Length: " << lst.Count() << std::endl;
    std::cout << "Length of the first row: " << lst[0]->Count() << std::endl;


    try 
    {
        lst.insert(5, &tmp4);
    }
    catch (std::out_of_range ex)
    {
        std::cout << std::endl << "!!!!!!!!!" << ex.what() << "!!!!!!!!!!" << std::endl;
    }

    return 0;
}

