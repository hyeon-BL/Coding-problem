#include <iostream>
#include <algorithm>
using namespace std;

string green_name;

struct Team
{
    int L_cnt;
    int O_cnt;
    int V_cnt;
    int E_cnt;

    Team() : L_cnt(0), O_cnt(0), V_cnt(0), E_cnt(0) {}
    Team(int L, int O, int V, int E) : L_cnt(L), O_cnt(O), V_cnt(V), E_cnt(E) {}

    int probability()
    {
        return ((L_cnt + O_cnt) * (L_cnt + V_cnt) * (L_cnt + E_cnt) * (O_cnt + V_cnt) * (O_cnt + E_cnt) * (V_cnt + E_cnt)) % 100;
    };
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int team_cnt, green_L = 0, green_O = 0, green_V = 0, green_E = 0;
    cin >> green_name >> team_cnt;

    for (int i = 0; i < green_name.size(); i++)
    {
        if (green_name[i] == 'L')
        {
            green_L++;
        }
        else if (green_name[i] == 'O')
        {
            green_O++;
        }
        else if (green_name[i] == 'V')
        {
            green_V++;
        }
        else if (green_name[i] == 'E')
        {
            green_E++;
        }
    }

    string *team_names = new string[team_cnt];

    for (int i = 0; i < team_cnt; i++)
    {
        cin >> team_names[i];
    }
    sort(team_names, team_names + team_cnt);

    Team *teams = new Team[team_cnt];
    for (int i = 0; i < team_cnt; i++)
    {
        teams[i] = Team(green_L, green_O, green_V, green_E);
    }
    for (int i = 0; i < team_cnt; i++)
    {
        for (int j = 0; j < team_names[i].size(); j++)
        {
            if (team_names[i][j] == 'L')
            {
                teams[i].L_cnt++;
            }
            else if (team_names[i][j] == 'O')
            {
                teams[i].O_cnt++;
            }
            else if (team_names[i][j] == 'V')
            {
                teams[i].V_cnt++;
            }
            else if (team_names[i][j] == 'E')
            {
                teams[i].E_cnt++;
            }
        }
    }

    int max_probability = 0;
    int max_index = 0;
    for (int i = 0; i < team_cnt; i++)
    {
        if (teams[i].probability() > max_probability)
        {
            max_probability = teams[i].probability();
            max_index = i;
        }
    }
    cout << team_names[max_index];
}