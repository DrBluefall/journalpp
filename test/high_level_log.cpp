#include <journalpp/journalpp.h>

int main() {
    journalpp::journal j;

    j.log({
        { "MESSAGE", "test/high_level_log.cpp 1" },
        { "PRIORITY", journalpp::Priority::Debug },
        { "SYSLOG_FACILITY", journalpp::Facility::Local7 },
    });

    j.log({
        { "MESSAGE", "test/high_level_log.cpp 2" },
        { "PRIORITY", journalpp::Priority::Notice },
        { "SYSLOG_FACILITY", journalpp::Facility::Local6 },
    });

    j.log({
        { "MESSAGE", "test/high_level_log.cpp 3" },
        { "PRIORITY", journalpp::Priority::Error },
        { "SYSLOG_FACILITY", journalpp::Facility::Local5 },
    });

    j.wrapup();
}
