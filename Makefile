%: %.cpp
	g++ $< -O3 -o $@

play_guessing_game: guessing_game
	./guessing_game


play_forca: forca
	./forca
