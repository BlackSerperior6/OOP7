#pragma once

#include <iostream>

#include "Pair.h"

using namespace std;

template <typename T>
struct Node 
{
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
	T Data;
};

template <typename T>
class List
{
public:

    List() { head = nullptr, tail = nullptr, Lenght = 0; }

    ~List() { Clear(); }

    void Push_Back(T element)
    {
        Node<T>* new_node = new Node<T>;
        new_node->Data = element;

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }

        Lenght++;
    }

    void Push_Front(T element)
    {
        Node<T>* new_node = new Node<T>;
        new_node->Data = element;

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }

        Lenght++;
    }

    void Pop_Back() 
    {
        if (head == nullptr)
        {
            cout << "Список пуст. Нечего удалять!" << endl;
            return;
        }

        Node<T>* tmp;

        if (head == tail)
        {
            tmp = head;

            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete tmp;

        Lenght--;
    }

    void Pop_Front()
    {
        if (head == nullptr)
        {
            cout << "Список пуст. Нечего удалять!" << endl;
            return;
        }

        Node<T>* tmp;
        if (head == tail)
        {
            tmp = head;

            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tmp = head;
            head = head->next;
            head->prev = nullptr;
        }

        delete tmp;

        Lenght--;
    }

    T& operator[](int index)
    {
        if (index >= Lenght|| index < 0)
        {
            cout << "Index out of range, must be non negative and less than collection's size!" << endl;
            Clear();
            exit(0);
        }

        Node<T>* current = head;

        for (int i = 0; i < index; i++)
            current = current->next;

        return current->Data;
    }

    List& operator=(List& anotherList)
    {
        if (this != &anotherList)
        {
            Clear();

            Node<T>* current = anotherList.head;

            while (current != nullptr)
            {
                Push_Back(current->Data);
                current = current->next;
            }
        }

        return *this;
    }

    int operator()() { return Lenght; }

    List& operator*=(List& anotherList)
    {
        int SmallerLenght = (anotherList.Lenght > Lenght) ? Lenght : anotherList.Lenght;

        for (int i = 0; i < SmallerLenght; i++)
            (*this)[i] *= anotherList[i];

        return *this;
    }

    void Clear()
    {
        while (head != nullptr)
        {
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }

        tail = nullptr;

        Lenght = 0;
    }

    template <typename T>
    friend istream& operator>>(istream& stream, List<T>& list);

    template <typename T>
    friend ostream& operator<<(ostream& stream, List<T>& list);

private:

	Node<T>* head;
	Node<T>* tail;
	int Lenght;
};

template <typename T>
istream& operator>>(istream& stream, List<T>& list)
{
    list.Clear();

    int Lenght;

    cout << "Введите длину списка: "; stream >> Lenght;

    for (int i = 0; i < Lenght; i++)
    {
        T data;
        cout << "Введите данные: "; stream >> data;
        list.Push_Back(data);
    }

    return stream;
}

template <typename T>
ostream& operator<<(ostream& stream, List<T>& list)
{
    if (list.Lenght == 0)
        stream << "Пустой список!";
    else
    {
        Node<T>* current = list.head;

        stream << current->Data;

        current = current->next;

        while (current != nullptr)
        {
            stream << " " << current->Data;
            current = current->next;
        }
    }

    return stream;
}

