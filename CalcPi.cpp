#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include <string>

// using namespace std; 

void runPiCalc(double &result, int numberOfRuns){
    int cirCount = 0;
    double x, y, sqCount = (double)numberOfRuns, radius = 1.0;

    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_real_distribution<double> dis(-radius, radius);

    for (int i = 0; i < numberOfRuns; i++){
        x = dis(gen);
        y = dis(gen);
        if ((x*x + y*y) <= radius*radius){
            cirCount++;
        }
    }
    result = 4.0*(cirCount/sqCount);
}

int main(int argc, char *argv[]){
    if (argc != 3){
        std::cout << "error: incorrect number of arguments\nplease have 2 integer arguments: number of threads and number of runs" << std::endl;
        return 1;
    }
    int numOfThreads = std::stol(argv[1], nullptr, 10), numOfRuns = std::stol(argv[2], nullptr, 10);
    if(numOfThreads == 0 || numOfRuns == 0){
        std::cout << "error: incompatible arguments entered\nplease enter a only numerical arguments or values greater than 0" << std::endl;
    }
    double results[numOfThreads];
    long double piRes = 0.0;
    // runPiCalc(result, 1000);
    // cout << result << endl;
    std::vector<std::thread> tList;

    //init threads
    for (int i = 0; i < numOfThreads; i++){
        tList.push_back(std::thread(runPiCalc, std::ref(results[i]), numOfRuns));
    }
    //sync threads and wait
    for (int i = 0; i < numOfThreads; i++){
        tList[i].join();
    }
    //get result
    for (int i = 0; i < numOfThreads; i++){
        piRes += results[i];
    }
    piRes = piRes/(long double)numOfThreads;
    std::cout << piRes << std::endl;
    // double result;
    // std::thread first(runPiCalc, std::ref(result));
    // first.join();
    // std::cout << result << std::endl;
    return 0;
}