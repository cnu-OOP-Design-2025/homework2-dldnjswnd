#include "homework2-1.h"
#include <stdexcept>
/* TODO IntClac 네임스페이스 및 함수 정의하기 */
namespace IntCalc
{
    int add(int a, int b) { return a + b; };

    int subtract(int a, int b) { return a - b; };

    int multiply(int a, int b) { return a * b; };

    int divide(int a, int b)
    {
        if (b == 0)
        {
            throw std::runtime_error("Divide by zero error");
        }
        return a / b;
    };
}
/* TODO FloatClac 네임스페이스 및 함수 정의하기 */

namespace FloatCalc
{
    float add(float a, float b) { return a + b; };
    float subtract(float a, float b) { return a - b; };
    float multiply(float a, float b) { return a * b; };
    float divide(float a, float b)
    {
        if (b == 0)
        {
            throw std::runtime_error("Divide by zero error");
        }
        return a / b;
    };

}
