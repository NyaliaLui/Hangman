from .Gallows import Gallows

class GameCLI:
    def __init__(self):
        self.__game_board = Gallows()
        self.__word_is_set = False

    def prompt(self):
        line = ''

        if self.__word_is_set:
            print('What letter do you guess?')
            print('Alternatively, you can try to guess the whole word/phrase.')
            line = input('--> ')

            #make sure the input is entirely in upper case letters
            line = line.upper()

            if len(line) > 1:
                self.__game_board.user_guess_line(line)
            else:
                self.__game_board.user_guess(line[0])
        else:
            line = input('What is the guessing word/phrase? --> ')

            #make sure the input is entirely in upper case letters
            line = line.upper()

            self.__game_board.set_word(line)
            self.__word_is_set = True

    def draw_board(self):
        board = self.__game_board.get_board()

        for string in board:
            print(string)
        print('')

    def is_running(self):
        is_finished = False
        is_finished = self.__game_board.is_body_complete() or self.__game_board.is_word_complete()
        return not is_finished
