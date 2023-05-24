#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std;

using namespace std::chrono;


int sum(int a[], int n)
{
    int sum = 0;
#pragma omp parallel reduction(+ : sum)
    for (int i = 0; i < n; i++)
    {
        sum += i;
    }

    return sum;
}

int min(int a[], int n)
{
    int x = a[0];
#pragma omp parallel reduction(min : x)
    for (int i = 0; i < n; i++)
    {
        if (a[i] < x)
        {
            x = a[i];
        }
    }

    return x;
}

int max(int a[], int n)
{
    int x = a[0];
#pragma omp parallel reduction(max : x)
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            x = a[i];
        }
    }

    return x;
}

float avg(int a[], int n)
{

    return (float(sum(a, n)) / n);
}

int main()
{
    int a[1000], n;
    int cnt = 0;
    cout << "ENTER LAST NUMBER: \n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
        cnt = cnt + 1;
    }
    cout << " Input data is :";
    for (int i = 0; i < cnt; i++)
        cout << " " << a[i];
    cout << "\n";

    auto t1  = high_resolution_clock::now();
    cout << "\nSUM OF NUMBERS ARE: " << sum(a, n);
    cout << "\nMINIMUM NUMBER IS: " << min(a, n);
    cout << "\nMAXIMUM NUMBER IS: " << max(a, n);
    cout << "\nAVG OF NUMBERS ARE: " << avg(a, n)<<endl; 
    auto t2  = high_resolution_clock::now();
    auto duration = (t2 - t1) * 1e-6;
        cout << "\nTime taken by function: " << duration.count() << " microseconds\n"
             << endl;
    
    return 0;
}
