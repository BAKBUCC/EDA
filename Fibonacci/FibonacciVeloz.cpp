#include <iostream>
#include <vector>

using namespace std;

struct matrix {

    unsigned int dimx, dimy;

    vector<vector<long long>> v;
    matrix(unsigned int x, unsigned int y)
        :dimx(x), dimy(y)
    {
        vector<long long> vec(dimy);
        for (unsigned int i = 0; i < dimx; i++)
        {
            v.push_back(vec);
        }
    }

    void put(int x, int y, long long num)
    {
        v[x][y] = num;
    }

    long long get(int x, int y)
    {
        return v[x][y];
    }

    void printMatrix()
    {
        for (unsigned int f = 0; f < dimx; f++)
        {
            for (unsigned int c = 0; c < dimy; c++)
            {
                cout << v[f][c] << " ";
            }
            cout << endl;
        }
        cout << "\n\n" << endl;
    }

    void igualar(matrix& m, matrix n)
    {
        if (m.dimx != n.dimx || m.dimy != n.dimy) return;

        for (int i = 0; i < m.dimx; i++)
        {
            for (int j = 0; j < m.dimy; j++)
            {
                m.put(i, j, n.get(i, j));
            }
        }
    }

    matrix sumarMatrix(matrix& m)
    {
        matrix sum(dimx, dimy);
        if (dimx != m.dimx || dimy != m.dimy) return sum;

        for (int i = 0; i < dimx; i++)
        {
            for (int j = 0; j < dimy; j++)
            {
                sum.put(i, j, v[i][j] + m.get(i, j));
            }
        }
        return sum;
    }

    matrix multiMatrix(matrix& m)
    {
        matrix multi(dimx, m.dimy);
        if (dimy != m.dimx) return multi;

        for (int i = 0; i < dimx; i++)
        {
            for (int j = 0; j < m.dimy; j++)
            {
                long long sum = 0;
                for (int k = 0; k < m.dimx; k++)
                {
                    sum += (v[i][k] * m.get(k, j));
                }
                multi.put(i, j, sum);
            }
        }
        return multi;
    }

    matrix powerMatrix(matrix& m, int n)
    {
        matrix temp(m.dimx, m.dimy);
        if (n == 0)
        {
            for (unsigned int f = 0; f < dimx; f++)
            {
                for (unsigned int c = 0; c < dimy; c++)
                {
                    temp.put(f, c, 0);
                    if (f == c)
                    {
                        temp.put(f, c, 1);
                    }
                }
            }
            return temp;
        }

        m.igualar(temp, m.powerMatrix(m, n / 2));

        if (n % 2 == 0)
        {
            m.igualar(temp, temp.multiMatrix(temp));
            return temp;
        }
        else 
        {
            m.igualar(temp, temp.multiMatrix(temp));
            m.igualar(temp, m.multiMatrix(temp));

            return  temp;
        }        
    }

};

long long fiboExp(int n)
{
    if (n == 1)
        return 1;
    else if (n == 0)
        return 1;

    return fiboExp(n - 1) + fiboExp(n - 2);
}

long long fiboLineal(int n)
{
    long long a = 0, b = 1, c;
    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

long long fiboLogaritmico(int n)
{
    matrix m(2, 2); 
    m.put(0, 0, 0); m.put(0, 1, 1);
    m.put(1, 0, 1); m.put(1, 1, 1);

    matrix p(2, 1);
    p.put(0, 0, 0);
    p.put(1, 0, 1);

    matrix power(2, 2);
    p.igualar(power, p.powerMatrix(m, n));


    matrix multi(2, 1);
    m.igualar(multi, power.multiMatrix(p));

    return multi.get(1,0);
}



int main() {
    
    int num;
    cout << "ingrese n: ";
    cin >> num;
    cout << "\nO logaritmico: " << fiboLogaritmico(num) << endl;
    cout << "O Lineal:      " << fiboLineal(num) << endl;
    cout << "O Exponencial: " << fiboExp(num) << endl;
    return 0;
}