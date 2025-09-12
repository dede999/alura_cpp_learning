%: %.cpp
	g++ $< -O3 -o $@

play_guessing_game: guessing_game
	./guessing_game

forca: forca.cpp headers/forca/*.cpp
	g++ forca.cpp headers/forca/*.cpp -O3 -o forca

play_forca: forca
	./forca
