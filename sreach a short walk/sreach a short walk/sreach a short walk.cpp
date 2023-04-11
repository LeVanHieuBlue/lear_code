// sreach a short walk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class graph
{
    int edges;
    int vertices;
public:
    graph(int e ,int v)
    {
        this->edges = e;
        this->vertices = v;
    }
    graph()
    {
        this->edges = 0;
        this->vertices = 0;
    }
    void create_graph();
    void create_graph(int e, int v);
  
};
void graph::create_graph()
{
    cout << "a";
}
void graph::create_graph(int e, int v)
{
    cout << "e";
}
void copy(int a, int* b)
{
   
}
int main()
{
    int a = 1;
    int c = 2;
    int* b = &a;
    cout << *b;
   
}

