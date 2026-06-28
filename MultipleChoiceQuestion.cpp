#include "MultipleChoiceQuestion.h"

MultipleChoiceQuestion::MultipleChoiceQuestion() : Question() {}

void MultipleChoiceQuestion::load(ifstream& in) {
    in >> question_id;
    in.ignore();
    getline(in, question_text);
    options.resize(4);
    for (int i = 0; i < 4; ++i) {
        getline(in, options[i]);
    }
    in >> correctAnswer;
    in.ignore();
}

void MultipleChoiceQuestion::display(int currentChoice) const {
    cout << "\n[MULTIPLE CHOICE] Question " << question_id << ": " << question_text << "\n";
    for (size_t i = 0; i < options.size(); ++i) {
        cout << "  " << (char)('A' + i) << ". " << options[i] << "\n";
    }
    cout << "-----------------------------------------\n";
    if (currentChoice != -1) cout << "-> Current Answer: " << (char)('A' + currentChoice) << "\n";
    else cout << "-> Current Answer: [Skipped]\n";
}