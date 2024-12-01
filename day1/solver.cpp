#include <fstream>
#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <unordered_set>

std::vector< std::vector<int> > getVectors()
{
    std::ifstream input("input.txt");

    std::vector<int> vec1;
    std::vector<int> vec2;

    std::string line;
    while(getline(input, line))
    {
        int vec1val = std::stoi(line.substr(0, 5));
        int vec2val = std::stoi(line.substr(8, 5));

        vec1.push_back(vec1val);
        vec2.push_back(vec2val);
    }

    return {vec1, vec2};
}

std::vector< std::unordered_multiset<int> > getMultisets()
{
    std::ifstream input("input.txt");

    std::unordered_multiset<int> mset1;
    std::unordered_multiset<int> mset2;

    std::string line;
    while(getline(input, line))
    {
        int mset1val = std::stoi(line.substr(0, 5));
        int mset2val = std::stoi(line.substr(8, 5));

        mset1.insert(mset1val);
        mset2.insert(mset2val);
    }

    return {mset1, mset2};
}

int getSimilarityScore(std::vector< std::unordered_multiset<int> > vec)
{
    int similarityScore = 0;
    for(int value : vec[0])
    {
        int currElementScore = 0;
        for(int value_ : vec[1])
        {
            if(value == value_)
            {
                currElementScore += value_;
            }
        }
    similarityScore += currElementScore;
    }
    return similarityScore;
}

int findDistance(std::vector< std::vector<int> > vecsVector)
{
    std::vector<int> vec1 = vecsVector[0];
    std::vector<int> vec2 = vecsVector[1];

    auto it1 = vec1.begin();
    auto it2 = vec2.begin();

    int distance = 0;
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    while(it1 != vec1.end() && it2 != vec2.end())
    {
        int diff = abs(*it1 - *it2);
        it1++;
        it2++;

        distance += diff;
    }
    return distance;
}

int main()
{
    std::vector< std::vector<int> > vecsVec = getVectors();
    int distance = findDistance(vecsVec);

    std::vector< std::unordered_multiset<int> > msetsVec = getMultisets();
    int similarityScore = getSimilarityScore(msetsVec);

    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Similarity Score: " << similarityScore << std::endl;
}