#include <iostream>
#include <sstream>
#include <journalpp/journalpp.h>

int main() {
    journalpp::journal j;

    // FIXME: For some godforsaken reason, checking for equality doesn't work.
    // So this has to be actually written to a file and checked manually in
    // order to verify that it works. If someone has a better solution, though,
    // please do not hesitate to notify me.
    //
    // - Dr. Bluefall.

    std::ostringstream out;
    j.marshal_field(out, "MESSAGE", "foo\nbar");

    std::cout << out.str();

    j.wrapup();
}
