/*Задание 2. Описать структуру Man (Фамилия, Имя, Возраст, Дата рождения).
Создать массив, предусмотреть:
● Вывод информации с сортировкой по фамилии или имени
● Вывод списка именинников месяца с указанием даты рождения
● Изменение размеров массива при добавлении и удалении записей
● Поиск по фамилии и имени
● Редактирование записи*/

#include <string>
#include <iostream>
using namespace std;
struct man
{
    string name;
    string surname;
    int age;
    struct dateOfBirth
    {
        int day;
        int month;
        int year;
    };
    dateOfBirth dateOfBirthProp;
    void setMan()
    {
        cout << "#########################" << endl;
        cout << "------Enter-man-data------" << endl;
        cout << "#########################" << endl;
        cout << "Enter name: "; cin >> name;
        cout << "Enter surname: "; cin >> surname;
        cout << "Enter date of birth: " << endl;
        cout << "Enter day: "; cin >> dateOfBirthProp.day;
        cout << "Enter month: "; cin >> dateOfBirthProp.month;
        cout << "Enter year: "; cin >> dateOfBirthProp.year;
        age = 2023 - dateOfBirthProp.year;
        cout << "#########################" << endl;

    }
    void print()
    {
        cout << "#########################" << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Date of birth: " << dateOfBirthProp.day << "/" << dateOfBirthProp.month << "/" << dateOfBirthProp.year << endl;
        cout << "Age: " << age << endl;
        cout << "#########################" << endl;

    }
};
void printAllMen(man* menArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        menArray[i].print();
    }
}
int findSmallestPosition(man* menArray, int startPosition, int size)
{
    int smallestPosition = startPosition;
    for (int i = startPosition; i < size; i++)
    {
        if (menArray[i].name < menArray[smallestPosition].name)
        {
            smallestPosition = i;
        }

    }
    return smallestPosition;
}
void sort(man* menArray, int size)
{
    cout << "--------After-sort--------" << endl;
    for (int i = 0; i < size; i++)
    {
        int smallestPosition = findSmallestPosition(menArray, i, size);
        swap(menArray[i], menArray[smallestPosition]);
    }

}
void swap(man* man1, man* man2)
{
    man temp = *man1;
    *man1 = *man2;
    *man2 = temp;

}
void printBDAyBoys(man* menArray, int bDayMonth, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (menArray[i].dateOfBirthProp.month == bDayMonth)
        {
            menArray[i].print();
        }
    }
}
void addNewMan(man** menArray, int& size)
{
    man* newMenArray = new man[size + 1];
    for (int i = 0; i < size; i++)
    {
        newMenArray[i] = (*menArray)[i];
    }
    newMenArray[size].setMan();
    delete[] * menArray;
    (*menArray) = newMenArray;
    size++;
}

void editMan(man* menArray, int index)
{
    menArray[index].setMan();
}

void deleteMan(man** menArray, int& size, int index)
{
    if (*menArray == NULL || index < 0 || index >= size) {
        cout << "Invalid input" << endl;
        return;

    }
    man* newMenArray = new man[size - 1];
    for (int i = 0, j = 0; i < size - 1; i++)
    {
        if (i != index)
        {
            newMenArray[j++] = (*menArray)[i];
        }
    }
    cout << "---" << menArray[index]->name << "-Was-deleted!---" << endl;
    delete[] * menArray;
    (*menArray) = newMenArray;
    size--;
}
void findMan(man* menArray, string keyName, string keySurname, int size)
{
    cout << "------Search-results------" << endl;
    for (int i = 0; i < size; i++)
    {
        if (menArray[i].name == keyName && menArray[i].surname == keySurname)
        {
            menArray[i].print();
        }
    }
}
int main()
{
    int size = 3;
    man m1 = { "Cegey", "Grigoriev", 27, 12, 06, 1999 };
    man m2 = { "Bista", "Frost", 14,11, 27, 1998 };
    man m3 = { "Ailla", "Real", 10,06, 10, 1988 };

    man* menArray = new man[size];
    menArray[0] = m1;
    menArray[1] = m2;
    menArray[2] = m3;


    //printAllMen(menArray, size);

    //sort(menArray, size);

    //printAllMen(menArray, size);

    //addNewMan(&menArray, size);

    printAllMen(menArray, size);

    deleteMan(&menArray, size, 2);

    printAllMen(menArray, size);

    findMan(menArray, "Cegey", "Grigoriev", size);


}

