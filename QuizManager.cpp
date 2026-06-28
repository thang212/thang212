#include "QuizManager.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std;

QuizManager::~QuizManager() {
    // Thu hồi bộ nhớ động đã cấp phát bằng lệnh new ở hàm load
    for (auto q : questions) {
        delete q;
    }
}

string QuizManager::getCurrentTimeStr() {
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << put_time(localtime(&time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

bool QuizManager::loadQuestions(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    string type;
    while (file >> type) {
        Question* q = nullptr;
        if (type == "MC") {
            q = new MultipleChoiceQuestion();
        }

        if (q != nullptr) {
            q->load(file); // Đa hình nạp file
            questions.push_back(q);
            candidateAnswers.push_back(-1); // Ban đầu chưa câu nào được trả lời
        }
    }
    file.close();
    return !questions.empty();
}

void QuizManager::startQuiz() {
    if (questions.empty()) {
        cout << "No questions available!\n";
        return;
    }

    // Áp dụng Chương 6: Nhập thông tin Candidate bằng toán tử >>
    cin >> candidate; 
    
    startTime = chrono::system_clock::now();
    startTimeStr = getCurrentTimeStr();

    int index = 0;
    bool finishing = false;

    while (!finishing) {
        system("clear || cls"); // Xóa màn hình cho sạch giao diện
        cout << "=========================================\n";
        cout << "QUIZ APP - Total Questions: " << questions.size() << "\n";
        cout << "Exam Start Time: " << startTimeStr << "\n";
        cout << "=========================================\n";

        // ✨ KÍCH HOẠT ĐA HÌNH TẠI ĐÂY
        // Tự động nhận diện display() của trắc nghiệm hay đúng sai
        questions[index]->display(candidateAnswers[index]);

        cout << "\n[A/B/C/D] Answer | [N] Next | [P] Previous | [S] Skip | [F] Finish\n";
        cout << "Your choice: ";
        string choice;
        cin >> choice;
        cin.ignore();

        if (choice.empty()) continue;
        char cmd = toupper(choice[0]);

        // Nhập/Sửa đáp án bất cứ lúc nào
        if (cmd >= 'A' && cmd <= 'D') {
            candidateAnswers[index] = cmd - 'A';
            if (index < (int)questions.size() - 1) index++; // Tự chuyển câu tiếp theo
        } 
        // Điều hướng câu hỏi (Next / Previous / Skip)
        else if (cmd == 'N' && index < (int)questions.size() - 1) {
            index++;
        } else if (cmd == 'P' && index > 0) {
            index--;
        } else if (cmd == 'S' && index < (int)questions.size() - 1) {
            index++; // Bản chất lệnh Skip là nhảy index sang câu tiếp theo mà giữ nguyên answer = -1
        } else if (cmd == 'F') {
            cout << "Are you sure you want to finish the exam? (Y/N): ";
            char confirm;
            cin >> confirm;
            if (toupper(confirm) == 'Y') finishing = true;
        }
    }
    displayResults();
}

void QuizManager::displayResults() {
    auto endTime = chrono::system_clock::now();
    chrono::duration<double> elapsed = endTime - startTime;

    int correct = 0;
    for (size_t i = 0; i < questions.size(); ++i) {
        if (candidateAnswers[i] == questions[i]->getcorrectAnswer()) correct++;
    }

    system("clear || cls");
    cout << "\n=========================================\n";
    cout << "               EXAM RESULT               \n";
    cout << "=========================================\n";
    
    // Áp dụng Chương 6: Xuất thông tin Candidate bằng toán tử <<
    cout << candidate; 
    
    cout << "-----------------------------------------\n";
    cout << "Exam Start Time : " << startTimeStr << "\n";
    cout << "Total Duration  : " << fixed << setprecision(1) << elapsed.count() << " seconds\n";
    cout << "Correct Answers : " << correct << " / " << questions.size() << "\n";
    cout << "Total Score     : " << fixed << setprecision(2) << ((double)correct / questions.size()) * 10.0 << " / 10.0\n";
    cout << "=========================================\n";
}