#include "imgui/imgui.h"
#include <vector>
#include <string>
#pragma once

class Logger {
        public:
            static Logger& GetInstance();
            void CreateGameLog();
        private:
            static Logger* instance;
            static bool open;
            static std::vector<const char*> logs;

};
