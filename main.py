import consoler
import sys

if __name__ == '__main__':
    def execute_dater():
        print("Dater")


    def execute_floater():
        print("Floater")


    def execute_inter():
        print("\n\nInter the tools for value input in Int\n")
        print(consoler.Inter.read("Simple number please : "))
        print(consoler.Inter.read_in_between("Simple number between 1 and 10 ", 0, 10))


    def execute_stringer():
        print("Stringer")


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
        user_selection(consoler.Menuer.ReadMenu("Consoler is a tool for easy IO in console application\n\n"
                                                "Which option of Consoler you want to try ?\n\n"
                                                "  [D]ater    - tools for date creation with validation\n"
                                                "  [F]loater  - tools for value input in Float\n"
                                                "  [I]inter   - tools for value input in Int\n"
                                                "  [S]tringer - tools for string input with validation\n"
                                                "  [Q]uitter  - tool to quit the current program\n\n"
                                                "   Selection : "))
