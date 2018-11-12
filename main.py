import consoler
import sys

if __name__ == '__main__':
    def execute_dater():
        print("LEAP YEAR !" if consoler.Dater.is_leap(
            consoler.Inter.read("Check if it is a Leap year or not ! ")) else "Regular Year... sorry...")
        print(consoler.Dater.read("What is your birthday ?"))


    def execute_floater():
        print("\n\nInter the tools for value input in Int\n")
        print(consoler.Floater.read("\nEnter any value (can be decimal) please : "))
        print(consoler.Floater.read_positive("\nPositive value (can be decimal) please : "))
        print(consoler.Floater.read_with_min("\n value (can be decimal) > 5.5 please : ", 5.5))
        print(consoler.Floater.read_in_between("\nSimple number between 2.25 and 7.75 ", 2.25, 7.75))
        print("You have cancelled by pressing the escape character! " if
              consoler.Floater.read_min_max_esc("\nNumber between 5.5 and 15.25, Enter Q to cancel : ", 5.5,
                                                15.25, "Q") == "Q" else "Good ! The Demo of Floater if done")


    def execute_inter():
        print("\n\nInter the tools for value input in Int\n")
        print(consoler.Inter.read("\nSimple number please : "))
        print(consoler.Inter.read_positive("\nSimple Positive number please : "))
        print(consoler.Inter.read_with_min("\nSimple number > 5 please : ", 5))
        print(consoler.Inter.read_in_between("\nSimple number between 1 and 10 ", 1, 10))
        print("You have cancelled by pressing the escape character! " if
              consoler.Inter.read_min_max_esc("\nNumber between 5 and 15, Enter Q to cancel : ", 5, 15, "Q") == "Q" else
              "Good ! The Demo of Inter if done")


    def execute_stringer():
        print("\n\ntools for string input with validation\n")
        print(consoler.Stringer.read("\nEnter anything you want : "))
        print(consoler.Stringer.read_not_empty("\nEnter something but not nothing : "))
        print(consoler.Stringer.read_controlled_size("\nEnter something between 5 and 15 characters : ", 5, 15))
        print(consoler.Stringer.read_word("\nEnter a single word : "))


    def execute_quitter():
        sys.exit(0)


    def user_selection(p_selection):

        if p_selection == "D":
            execute_dater()

        elif p_selection == "F":
            execute_floater()

        elif p_selection == "I":
            execute_inter()

        elif p_selection == "S":
            execute_stringer()

        elif p_selection == "Q":
            execute_quitter()


    while True:
        user_selection(consoler.Menuer.read_menu("Consoler is a tool for easy IO in console application\n\n"
                                                 "Which option of Consoler you want to try ?\n\n"
                                                 "  [D]ater    - tools for date creation with validation\n"
                                                 "  [F]loater  - tools for value input in Float\n"
                                                 "  [I]inter   - tools for value input in Int\n"
                                                 "  [S]tringer - tools for string input with validation\n"
                                                 "  [Q]uitter  - tool to quit the current program\n\n"
                                                 "   Selection : "))
