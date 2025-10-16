tictactoe: Source.cpp game.h game.cpp board.h board.cpp player.h player.cpp bot.h bot.cpp queue.h stack.h
	@echo "Compiling TicTacToe v2"
	g++ -Iinclude Source.cpp game.cpp board.cpp player.cpp bot.cpp -o tictactoe
