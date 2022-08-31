#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <fstream>
#include <string>

using namespace std;



int rand1000()
{
    return rand() % 1000;
}

template<class R, class T, const int nvector, const int kSize>
struct Distancias {
    string name;
    
    Distancias(string n) {
        name = n;
        Motor();
    }

private:

    vector<vector<T>> vectors;
    vector<R> dist;


    R distEucli(vector<T> V, vector<T> W)
    {
        int suma = 0;
        for (int i = 0; i < V.size(); i++)
        {
            suma += pow((V[i] - W[i]), 2);
        }
        return sqrt(suma);
    }

    vector<int> randomVector()
    {
        vector<T> array(kSize);
        generate(array.begin(), array.end(), rand1000);
        sort(array.begin(), array.end(), std::greater<int>());
        return array;
    }

    void printVec(vector<int> V)
    {
        for (vector<int>::iterator it = V.begin();
            it < V.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    void printFrequency(vector<R> vec)
    {
        map <R, R> M;

        for (int i = 0;
            i < nvector - 1
            ; i++)
        {
            if (M.find(vec[i]) == M.end()) {
                M[vec[i]] = 1;
            }
            else {
                M[vec[i]]++;
            }
        }
        std::ofstream myfile;
        myfile.open(name + ".csv");
        myfile << "distancias;repeticiones\n";
        for (auto& it : M)
        {
            myfile << it.first << ";" << it.second << "\n";
        }
        myfile.close();
    }

    void Motor()
    {
        for (int i = 0; i < nvector; i++)
        {
            vectors.push_back(randomVector());
        }


        for (vector<vector<int>>::iterator x = ++vectors.begin(); x < vectors.end(); x++)
        {
            dist.push_back(distEucli(vectors[0], *x));
        }


        printFrequency(dist);
    }
    
};


int main() {

    Distancias<float, int, 10000, 10> A1("10k10");
    Distancias<float, int, 10000, 20> A2("10k20");
    Distancias<float, int, 10000, 30> A3("10k30");
    Distancias<float, int, 10000, 40> A4("10k40");
    Distancias<float, int, 10000, 50> A5("10k50");

    Distancias<float, int, 20000, 10> B1("20k10");
    Distancias<float, int, 20000, 20> B2("20k20");
    Distancias<float, int, 20000, 30> B3("20k30");
    Distancias<float, int, 20000, 40> B4("20k40");
    Distancias<float, int, 20000, 50> B5("20k50");

    Distancias<float, int, 30000, 10> C1("30k10");
    Distancias<float, int, 30000, 20> C2("30k20");
    Distancias<float, int, 30000, 30> C3("30k30");
    Distancias<float, int, 30000, 40> C4("30k40");
    Distancias<float, int, 30000, 50> C5("30k50");

    Distancias<float, int, 40000, 10> D1("40k10");
    Distancias<float, int, 40000, 20> D2("40k20");
    Distancias<float, int, 40000, 30> D3("40k30");
    Distancias<float, int, 40000, 40> D4("40k40");
    Distancias<float, int, 40000, 50> D5("40k50");

    Distancias<float, int, 50000, 10> E1("50k10");
    Distancias<float, int, 50000, 20> E2("50k20");
    Distancias<float, int, 50000, 30> E3("50k30");
    Distancias<float, int, 50000, 40> E4("50k40");
    Distancias<float, int, 50000, 50> E5("50k50");

    return 0;
}