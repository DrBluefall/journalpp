#include <sstream>
#include <journalpp/journalpp.h>

int main() {
    journalpp::journal j;

    std::ostringstream out;
    j.write_to_socket("MESSAGE=mslbegin\n");
    j.marshal_field(out, "MESSAGE", "foo\nbar");
    j.write_to_socket(out.str());
    j.write_to_socket("MESSAGE=mslend\n");
    j.wrapup();
}
