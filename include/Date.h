#pragma once

#include <ctime>
#include <string>

namespace ima {
    class Date {
        public:
            Date();
            explicit Date(std::string &);
            explicit Date(std::string &&);
            Date(const Date &) = default;
            Date(Date &&) = default;
            Date &operator=(const Date &) = default;
            Date &operator=(Date &&) = default;
            void setDate(std::string &);
            std::string getDateStr() const;
            static Date getCurrentDate();
            unsigned int operator-(const Date &);
            Date operator+(unsigned int) const;
            bool operator!=(const Date &);
            bool operator==(const Date &);
            bool operator<(const Date &);
            bool operator>(const Date &);
            bool operator<=(const Date &);
            bool operator>=(const Date &);
        private:
            std::time_t time;
    };
}
