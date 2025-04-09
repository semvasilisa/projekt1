#include "ArrayList.hpp"
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"

#include <fstream>
#include <vector>
#include <chrono>

void generateRandomData(const std::vector<int>& dataSizes)
{
    std::string folderPath = "../datasets";

    for (int size : dataSizes)
    {
        for (int fileIndex = 0; fileIndex < 10; fileIndex++)
        {
            std::string fileName = folderPath + "/random_data_" + std::to_string(size) + "_" + std::to_string(fileIndex) + ".txt";
            std::ofstream outFile(fileName);
            if (!outFile)
            {
                throw std::runtime_error("Unable to open file: " + fileName);
            }

            srand(size + fileIndex);

            for (int i = 0; i < size; i++)
            {
                int value = rand();
                outFile << value << ";";
            }

            outFile.close();
        }
    }
}

void prepareStructures(const std::vector<int>& dataSizes)
{
    std::string folderPath = "../datasets";
    std::string resultsFile = "../results/efficiency_results.txt";

    std::ofstream resultsOut(resultsFile);
    if (!resultsOut)
        throw std::runtime_error("Unable to open results file: " + resultsFile);

    resultsOut << "Size;Operation;Structure;Time\n";

    for (int size : dataSizes)
    {
        double slPush = 0, slRand = 0, slFront = 0;
        double slPop = 0, slPopBack = 0, slPopRand = 0;

        double dlPush = 0, dlRand = 0, dlFront = 0;
        double dlPop = 0, dlPopBack = 0, dlPopRand = 0;

        double alPush = 0, alRand = 0, alFront = 0;
        double alPop = 0, alPopBack = 0, alPopRand = 0;

        for (int datasetIndex = 0; datasetIndex < 10; ++datasetIndex)
        {
            std::string fileName = folderPath + "/random_data_" + std::to_string(size) + "_" + std::to_string(datasetIndex) + ".txt";
            std::ifstream inFile(fileName);
            if (!inFile)
                throw std::runtime_error("Unable to open file: " + fileName);

            std::string line;
            std::getline(inFile, line);
            inFile.close();

            std::vector<int> data;
            size_t pos = 0;
            while ((pos = line.find(';')) != std::string::npos)
            {
                int value = std::stoi(line.substr(0, pos));
                data.push_back(value);
                line.erase(0, pos + 1);
            }

            auto measure = [](auto& structure, auto operation)
            {
                auto start = std::chrono::high_resolution_clock::now();
                operation(structure);
                auto end = std::chrono::high_resolution_clock::now();
                
                return std::chrono::duration<double, std::micro>(end - start).count();
            };

            for (int i = 0; i < 10; ++i)
            {
                // SinglyLinkedList
                SinglyLinkedList sList;
                for (int val : data) sList.push_back(val);

                slPush += measure(sList, [](auto& l) { l.push_back(rand()); });
                slRand += measure(sList, [](auto& l) { l.insert(rand() % l.getSize(), rand()); });
                slFront += measure(sList, [](auto& l) { l.insert(0, rand()); });

                slPop += measure(sList, [](auto& l) { l.pop_front(); });
                slPopBack += measure(sList, [](auto& l) { l.pop_back(); });
                slPopRand += measure(sList, [](auto& l) { l.remove_at(rand() % l.getSize()); });

                // DoublyLinkedList
                DoublyLinkedList dList;
                for (int val : data) dList.push_back(val);

                dlPush += measure(dList, [](auto& l) { l.push_back(rand()); });
                dlRand += measure(dList, [](auto& l) { l.insert(rand() % l.getSize(), rand()); });
                dlFront += measure(dList, [](auto& l) { l.insert(0, rand()); });

                dlPop += measure(dList, [](auto& l) { l.pop_front(); });
                dlPopBack += measure(dList, [](auto& l) { l.pop_back(); });
                dlPopRand += measure(dList, [](auto& l) { l.remove_at(rand() % l.getSize()); });

                // ArrayList
                ArrayList<int> aList;
                for (int val : data) aList.add(val);

                alPush += measure(aList, [](auto& l) { l.add(rand()); });
                alRand += measure(aList, [](auto& l) { l.add(rand() % l.getSize(), rand()); });
                alFront += measure(aList, [](auto& l) { l.add(0, rand()); });

                alPop += measure(aList, [](auto& l) { l.remove(0); });
                alPopBack += measure(aList, [](auto& l) { l.remove(l.getSize() - 1); });
                alPopRand += measure(aList, [](auto& l) { l.remove(rand() % l.getSize()); });
            }
        }

        // Average time for each operation
        resultsOut << size << ";PushBack;SinglyLinkedList;" << slPush / 100.0 << "\n";
        resultsOut << size << ";InsertRandom;SinglyLinkedList;" << slRand / 100.0 << "\n";
        resultsOut << size << ";InsertFront;SinglyLinkedList;" << slFront / 100.0 << "\n";
        resultsOut << size << ";RemoveFront;SinglyLinkedList;" << slPop / 100.0 << "\n";
        resultsOut << size << ";RemoveBack;SinglyLinkedList;" << slPopBack / 100.0 << "\n";
        resultsOut << size << ";RemoveRandom;SinglyLinkedList;" << slPopRand / 100.0 << "\n";

        resultsOut << size << ";PushBack;DoublyLinkedList;" << dlPush / 100.0 << "\n";
        resultsOut << size << ";InsertRandom;DoublyLinkedList;" << dlRand / 100.0 << "\n";
        resultsOut << size << ";InsertFront;DoublyLinkedList;" << dlFront / 100.0 << "\n";
        resultsOut << size << ";RemoveFront;DoublyLinkedList;" << dlPop / 100.0 << "\n";
        resultsOut << size << ";RemoveBack;DoublyLinkedList;" << dlPopBack / 100.0 << "\n";
        resultsOut << size << ";RemoveRandom;DoublyLinkedList;" << dlPopRand / 100.0 << "\n";

        resultsOut << size << ";PushBack;ArrayList;" << alPush / 100.0 << "\n";
        resultsOut << size << ";InsertRandom;ArrayList;" << alRand / 100.0 << "\n";
        resultsOut << size << ";InsertFront;ArrayList;" << alFront / 100.0 << "\n";
        resultsOut << size << ";RemoveFront;ArrayList;" << alPop / 100.0 << "\n";
        resultsOut << size << ";RemoveBack;ArrayList;" << alPopBack / 100.0 << "\n";
        resultsOut << size << ";RemoveRandom;ArrayList;" << alPopRand / 100.0 << "\n";
    }

    resultsOut.close();
}


int main(int argc, char *argv[])
{
    std::vector<int> dataSizes = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};
    generateRandomData(dataSizes);

    prepareStructures(dataSizes);
}