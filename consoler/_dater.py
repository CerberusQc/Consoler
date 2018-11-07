# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
# ** ** ** ** **   FLOAT VALIDATOR SECTION    ** ** ** ** **
# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **

# CONSTANT
from enum import Enum


class Month(Enum):
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

    def __str__(self):
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