global BOARD_SIZE
global GALLOWS_SIZE
global ALPHABT_SIZE

BOARD_SIZE = 10
GALLOWS_SIZE = 8
ALPHABT_SIZE = 26

class Gallows:

    def __init__(self):
        self.__body_complete = False
        self.__word_complete = False
        self.__board = [''] * BOARD_SIZE
        self.__gallows = [''] * GALLOWS_SIZE
        self.__alphabet = ['-'] * ALPHABT_SIZE
        self.__word = ''
        self.__fill_space = ''
        self.__attempt = 0

        #create empty gallows
        self.__gallows[0] = '  ======= '
        self.__gallows[1] = '  |     |    '
        self.__gallows[2] = '  |          '
        self.__gallows[3] = '  |          '
        self.__gallows[4] = '  |          '
        self.__gallows[5] = '  |          '
        self.__gallows[6] = '  |          '
        self.__gallows[7] = '=====     '

        #update the whole board with the gallows and the alphabet
        self.__update_board()
        self.__update_fill_space()
        self.__board[9] = ' '
    
    def user_guess(self, c):
        index, last_pos = 0, 0
        found_letter = False

        #if the letter is found, replace every occurance
        #of the letter in fill space
        while index > -1:
            index = self.__word.find(c, last_pos)

            if index > -1:
                self.__board[9] = 'Letter found! :)'
                self.__fill_space = self.__fill_space[:index] + c + self.__fill_space[(index+1):]
                last_pos = index + 1
                found_letter = True
            elif not found_letter:
                self.__board[9] = 'Letter not found :('
                self.__attempt += 1

        #mark the letter in the alphabet list
        self.__alphabet[ord(c) - 65] = c

        #mark the proper body part if the letter was not found
        #(i.e. found_letter is true)
        if not found_letter:
            if self.__attempt == 1:
                self.__create_head()

            elif self.__attempt == 2:
                self.__create_body()
            
            elif self.__attempt == 3:
                self.__create_left_arm()

            elif self.__attempt == 4:
                self.__create_right_arm()

            elif self.__attempt == 5:
                self.__create_left_leg()

            elif self.__attempt == 6:
                self.__create_right_leg()

        #check if the word was completed
        self.__word_complete = self.__fill_space.find('_') < 0

        #update the whole board
        self.__update_board()

        #update the fill_space
        self.__update_fill_space()

    def user_guess_line(self, line):
        if line == self.__word:
            self.__fill_space = self.__word
        else:
            self.__attempt = 6
            self.__create_head()
            self.__create_body()
            self.__create_left_arm()
            self.__create_right_arm()
            self.__create_left_leg()
            self.__create_right_leg()

        #check if the word was completed
        self.__word_complete = self.__fill_space.find('_') < 0

        #update the whole board
        self.__update_board()

        #update the fill_space
        self.__update_fill_space()

    def set_word(self, word):
        #word can only be set if it wasn't set previously
        #(i.e. set word when fill space is not set)
        self.__word = word
        self.__fill_space = ''

        for i in range(len(self.__word)):
            if self.__word[i] != ' ':
                self.__fill_space += '_'
            else:
                self.__fill_space += self.__word[i]

        #make sure the fill space is seen on the board
        self.__update_fill_space()

    def get_board(self):
        return self.__board

    def is_body_complete(self):
        return self.__body_complete

    def is_word_complete(self):
        return self.__word_complete
	
    #the below methods are supposed to be 'private' and thus
    #the leading underscores
    def __update_board(self):
        self.__board[0] = self.__gallows[0]
        self.__board[1] = self.__gallows[1] + self.__alphabet[0] + ' ' + self.__alphabet[1] + ' ' + self.__alphabet[2] + ' ' + self.__alphabet[3] + ' ' + self.__alphabet[4]
        self.__board[2] = self.__gallows[2] + self.__alphabet[5] + ' ' + self.__alphabet[6] + ' ' + self.__alphabet[7] + ' ' + self.__alphabet[8] + ' ' + self.__alphabet[9]
        self.__board[3] = self.__gallows[3] + self.__alphabet[10] + ' ' + self.__alphabet[11] + ' ' + self.__alphabet[12] + ' ' + self.__alphabet[13] + ' ' + self.__alphabet[14]
        self.__board[4] = self.__gallows[4] + self.__alphabet[15] + ' ' + self.__alphabet[16] + ' ' + self.__alphabet[17] + ' ' + self.__alphabet[18] + ' ' + self.__alphabet[19]
        self.__board[5] = self.__gallows[5] + self.__alphabet[20] + ' ' + self.__alphabet[21] + ' ' + self.__alphabet[22] + ' ' + self.__alphabet[23] + ' ' + self.__alphabet[24]
        self.__board[6] = self.__gallows[6] + self.__alphabet[25]
        self.__board[7] = self.__gallows[7]

    def __update_fill_space(self):
        self.__board[8] = '      '
        self.__board[8] = self.__board[8] + self.__fill_space

    def __create_head(self):
        self.__gallows[2] = '  |     O    '

    def __create_body(self):
        self.__gallows[3] = '  |     |    '
        self.__gallows[4] = '  |     |    '

    def __create_left_arm(self):
        #the left arm can only be created when the body already exists
        self.__gallows[3] = '  |    /|   '

    def __create_right_arm(self):
        #the right can can only be created when the left arm exists
        self.__gallows[3] = '  |    /|\\   '

    def __create_left_leg(self):
        self.__gallows[5] = '  |    /     '

    def __create_right_leg(self):
        #the right leg can only be created when the left leg exists
        self.__gallows[5] = '  |    / \\   '

        #the body is complete when the right leg is created
        self.__body_complete = True

