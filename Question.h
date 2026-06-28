#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Question{
    protected:
        int question_id;
        string question_text;
        int correctAnswer;
    public:
        Question(int id = 0, string text = "", int correct = 0);
        virtual ~Question();
        virtual void display(int currentChoice) const = 0;
        virtual void load(ifstream& in) = 0;

        int getId() const;
        int getcorrectAnswer() const;
};