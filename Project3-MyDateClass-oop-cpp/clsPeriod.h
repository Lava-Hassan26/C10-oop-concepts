#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsPeriod
{
    clsDate _startDate;
    clsDate _endDate;

public:
    clsPeriod(clsDate startDate, clsDate endDate)
    {
        _startDate = startDate;
        _endDate = endDate;
    }

    void SetStartDate(clsDate startDate)
    {
        _startDate = startDate;
    }

    clsDate GetStartDate()
    {
        return _startDate;
    }

    void SetEndDate(clsDate endDate)
    {
        _endDate = endDate;
    }

    clsDate GetEndDate()
    {
        return _endDate;
    }

    static bool IsPeriodsOverlap(clsPeriod period1, clsPeriod period2)
    {
        if (clsDate::CompareDates(period2.GetEndDate(), period1.GetStartDate()) == clsDate::enCompareDates::Before
            || clsDate::CompareDates(period2.GetStartDate(), period1.GetEndDate()) == clsDate::enCompareDates::After)
            return false;
        return true;
    }

    bool IsPeriodsOverlap(clsPeriod period2)
    {
        return IsPeriodsOverlap(*this, period2);
    }

    static int PeriodLengthInDays(clsPeriod period, bool isEndDayInclude = true)
    {
        return clsDate::DifferenceInDaysBetweenDates(period.GetStartDate(), period.GetEndDate(), isEndDayInclude);
    }

    int PeriodLengthInDays(bool isEndDayInclude = true)
    {
        return PeriodLengthInDays(*this, isEndDayInclude);
    }

    static bool IsDateWithinPeriod(clsPeriod period, clsDate date)
    {
        if (clsDate::IsDate1BeforeDate2(date, period.GetStartDate()) || clsDate::IsDate1AfterDate2(date, period.GetEndDate()))
            return false;
        return true;
    }

    bool IsDateWithinPeriod(clsDate date)
    {
        return IsDateWithinPeriod(*this, date);
    }

    static int CountOverlapDays(clsPeriod period1, clsPeriod period2)
    {
        if (!IsPeriodsOverlap(period1, period2))
            return 0;

        clsDate startDate1 = period1.GetStartDate();
        clsDate endDate1 = period1.GetEndDate();
        clsDate startDate2 = period2.GetStartDate();
        clsDate endDate2 = period2.GetEndDate();

        clsDate overlapStart = clsDate::IsDate1BeforeDate2(startDate1, startDate2) ? startDate2 : startDate1;

        clsDate overlapEnd = clsDate::IsDate1BeforeDate2(endDate1, endDate2) ? endDate1 : endDate2;

        return clsDate::DifferenceInDaysBetweenDates(overlapStart, overlapEnd, true);
    }

    int CountOverlapDays(clsPeriod period2)
    {
        return CountOverlapDays(*this, period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        _startDate.Print();
        cout << "Period End: ";
        _endDate.Print();
    }
};