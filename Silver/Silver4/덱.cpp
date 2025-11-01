#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Deque
{
private:
    vector<T> front; // 가장 최근에 들어온 원소가 맨 뒤에 위치(front)
    vector<T> back;  // 가장 최근에 들어온 원소가 맨 뒤에 위치(back)

public:
    Deque() {}

    void push_front(const T &value)
    {
        front.push_back(value);
    }

    void push_back(const T &value)
    {
        back.push_back(value);
    }

    void pop_front()
    {
        if (front.empty())
        {
            // 역순 -> back의 마지막 원소가 front의 첫 번째 원소가 되어야 함
            int n = back.size();
            for (int i = n - 1; i >= 0; --i)
                front.push_back(back[i]);
            back.clear();
        }
        if (!front.empty())
            front.pop_back();
    }

    void pop_back()
    {
        if (back.empty())
        {
            // 역순 -> front의 마지막 원소가 back의 첫 번째 원소가 되어야 함
            int n = front.size();
            for (int i = n - 1; i >= 0; --i)
                back.push_back(front[i]);
            front.clear();
        }
        if (!back.empty())
            back.pop_back();
    }

    T &front_element()
    {
        if (front.empty())
        {
            int n = back.size();
            for (int i = n - 1; i >= 0; --i)
                front.push_back(back[i]);
            back.clear();
        }
        return front.back();
    }

    T &back_element()
    {
        if (back.empty())
        {
            int n = front.size();
            for (int i = n - 1; i >= 0; --i)
                back.push_back(front[i]);
            front.clear();
        }
        return back.back();
    }

    bool is_empty() const
    {
        return front.empty() && back.empty();
    }

    size_t size() const
    {
        return front.size() + back.size();
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    Deque<int> dq;
    while (N--)
    {
        string command;
        cin >> command;
        if (command == "push_front")
        {
            int value;
            cin >> value;
            dq.push_front(value);
        }
        else if (command == "push_back")
        {
            int value;
            cin >> value;
            dq.push_back(value);
        }
        else if (command == "pop_front")
        {
            if (dq.is_empty())
                cout << -1 << '\n';
            else
            {
                cout << dq.front_element() << '\n';
                dq.pop_front();
            }
        }
        else if (command == "pop_back")
        {
            if (dq.is_empty())
                cout << -1 << '\n';
            else
            {
                cout << dq.back_element() << '\n';
                dq.pop_back();
            }
        }
        else if (command == "size")
            cout << dq.size() << '\n';
        else if (command == "empty")
            cout << (dq.is_empty() ? 1 : 0) << '\n';
        else if (command == "front")
        {
            if (dq.is_empty())
                cout << -1 << '\n';
            else
                cout << dq.front_element() << '\n';
        }
        else if (command == "back")
        {
            if (dq.is_empty())
                cout << -1 << '\n';
            else
                cout << dq.back_element() << '\n';
        }
    }
}