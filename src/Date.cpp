#include <cstring>
#include <ctime>
#include <sstream>
#include <string>
#include <iostream>
#include <functional>
#include <chrono>
#include <iomanip>
#include <locale>
#include <cmath>
#include "Date.h"

namespace ima {
    Date::Date()
    {
        auto now = std::chrono::system_clock::now();
        time = std::chrono::system_clock::to_time_t(now);
    }

    Date::Date(std::string &date)
    {
        setDate(date);
    }

    Date::Date(std::string &&date)
    {
        setDate(date);
    }

    void Date::setDate(std::string &date) {
        std::tm dtm = {};
        std::istringstream ss(date);
        ss >> std::get_time(&dtm, "%b %d, %Y");
        time = mktime(&dtm);
    }

    std::string Date::getDateStr() const
    {
        char tStr[20];
        std::strftime(tStr, sizeof(tStr), "%F", std::localtime(&time));
        return std::string(tStr);
    }

    Date Date::getCurrentDate()
    {
        Date newDate;
        return newDate;
    }

    unsigned int Date::operator-(const Date &rhs)
    {
        double diff = std::difftime(this->time, rhs.time);
        return std::ceil(diff / (24 * 3600));
    }

    Date Date::operator+(unsigned int numOfNights) const
    {
        Date newDate;
        std::tm *lt = localtime(&this->time);
        lt->tm_mday = lt->tm_mday + numOfNights;
        newDate.time = mktime(lt);
        return newDate;
    }

    bool Date::operator!=(const Date &rhs)
    {
        double diff = std::difftime(this->time, rhs.time);
        if (static_cast<int>(diff) != 0) {
            return true;
        } else {
            return false;
        }
    }
    bool Date::operator==(const Date &rhs)
    {
        double diff = std::difftime(this->time, rhs.time);
        if (static_cast<int>(diff) == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool Date::operator<(const Date &rhs)
    {
        double diff = std::difftime(this->time, rhs.time);
        if (static_cast<int>(diff) < 0) {
            return true;
        } else {
            return false;
        }
    }

    bool Date::operator>(const Date &rhs)
    {
        double diff = std::difftime(this->time, rhs.time);
        if (static_cast<int>(diff) > 0) {
            return true;
        } else {
            return false;
        }
    }

    bool Date::operator<=(const Date &rhs)
    {
        double diff = std::difftime(this->time, rhs.time);
        if (static_cast<int>(diff) <= 0) {
            return true;
        } else {
            return false;
        }
    }

    bool Date::operator>=(const Date &rhs)
    {
        double diff = std::difftime(this->time, rhs.time);
        if (static_cast<int>(diff) >= 0) {
            return true;
        } else {
            return false;
        }
    }
}
