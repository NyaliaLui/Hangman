import sys
from hangman import GameCLI

def main():
    game = GameCLI()

    #show welcome message
    print('== Welcome to Hangman! ==\n')

    while game.is_running():

        #prompt for word/phrase or guesser's input
        game.prompt()

        #draw the board to the screen
        game.draw_board()

if __name__ == "__main__":
    if len(sys.argv) != 1:
        print('Usage: python3 hangman.py')
        sys.exit(1)

    main()