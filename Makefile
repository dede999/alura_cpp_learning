%: %.cpp
	g++ $< -O3 -o bin/$@

play_guessing_game: guessing_game
	./bin/guessing_game

forca: forca.cpp headers/forca/*.cpp
	g++ forca.cpp headers/forca/*.cpp -O3 -o bin/forca

accounts: accounts.cpp headers/accounts/*.cpp
	g++ accounts.cpp headers/accounts/*.cpp -O3 -o bin/accounts

play_forca: forca
	./bin/forca

see_accounts: accounts
	./bin/accounts

test: test/main.cpp headers/**/*.cpp test/forca/*.cpp
	g++ $< -O3 -o bin/test
	./bin/test

clean:
	rm bin/*

all: guessing_game forca accounts