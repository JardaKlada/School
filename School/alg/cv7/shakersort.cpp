#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

vector<int> generateRandomVector(int len, int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(min, max);

    vector<int> result;
    result.reserve(len);

    for (int i = 0; i < len; i++)
    {
        result.push_back(distribution(gen));
    }
    return result;
}

vector<int> ShakerSort(vector<int> randvector)
{
    vector<int> tmp = randvector;
    bool swapped = 0;
    for(int k = 0; k < tmp.size() / 2; k++)
    {    
        swapped = 0;
        for(int i = k; i < tmp.size() - k - 1; i++)
        {
            if(tmp[i] < tmp[i + 1])
            {
                swap(tmp[i], tmp[i + 1]);
                swapped = 1;
            }
        }

        for(int i = tmp.size() - 2 - k; i > 0; i--)
        {
            if(tmp[i] > tmp[i - 1])
            {
                swap(tmp[i], tmp[i - 1]);
                swapped = 1;
            }   
        }
        if(!swapped)
        {
            break;
        }
    }

    return tmp;
}

vector<int> bubblesort(vector<int> arr){
    vector<int> temp = arr;
    for (size_t i = 0; i < temp.size(); i++)
    {
        for (size_t j = 0; j < temp.size()-(i+1); j++)
        {
            if (temp[j] > temp[j + 1])
            {
                std::swap(temp[j], temp[j + 1]);
            }
        }
    }
    return temp;
}

vector<int> selectionsort(vector<int> arr){
    size_t min;
    vector<int> temp = arr;
    for (size_t i = 0; i < temp.size()-1; i++)
    {
        min = i;
        for (size_t l = i; l < temp.size(); l++)
        {
            if (temp[min] > temp[l])
            {
                min = l;
            }
        }
        std::swap(temp[i], temp[min]);
    }
    return temp;
}

int main()
{
    cout<<fixed;

    vector<int> intArr = generateRandomVector(100, 0, 1000);

    auto start = chrono::high_resolution_clock::now();
    ShakerSort(intArr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Time taken to shaker sort the vector: " << duration.count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    bubblesort(intArr);
    end = chrono::high_resolution_clock::now();
    cout << "Time taken to bubble sort the vector: " << duration.count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    vector<int> vectorResult = selectionsort(intArr);
    end = chrono::high_resolution_clock::now();
    cout << "Time taken to selection sort the vector: " << duration.count() << " seconds" << endl;

    for(int i = 0; i < vectorResult.size(); i++)
    {
        cout << vectorResult[i] << " ";
    }
    cout << endl;

    return 0; 
}