#include<iostream> 
using namespace std;
int sudoku[9][9];//数独矩阵
bool wancheng = false;
void input();
void output();
bool jiancha(int n, int jie);
int DFS(int n);

void input()
{
    char temp[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> temp[i][j];
            sudoku[i][j] = temp[i][j] - '0';//获得矩阵各行各列的值
        }
    }
}

void output()
{
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

bool jiancha(int n, int jie)
{
    for (int i = 0; i < 9; i++)
    {
        int j = n / 9;//竖坐标
        if (sudoku[j][i] == jie)
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        int j = n % 9;//横坐标
        if (sudoku[i][j] == jie)
            return false;
    }
    int x = n / 9 / 3 * 3;//所在小九宫格左顶点竖坐标
    int y = n % 9 / 3 * 3;//所在的小九宫格左顶点横坐标
    /* 判断n所在的小九宫格是否合法 */
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (sudoku[i][j] == jie)
                return false;
        }
    }
    return true;
}

int DFS(int n)
{
    if (n > 80)
    {
        wancheng = true;
        return 0;
    }
    if (sudoku[n / 9][n % 9] != 0)//不为0时
    {
        DFS(n + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)//进行枚举
        {
            if (jiancha(n, i) == true) {
                sudoku[n / 9][n % 9] = i;
                DFS(n + 1);
                if (wancheng == true) //构建成功
                    return 0;
                sudoku[n / 9][n % 9] = 0;//构建失败，还原现场 
            }
        }
    }
}
int main()
{
    cout << "请输入一个9*9的数独:" << endl;
    input();
    DFS(0);
    output();
}