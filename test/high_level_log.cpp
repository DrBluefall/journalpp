#include <journalpp/journalpp.h>

int main() {
    journalpp::journal j({{"JOURNALPP_TEST", "test/high_level_log"}});

    j.log({
        { "MESSAGE", "message 1" },
        { "PRIORITY", journalpp::Priority::Debug },
        { "SYSLOG_FACILITY", journalpp::Facility::Local7 },
    });

    j.log({
        { "MESSAGE", "message 2" },
        { "PRIORITY", journalpp::Priority::Notice },
        { "SYSLOG_FACILITY", journalpp::Facility::Local6 },
    });

    j.log({
        { "MESSAGE", "message 3" },
        { "PRIORITY", journalpp::Priority::Error },
        { "SYSLOG_FACILITY", journalpp::Facility::Local5 },
    });

    j.wrapup();
}
