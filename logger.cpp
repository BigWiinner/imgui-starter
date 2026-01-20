#include "logger.h"

Logger* Logger::instance = nullptr;
bool Logger::open = true;
std::vector<message> Logger::logs = {};

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
            
        }
    if (clear)
        {
            Logger::logs.clear();
        }
    if (info) 
        {
            message txt = {"This is a test info message", 0};
            Logger::logs.push_back(txt);
        }
    if (warning) 
        {
            message txt = {"This is a test warning message", 1};
            Logger::logs.push_back(txt);
        }
    if (error) 
        {
            message txt = {"This is a test error message", 2};
            Logger::logs.push_back(txt);
        }

    for (int i = 0; i < Logger::logs.size(); i++) {
        if (Logger::logs[i].intensity == 1) {
            ImGui::TextColored(ImVec4(1.0, 1.0, 0.0, 1.0), "[WARN]"); ImGui::SameLine();
            ImGui::TextColored(ImVec4(1.0, 1.0, 0.0, 1.0), Logger::logs[i].msg);
        }
        else if (Logger::logs[i].intensity == 2) {
            ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), "[ERROR]"); ImGui::SameLine();
            ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), Logger::logs[i].msg);
        }
        else if (Logger::logs[i].intensity == 3) {
            ImGui::Text("[INFO] [GAME]"); ImGui::SameLine();
            ImGui::Text(Logger::logs[i].msg);
        }
        else if (Logger::logs[i].intensity == 4) {
            ImGui::TextColored(ImVec4(1.0, 1.0, 0.0, 1.0), "[WARN] [GAME]"); ImGui::SameLine();
            ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), Logger::logs[i].msg);
        }
        else if (Logger::logs[i].intensity == 5) {
            ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), "[ERROR] [GAME]"); ImGui::SameLine();
            ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), Logger::logs[i].msg);
        }
        else {
            ImGui::Text("[INFO]"); ImGui::SameLine();
            ImGui::Text(Logger::logs[i].msg);
        }
    }
    
    ImGui::End();
}

void Logger::LogInfo(const char* info) {
    message log = {info, 0};
    Logger::logs.push_back(log);
}

void Logger::LogGameEvent(const char* event, int intensity) {
    intensity += 3;
    message log = {event, intensity};
    Logger::logs.push_back(log);
}