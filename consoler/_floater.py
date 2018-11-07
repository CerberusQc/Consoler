# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
# ** ** ** ** **   FLOAT VALIDATOR SECTION    ** ** ** ** **
# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **


class Floater:
    @staticmethod
    def is_float(value):
        try:
            float(value)
            return True
        except ValueError:
            return False

    @staticmethod
    def read(p_question):
        """
        Allow to validate an user input for Float
        :param p_question: the question to ask to the user
        :return: the value of the input
        """
        while True:
            value = input(p_question + ' ')
            if Floater.is_float(value):
                return float(value)
            else:
                print("Please, enter a float value...")

    @staticmethod
    def read_positive(p_question):
        """
        Allow to validate an user input for Float
        :param p_question: the question to ask to the user
        :return: the value of the input
        """
        while True:
            value = input(p_question + ' ')
            if Floater.is_float(value) and float(value) > 0:
                return float(value)
            else:
                print("Please, enter a simple positive number...")

    @staticmethod
    def read_with_min(p_question, p_min):
        """
         Allow to validate an user input for Float bigger than the minimum passed in param
        :param p_question:  the question to ask to the user
        :param p_min: the minimum value required
        :return:  the value of the input
        """
        while True:
            value = input(p_question + ' ')
            if Floater.is_float(value) and float(value) >= p_min:
                return float(value)
            else:
                print("Please, enter a simple number higher than %d" % p_min)

    @staticmethod
    def read_in_between(p_question, p_min, p_max):
        """
         Allow to validate an user input for Float bigger between the number in params
        :param p_question:  the question to ask to the user
        :param p_min: the minimum value required
        :param p_max: the maximum value required
        :return:  the value of the input
        """
        while True:
            value = input(p_question + ' ')
            if Floater.is_float(value) and p_min <= float(value) <= p_max:
                return float(value)
            else:
                print("Please, enter a simple number between %d and %d " % (p_min, p_max))

    @staticmethod
    def read_min_esc(p_question, p_min, p_esc):
        """
         Allow to validate an user input for Float bigger than the minimum passed in param
         with a possibility to enter an escape value to cancel
        :param p_question:  the question to ask to the user
        :param p_min: the minimum value required
        :param p_esc: the escape value
        :return:  the value of the input
        """
        while True:
            value = input(p_question + ' ')
            if Floater.is_float(value) and (p_min <= float(value) or p_esc == float(value)):
                return float(value)
            else:
                print("Please, enter a simple positive number higher than " + str(p_min) + ", press " + str(
                    p_esc) + " to cancel")

    @staticmethod
    def read_min_max_esc(p_question, p_min, p_max, p_esc):
        """
         Allow to validate an user input for Float bigger than the minimum passed in param
         with a possibility to enter an escape value to cancel
        :param p_question:  the question to ask to the user
        :param p_min: the minimum value required
        :param p_max: the maximum value required
        :param p_esc: the escape value
        :return:  the value of the input
        """
        while True:
            value = input(p_question + ' ')
            if Floater.is_float(value) and (p_min <= float(value) <= p_max or p_esc == float(value)):
                return float(value)
            else:
                print("Please, enter a positive float between " + p_min + " and " + p_max +
                      ", press " + p_esc + " to cancel")
