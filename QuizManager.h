#pragma once
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "Question.h"
#include "MultipleChoiceQuestion.h"
#include "Candidate.h"

using namespace std;

class QuizManager {
private:
    vector<Question*> questions;    // Mảng con trỏ lớp cha (Đa hình)
    vector<int> candidateAnswers;   // Lưu đáp án thí sinh chọn (-1: bỏ qua)
    Candidate candidate;            // Đối tượng thí sinh
    
    chrono::system_clock::time_point startTime;
    string startTimeStr;

    string getCurrentTimeStr();
    void displayResults();

public:
    QuizManager() = default;
    ~QuizManager(); 
    bool loadQuestions(const string& filename);
    void startQuiz();
};