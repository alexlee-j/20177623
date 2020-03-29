#include<iostream> 
using namespace std;
int sudoku[9][9];//��������
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
            sudoku[i][j] = temp[i][j] - '0';//��þ�����и��е�ֵ
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
        int j = n / 9;//������
        if (sudoku[j][i] == jie)
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        int j = n % 9;//������
        if (sudoku[i][j] == jie)
            return false;
    }
    int x = n / 9 / 3 * 3;//����С�Ź����󶥵�������
    int y = n % 9 / 3 * 3;//���ڵ�С�Ź����󶥵������
    /* �ж�n���ڵ�С�Ź����Ƿ�Ϸ� */
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
    if (sudoku[n / 9][n % 9] != 0)//��Ϊ0ʱ
    {
        DFS(n + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)//����ö��
        {
            if (jiancha(n, i) == true) {
                sudoku[n / 9][n % 9] = i;
                DFS(n + 1);
                if (wancheng == true) //�����ɹ�
                    return 0;
                sudoku[n / 9][n % 9] = 0;//����ʧ�ܣ���ԭ�ֳ� 
            }
        }
    }
}
int main()
{
    cout << "������һ��9*9������:" << endl;
    input();
    DFS(0);
    output();
}