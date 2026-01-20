#include "logger.h"

Logger* Logger::instance = nullptr;
bool Logger::open = true;
std::vector< const char* > Logger::logs = {};

Logger &Logger::GetInstance() {
    if (!instance) {
        instance = new Logger();
    }
    return *instance;
}

void Logger::CreateGameLog() {
    ImGui::Begin("Game Log", &open);

    bool options = ImGui::Button("Options"); ImGui::SameLine();
    bool clear = ImGui::Button("Clear"); ImGui::SameLine();
    bool info = ImGui::Button("Test Info"); ImGui::SameLine();
    bool warning = ImGui::Button("Test Warning"); ImGui::SameLine();
    bool error = ImGui::Button("Test Error");

    if (options)
        {
            Logger::logs.push_back("These are the options");
        }
    if (clear)
        {
            Logger::logs.clear();
        }
    if (info) 
        {
            
        }
    if (warning) 
        {
            
        }
    if (error) 
        {
            
        }

    for (int i = 0; i < Logger::logs.size(); i++) {
        ImGui::Text(Logger::logs[i]);
    }
    
    ImGui::End();
}