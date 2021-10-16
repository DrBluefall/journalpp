// -*- cpp -*-

#ifndef JOURNALPP_H_
#define JOURNALPP_H_
#include <ostream>
#include <sstream>
#include <sys/socket.h>
#include <sys/un.h>
#include <string>
/*
 * Copyright (C) 2021 Alexander Bisono.
 *
 * This file is part of libjournalpp.
 *
 * libjournalpp is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * libjournalpp is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with libjournalpp. If not, see <https://www.gnu.org/licenses/>.
 * */

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
