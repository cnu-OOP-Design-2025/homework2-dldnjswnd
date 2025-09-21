#include <iostream>
#include <cstdlib> // atoi
#include "homework2-1.h"
#include "homework2-2.h"
using namespace std;

StudentStruct *students = nullptr;
int numOfStudent = 0;

void printBestStudent()
{
    int bestMidtermId = findBestStudentInMidterm(students, numOfStudent);
    int bestFinalId = findBestStudentInFinal(students, numOfStudent);
    int bestTotalId = findBestStudent(students, numOfStudent);

    cout << "Best Midterm Student:\n";
    printStudentInfo(students, numOfStudent, bestMidtermId);

    cout << "Best Final Student:\n";
    printStudentInfo(students, numOfStudent, bestFinalId);

    cout << "Best Total Score Student:\n";
    printStudentInfo(students, numOfStudent, bestTotalId);
}
void printAverage()
{
    float midtermAvg = getMidtermAverage(students, numOfStudent);
    float finalAvg = getFinalAverage(students, numOfStudent);
    float totalAvg = getTotalAverage(students, numOfStudent);

    cout << "# of Student: " << numOfStudent << endl;
    cout << "Midterm Average: " << midtermAvg << endl;
    cout << "Midterm Average: " << finalAvg << endl;
    cout << "Midterm Average: " << totalAvg << endl;
}

void printStudentList()
{
    for (int id = 1000; id < 1100; ++id)
    {
        printStudentInfo(students, numOfStudent, id);
    }
}

void doNamespaceTest()
{
    cout << "---------------------------" << endl;
    cout << "Namespace Test" << endl;

    // 정수형 계산기 테스트
    cout << "[IntCalc] 10 + 3 = " << IntCalc::add(10, 3) << endl;
    cout << "[IntCalc] 10 - 3 = " << IntCalc::subtract(10, 3) << endl;
    cout << "[IntCalc] 10 * 3 = " << IntCalc::multiply(10, 3) << endl;
    cout << "[IntCalc] 10 / 3 = " << IntCalc::divide(10, 3) << endl;

    cout << "[IntCalc] 10.5 + 3.2 = " << IntCalc::add(10.5, 3.2) << endl;
    cout << "[IntCalc] 10.5 - 3.2 = " << IntCalc::subtract(10.5, 3.2) << endl;
    cout << "[IntCalc] 10.5 * 3.2 = " << IntCalc::multiply(10.5, 3.2) << endl;
    cout << "[IntCalc] 10.5 / 3.2 = " << IntCalc::divide(10.5, 3.2) << endl;

    // 실수형 계산기 테스트
    cout << "[FloatCalc] 10 + 3 = " << FloatCalc::add(10.0f, 3.0f) << endl;
    cout << "[FloatCalc] 10 - 3 = " << FloatCalc::subtract(10.0f, 3.0f) << endl;
    cout << "[FloatCalc] 10 * 3 = " << FloatCalc::multiply(10.0f, 3.0f) << endl;
    cout << "[FloatCalc] 10 / 3 = " << FloatCalc::divide(10.0f, 3.0f) << endl;

    cout << "[FloatCalc] 10.5 + 3.2 = " << FloatCalc::add(10.5f, 3.2f) << endl;
    cout << "[FloatCalc] 10.5 - 3.2 = " << FloatCalc::subtract(10.5f, 3.2f) << endl;
    cout << "[FloatCalc] 10.5 * 3.2 = " << FloatCalc::multiply(10.5f, 3.2f) << endl;
    cout << "[FloatCalc] 10.5 / 3.2 = " << FloatCalc::divide(10.5f, 3.2f) << endl;
}
void doTest1()
{
    cout << "---------------------------" << endl;
    cout << "Test 1" << endl;

    printBestStudent();
    printAverage();
    printStudentList();
}
void doTest2()
{
    cout << "---------------------------" << endl;
    cout << "Test 2" << endl;

    StudentStruct charlie("Charlie", 1003, 70, 99.0);

    int idx = findStudentByStudentID(students, numOfStudent, charlie.id);
    if (idx >= 0)
        modifyRecord(students, numOfStudent, charlie);

    addStudent(students, &numOfStudent, "Ana", 1051, 88, 65);
    addStudent(students, &numOfStudent, "Suji", 1052, 90, 93);
    addStudent(students, &numOfStudent, "Zhang", 1053, 100, 40);

    printBestStudent();
    printAverage();
    printStudentList();
}
void doTest3()
{
    std::cout << "---------------------------" << std::endl;
    std::cout << "Test 3" << std::endl;

    deleteStudent(students, &numOfStudent, 1011);
    deleteStudent(students, &numOfStudent, 1029);

    printStudentList();
}

void doPointerTest(int select)
{
    const int MAX_STUDENTS = 100;
    // StudentStruct[MAX_STUDENTS] 메모리 동적 할당
    students = new StudentStruct[MAX_STUDENTS];
    numOfStudent = 0;
    fillStudentRecord(students, &numOfStudent);

    if (students == nullptr)
        return;

    switch (select)
    {
    case 2:
        doTest1();
        break;
    case 3:
        doTest2();
        break;
    case 4:
        doTest3();
        break;
    default:
        doTest1();
        doTest2();
        doTest3();
        break;
    }
    delete[] students;
    students = nullptr;
}
int main(int argc, char **argv)
{

    if (argc == 2)
    {
        int select = atoi(argv[1]);
        switch (select)
        {
        case 1:
            doNamespaceTest();
            return 0;
        case 2:
        case 3:
        case 4:
            doPointerTest(select);
            return 0;
        }
    }
    doNamespaceTest();
    doPointerTest(0);

    return 0;
}
