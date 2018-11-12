# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
# ** ** ** ** **   STRING VALIDATOR SECTION    ** ** ** ** **
# ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **


class Stringer:
    @staticmethod
    def read(p_question):
        return input(p_question + ' ')

    @staticmethod
    def read_not_empty(p_question):
        while True:
            value = input(p_question + ' ').strip()

            if len(value) > 0:
                return value
            else:
                print("You can't just enter nothing !")

    @staticmethod
    def read_controlled_size(p_question, p_min, p_max):
        while True:
            value = input(p_question + ' ').strip()

            if p_min <= len(value) <= p_max:
                return value
            else:
                print("Please your answer need to be between %d and %d characters..." % (p_min, p_max))

    @staticmethod
    def read_word(p_question):
        while True:
            value = input(p_question + ' ').strip()

            if value.find(' ') == -1 and len(value) > 0:
                return value
            else:
                print("Please your answer need to be a single word")
