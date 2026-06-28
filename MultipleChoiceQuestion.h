#pragma once
#include "Question.h"

class MultipleChoiceQuestion : public Question {
private:
    vector<string> options;
public:
    MultipleChoiceQuestion();
    void load(ifstream& in) override;
    void display(int currentChoice) const override;
};

