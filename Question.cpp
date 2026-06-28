#include "Question.h"

Question::Question(int id, string text, int correct)
    :question_id(id), question_text(text), correctAnswer(correct) {}

Question::~Question(){}

int Question::getId() const {return question_id; }
int Question::getcorrectAnswer() const {return correctAnswer; }