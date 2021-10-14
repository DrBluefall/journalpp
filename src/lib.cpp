#include <algorithm>
#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <journalpp/journalpp.h>
#include <ostream>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int journalpp::foo() {
    return 1;
}

journalpp::journal::journal() {
    mjournal_fd = socket(AF_UNIX, SOCK_DGRAM, 0);

    if (mjournal_fd == -1) {
        throw std::runtime_error(std::strerror(errno));
    }
}

void journalpp::journal::write_to_socket(std::string msg) {

    if (sendto(mjournal_fd,
            msg.c_str(),
            msg.size(),
            MSG_NOSIGNAL,
            (const struct sockaddr*)&msa,
            sizeof(msa))
        == -1) {
        throw std::runtime_error(std::strerror(errno));
    }
}

void journalpp::journal::marshal_field(std::ostringstream& input, std::string name, std::string value) {
    input << name;

    if (std::find(value.begin(), value.end(), '\n') != value.end()) {
        input << "\n";

        std::uint64_t size;
        unsigned char i;
        for (size = static_cast<std::uint64_t>(value.length()), i=0; i < 8 ; size >>= 8, ++i) {
            input.put(size & 0xFF);
        }

        input << value << '\n';

    } else {
        // No newline, just write this to the stream.
        input << name << '=' << value << '\n';
    }
}

void journalpp::journal::wrapup() {
    if (close(mjournal_fd) == -1) {
        throw std::runtime_error(std::strerror(errno));
    }
}
