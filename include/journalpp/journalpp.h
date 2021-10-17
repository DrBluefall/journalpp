// -*- cpp -*-
#ifndef JOURNALPP_H_
#define JOURNALPP_H_
#include <ostream>
#include <sys/socket.h>
#include <sys/syslog.h>
#include <sys/un.h>
#include <string>
#include <map>
#include <syslog.h>
#include <variant>
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

    enum class Priority {
        Emergency = LOG_EMERG,
        Alert     = LOG_ALERT,
        Critical  = LOG_CRIT,
        Error     = LOG_ERR,
        Warning   = LOG_WARNING,
        Notice    = LOG_NOTICE,
        Info      = LOG_INFO,
        Debug     = LOG_DEBUG,
    };

    // NOTE: for some godforsaken reason, journald doesn't recognize the syslog
    // facility values as they're defined in 'sys/syslog.h'. Probably because
    // the values are bitshifted under the hood. So the macros have to be
    // manually expanded and stripped of the bitshift.
    enum class Facility {
        Auth = 4,
        AuthPrivate = 10,
        Cron = 9,
        Daemon = 3,
        FTP = 11,
        Kernel = 0,
        Local0 = 16,
        Local1 = 17,
        Local2 = 18,
        Local3 = 19,
        Local4 = 20,
        Local5 = 21,
        Local6 = 22,
        Local7 = 23,
        LinePrinter = 6,
        Mail = 2,
        News = 7,
        Syslog = 5,
        User = 1,
        UUCP = 8,
    };

    using LogValue = std::variant<std::string, Priority, Facility>;

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

        void log(const std::map<std::string, LogValue>& kv);
        void wrapup();
        void write_to_socket(std::string msg);
        void marshal_field(std::ostringstream& input, std::string name, std::string value);
    };
};

#endif // JOURNALPP_H_
