#include <iostream>
#include <journalpp/journalpp.h>
#include <unistd.h>

int main() {
    journalpp::journal j;
    j.write_to_socket("MESSAGE=message sent from journalpp test 'test/sanity'\n");
    j.wrapup();
    std::cout << getpid() << std::endl;
}
