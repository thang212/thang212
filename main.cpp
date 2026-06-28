#include "QuizManager.h"
#include <iostream>

using namespace std;

int main() {
    QuizManager quiz;
    
    // Nạp file ngân hàng câu hỏi
    if (!quiz.loadQuestions("questions.txt")) {
        cout << "Error: Cannot open 'questions.txt' or format is incorrect!\n";
        return 1;
    }

    // Bắt đầu chạy chương trình thi
    quiz.startQuiz();

    return 0;
}