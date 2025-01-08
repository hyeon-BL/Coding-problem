#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, int> precedence = { //
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'(', 0}};

string postorder(string expression)
{
    stack<char> s;
    string result = "";
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] >= 'A' && expression[i] <= 'Z')
        { // 피연산자는 바로 출력
            result += expression[i];
        }
        else if (expression[i] == '(')
        { // 여는 괄호는 스택에 push
            s.push(expression[i]);
        }
        else if (expression[i] == ')')
        { // 닫는 괄호는 여는 괄호가 나올 때까지 pop
            while (!s.empty() && s.top() != '(')
            {
                result += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        { // 연산자는 스택의 top과 우선순위를 비교하여 출력
            while (!s.empty() && precedence[s.top()] >= precedence[expression[i]])
            {
                result += s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
    }
    while (!s.empty())
    { // 스택에 남아있는 연산자들을 모두 출력
        result += s.top();
        s.pop();
    }
    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string expression;
    cin >> expression;

    string result = postorder(expression);
    cout << result;
}