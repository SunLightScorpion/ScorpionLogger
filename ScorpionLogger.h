#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class ScorpionLog{

public:

    enum LogType{

        INFO [[maybe_unused]],
        ERROR [[maybe_unused]],
        WARNING [[maybe_unused]],

    };

    [[maybe_unused]] static void log(LogType type, const string& msg){
        ofstream out_file;
        out_file.open("pass.txt", std::ofstream::app);

        time_t now = time(nullptr);
        char* td = ctime(&now);

        out_file << rawType(type) << ": "+msg << " | " << td;
    }

private:

    [[maybe_unused]] static string rawType(LogType log){
        if(log == INFO){
            return "INFO";
        }
        if(log == WARNING){
            return "WARNING";
        }
        if(log == ERROR){
            return "ERROR";
        }
        return "";
    }

};
