// -*- cpp -*-

#ifndef JOURNALPP_H_
#define JOURNALPP_H_
#include <ostream>
#include <sstream>
#include <sys/socket.h>
#include <sys/un.h>
#include <string>

namespace journalpp {
    int foo();

    class journal {

        int mjournal_fd;
        const sockaddr_un msa = {
            AF_UNIX, // sun_family
            "/run/systemd/journal/socket", // sun_path
        };

      public:
        journal();
        journal(const journal&) = delete;
        journal(const journal&&) = delete;

        void wrapup();
        void write_to_socket(std::string msg);
        void marshal_field(std::ostringstream& input, std::string name, std::string value);
    };
};

#endif // JOURNALPP_H_
