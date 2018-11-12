# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
# ** ** ** ** **   FLOAT VALIDATOR SECTION    ** ** ** ** **
# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **

# CONSTANT
from enum import Enum
from datetime import date
from consoler._inter import Inter


class Month(Enum):
    """
    Author : Bastien Roy-Mazoyer
    """
    JANUARY = 1
    FEBRUARY = 2
    MARCH = 3
    APRIL = 4
    MAY = 5
    JUNE = 6
    JULY = 7
    AUGUST = 8
    SEPTEMBER = 9
    OCTOBER = 10
    NOVEMBER = 11
    DECEMBER = 12

    def __int__(self):
        return self.value

    def __str__(self):
        """
        TODO
        :return:
        """
        months = {
            Month.JANUARY: "January",
            Month.FEBRUARY: "February",
            Month.MARCH: "March",
            Month.APRIL: "April",
            Month.MAY: "May",
            Month.JUNE: "June",
            Month.JULY: "July",
            Month.AUGUST: "August",
            Month.SEPTEMBER: "September",
            Month.OCTOBER: "October",
            Month.NOVEMBER: "November",
            Month.DECEMBER: "December"
        }
        return months.get(self, "Invalid Value")


class Dater:
    """
     Author : Bastien Roy-Mazoyer
    """

    @staticmethod
    def read(p_question):
        """
        Allow to read the input of a valid date (leap year included)
        :param p_question: the question to ask to the user
        :return: date The date input from the user
        """

        # index 0 is a filler for a natural use of Months of the year (1 is January)
        reg_days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        leap_days = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        print(p_question)
        year = Inter.read("Year ? ")

        print('\n')

        for i in range(1, 13):
            print(str(i) + "- " + str(Month(i)))

        month_msg = "\nMonth of Year %d ?" % year

        month = Inter.read_in_between(month_msg, 1, 12)

        month_msg = "\nDay of %s ?" % Month(month)

        day = Inter.read_in_between(month_msg, 1,
                                    leap_days[month] if Dater.is_leap(year) else reg_days[month])

        return date(year, month, day)

    @staticmethod
    def is_leap(p_year):
        """
        Allow to check if the year is a leap year or not
        :param p_year: int the year to check
        :return: bool True if it is a leap year
        """
        p_year = int(p_year)
        return (p_year % 4 == 0 and p_year % 100 != 0) or p_year % 400 == 0
