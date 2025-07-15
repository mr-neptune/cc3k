#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "displayer.h"
using namespace std;

class Subject {
    vector<Displayer*> displayers;

    public:
        void attach(Displayer *d);
        void detach(Displayer *d);
        void callAllDisplayers() const;
        virtual ~Subject() = 0;
};

#endif
