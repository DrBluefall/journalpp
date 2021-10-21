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

    /*
     * Journal priority.
     *
     * When excluded from a call to journal::log, it'll default to
     * Priority::Info unless JOURNALPP_DEFAULT_PRIORITY is set differently.
     */
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

#ifndef JOURNALPP_DEFAULT_PRIORITY
    constexpr Priority DEFAULT_PRIORITY = Priority::Info;
#else
    constexpr Priority DEFAULT_PRIORITY = JOURNALPP_DEFAULT_PRIORITY;
#endif


    // NOTE: for some godforsaken reason, journald doesn't recognize the syslog
    // facility values as they're defined in 'sys/syslog.h'. Probably because
    // the values are bitshifted under the hood. So the macros have to be
    // manually expanded and stripped of the bitshift.
    /*
     * Journal facility.
     *
     * When excluded from a call to journal::log, the default will be
     * Facility::User, as documented in syslog(3), unless defined otherwise by
     * JOURNALPP_DEFAULT_FACILITY.
     */
    enum class Facility {
        Auth = LOG_AUTH,
        AuthPrivate = LOG_AUTHPRIV,
        Cron = LOG_CRON,
        Daemon = LOG_DAEMON,
        FTP = LOG_FTP,
        Kernel = LOG_KERN,
        Local0 = LOG_LOCAL0,
        Local1 = LOG_LOCAL1,
        Local2 = LOG_LOCAL2,
        Local3 = LOG_LOCAL3,
        Local4 = LOG_LOCAL4,
        Local5 = LOG_LOCAL5,
        Local6 = LOG_LOCAL6,
        Local7 = LOG_LOCAL7,
        LinePrinter = LOG_LPR,
        Mail = LOG_MAIL,
        News = LOG_NEWS,
        Syslog = LOG_SYSLOG,
        User = LOG_USER,
        UUCP = LOG_UUCP,
    };

#ifndef JOURNALPP_DEFAULT_FACILITY
    constexpr Facility DEFAULT_FACILITY = Facility::User;
#else
    constexpr Facility DEFAULT_FACILITY = JOURNALPP_DEFAULT_FACILITY;
#endif

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
        void log(const std::string& msg);
        void log(const Priority priority, const std::string& msg);
        void log(const Priority priority, const Facility facility, const std::string& msg);
        void wrapup();
        void write_to_socket(std::string msg);
        void marshal_field(std::ostringstream& input, std::string name, std::string value);
    };
};

#endif // JOURNALPP_H_
