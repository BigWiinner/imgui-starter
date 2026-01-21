#include "imgui/imgui.h"
#include <vector>
#include <string>
#include <variant>
#pragma once

struct message {
    public:
        const char* msg;
        int intensity;
};

class Logger {
        public:
            static Logger& GetInstance();
            void CreateGameLog();
            void LogInfo(const char*);
            void LogWarning(const char*);
            void LogError(const char*);
            void LogGameEvent(const char*, int = 0);
            void LogToFile();
            void Start();
        private:
            static Logger* instance;
            static bool open;
            static std::vector<message> logs;
            static int debugIndex;

};
