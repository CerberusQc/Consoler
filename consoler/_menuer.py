# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
# ** ** ** ** **   FLOAT VALIDATOR SECTION     ** ** ** ** **
# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **


class Menuer:
    @staticmethod
    def _format_validation_character(p_chars):
        """
        Allow to format a list of character with [] around them (Exemple ABC -> [A] [B] [C])
        :param p_chars: the list of chars to format
        :return: the list of chars formatted
        """
        formatted_char = ""
        for i in range(0, len(p_chars)):
            formatted_char += '['
            formatted_char += p_chars[i]
            formatted_char += ']'
            formatted_char += ' '

        return formatted_char

    @staticmethod
    def _analyze_menu(p_menu):
        """
        Allow to extract a list of chars for menu (ex: "[P]lane, [C]ar, [O]thers" will return "PCO")
        :param p_menu: the menu string you want to extract the char
        :return: the chars from the chars between '[' & ']'
        """
        formatted_char = ""
        is_analyzing = False

        for i in range(0, len(p_menu)):
            if p_menu[i] == '[' and p_menu[i + 2] == ']':
                formatted_char += p_menu[i + 1]

        return formatted_char

    @staticmethod
    def confirm(p_question):
        """
        TODO
        :param p_question:
        :return:
        """
        while True:
            answer = input(p_question + ' (Y/N) :')

            if answer.lower() == "y":
                return True

            if answer.lower() == "n":
                return False

            print("Please confirm by pressing (Y/N) then Enter")

    @staticmethod
    def read_menu(p_menu):
        while True:
            choices = Menuer._analyze_menu(p_menu).upper()

            choice = input("\n" + p_menu).upper()

            if choice in choices:
                return choice
            else:
                print("\nPlease enter a valid option --> %s"
                      % Menuer._format_validation_character(choices))
