# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
# ** ** ** ** **    DIGIT VALIDATOR SECTION    ** ** ** ** **
# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **


class Inter:
    @staticmethod
    def read(p_question):
        """
        Allow to validate an user input for simple integers
        :param p_question: the question to ask to the user
        :return: int the value of the input
        """
        while True:
            value = input(p_question + ' ')
            if value.isdigit():
                return int(value)
            else:
                print("Please, enter a simple number...")

    @staticmethod
    def read_positive(p_question):
        """
        Allow to validate an user input for simple positive integers
        :param p_question: the question to ask to the user
        :return: int the value of the input
        """
        while True:
            value = input(p_question + ' ')
            if value.isdigit() and int(value) >= 0:
                return int(value)
            else:
                print("Please, enter a simple positive number...")

    @staticmethod
    def read_with_min(p_question, p_min):
        """
         Allow to validate an user input for simple integers bigger than the minimum passed in param
        :param p_question:  the question to ask to the user
        :param p_min: the minimum value required
        :return: int  the value of the input
        """
        while True:
            value = input(p_question + ' ')
            if value.isdigit() and int(value) >= p_min:
                return int(value)
            else:
                print("Please, enter a simple number higher than %d" % p_min)

    @staticmethod
    def read_in_between(p_question, p_min, p_max):
        """
         Allow to validate an user input for simple  integers bigger between the number in params
        :param p_question:  the question to ask to the user
        :param p_min: the minimum value required
        :param p_max: the maximum value required
        :return: int  the value of the input
        """
        while True:
            value = input(p_question + ' ')
            if value.isdigit() and p_min <= int(value) <= p_max:
                return int(value)
            else:
                print("Please, enter a simple number between %d and %d " % (p_min, p_max))

    @staticmethod
    def read_min_esc(p_question, p_min, p_esc):
        """
         Allow to validate an user input for simple integers bigger than the minimum passed in param
         with a possibility to enter an escape value to cancel
        :param p_question:  the question to ask to the user
        :param p_min: the minimum value required
        :param p_esc: the escape value
        :return:  the value of the input
        """
        while True:
            value = input(p_question + ' ')

            if str(p_esc).lower() == str(value).lower():
                return str(value)
            elif value.isdigit() and (p_min <= int(value)):
                return int(value)
            else:
                print("Please, enter a simple positive number higher than " + str(p_min) + ", press " +
                      str(p_esc) + " to cancel")

    @staticmethod
    def read_min_max_esc(p_question, p_min, p_max, p_esc):
        """
         Allow to validate an user input for simple integers bigger than the minimum passed in param
         with a possibility to enter an escape value to cancel
        :param p_question:  the question to ask to the user
        :param p_min: int the minimum value required
        :param p_max: int the maximum value required
        :param p_esc: mixed the escape value
        :return: mixed the value of the input or the escape char in Uppercase
        """
        while True:
            value = input(p_question + ' ')

            if str(p_esc).lower() == str(value).lower():
                return str(value).upper()
            elif value.isdigit() and (p_min <= int(value) <= p_max):
                return int(value)
            else:
                print("Please, enter a simple positive number between " + str(p_min) + " and " +
                      str(p_max) + ", press " + str(p_esc) + " to cancel")
