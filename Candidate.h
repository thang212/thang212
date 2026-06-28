#pragma once
#include <iostream>
#include <string>

using namespace std;

class Candidate{
    private:
    string name;
    int candidate_id;
    public:
    Candidate();

    friend istream& operator>>(istream& in, Candidate& c);
    friend ostream& operator<<(ostream& out, const Candidate& c);
};