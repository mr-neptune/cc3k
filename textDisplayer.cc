#include "textDisplayer.h"

void TextDisplayer::display() {
    // display the map
    for (int i = 0; i < gsm.getRowNum(); i++) {
        for (int j = 0; j < gsm.getColNum(); j++) {
            if (gsm.getObjectAt(i, j) == nullptr) {
                cout << ' ';
            }
            else {
                cout << gsm.getObjectAt(i, j)->getDisplay();
            }
        }
        cout << endl;
    }

    // display the events
    vector<string> events = gsm.getActionMsg();
    for (auto it = events.begin(); it != events.end(); ++it) {
        cout << *it << endl;
    }
    gsm.clearActionMsg();
}
