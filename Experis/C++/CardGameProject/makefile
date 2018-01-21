FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
objects = Card.o Cards.o Player.o Players.o BareketCards.o TestBareketCards.o

CARD_PATH = ./Card/
CARDS_PATH = ./Cards/
PLAYER_PATH = ./Player/
PLAYERS_PATH = ./Players/
BRKT_GAME_PATH = ./BareketCards/
CARD_GAME_PATH = ./CardGame/




RunBareketCards: $(objects) 
	g++ $(FLAGS) -o RunBareketCards  $(objects) 
	
	
TestBareketCards.o: $(BRKT_GAME_PATH)TestBareketCards.cpp $(BRKT_GAME_PATH)BareketCards.h
	g++ $(FLAGS) -c  $(BRKT_GAME_PATH)TestBareketCards.cpp 


BareketCards.o: $(BRKT_GAME_PATH)BareketCards.cpp $(BRKT_GAME_PATH)BareketCards.h $(CARDS_PATH)Cards.h \
				$(PLAYERS_PATH)Players.h $(CARD_GAME_PATH)CardGame.h	
	g++ $(FLAGS) -c  $(BRKT_GAME_PATH)BareketCards.cpp 
	

Players.o: $(PLAYERS_PATH)Players.cpp  $(PLAYERS_PATH)Players.h $(PLAYER_PATH)Player.h 	
	g++ $(FLAGS) -c  $(PLAYERS_PATH)Players.cpp
	
	
Player.o: $(PLAYER_PATH)Player.cpp $(PLAYER_PATH)Player.h $(CARDS_PATH)Cards.h	
	g++ $(FLAGS) -c  $(PLAYER_PATH)Player.cpp
	
	
Cards.o: $(CARDS_PATH)Cards.cpp $(CARDS_PATH)Cards.h $(CARD_PATH)Card.h 	
	g++ $(FLAGS) -c  $(CARDS_PATH)Cards.cpp


Card.o: $(CARD_PATH)Card.cpp $(CARD_PATH)Card.h 	
	g++ $(FLAGS) -c  $(CARD_PATH)Card.cpp


clean:
	rm RunBareketCards $(objects)	
	
