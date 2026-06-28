#include "Candidate.h"

Candidate::Candidate() : name(""), candidate_id(0) {}

istream& operator>>(istream& in, Candidate& c) {
    cout << "===== CANDIDATE INFORMATION =====\n";
    cout << "Enter Candidate ID (Number): ";
    in >> c.candidate_id;
    
    in.ignore(); //
    
    cout << "Enter Full Name: ";
    getline(in, c.name);
    return in;
}

ostream& operator<<(ostream& os, const Candidate& c) {
    os << "Candidate ID  : " << c.candidate_id << "\n";
    os << "Candidate Name: " << c.name << "\n";
    return os;
}