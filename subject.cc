#include "subject.h"

void Subject::attach(Displayer *d) {
    displayers.emplace_back(d);
}

void Subject::detach(Displayer *d) {
    for (auto it = displayers.begin(); it != displayers.end(); ++it) {
        if (*it == d) {
            displayers.erase(it);
            break;
        }
    }
}

void Subject::callAllDisplayers() const {
    for (auto it = displayers.begin(); it != displayers.end(); ++it) {
       (*it)->display();
    }
}

Subject::~Subject() {}
