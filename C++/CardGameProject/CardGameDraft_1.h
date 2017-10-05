
CardGame (Abstract base class):
-------------------------------
	Public (pure virtual):
		void Shuffle(Cards* _cards);
		void Start(size_t _numOfPlayers);
		void Restart();
		void Pause();
		void Stop();
		void Quit();
		void PrintScore(unsigned int _playerNum);
		void PrintFinalScore();
		virtual bool GetPrintMode() const;
		virtual bool SetPrintMode(bool _mode = true);
		static bool SetNumOfPlayers(size_t _numOfPlayers);
		static size_t GetNumOfPlayers() const;
		
		
	Protected:
/////////		GameManager*	m_manager;
		Players* 		m_players;
		Cards*  		m_deck;
		Cards*			m_board;
		static size_t	m_numOfPlayers;
		bool			m_printMode;
		

BareketCards:
-------------
Inherits from CardGame



Card:
-----
	Public:
		bool SetSuit(const char _suit);
		char GetSuit() const;
		bool SetVal(const char _val);
		char GetVal() const;
		char SetOwner(unsigned int _ownerID);
		char GetOwner() const;
		bool IsActive() const;
		
	Private:
		char 			m_suit;
		char 			m_val;
		unsigned int	m_ownerID;
		bool			m_active;

Cards:
------
	Public:
		bool 			Shuffle();
		bool 			Sort();
		unsigned int 	GetOwner()const;
		bool 			SetOwner(unsigned int _ownerID);
		Card* 			RemoveCard(char _suit, char _val);
		Card* 			RemoveCard(size_t _index);
		bool			InsertCard(char _suit, char _val);
		bool			InsertCard(size_t _index);	
		size_t			GetNumOfActiveCards() const;
		
	Private:
		vector<Card*> 	m_cards;
		size_t			m_numOfCards;
		size_t			m_numOfActiveCards;
		size_t			m_ownerID;
		
Player:
-------
	Public:
		bool		Attack(Card* _card);
		bool		Defend(Card* _card);
		Card*		TakeCard(Cards* _cards);
		bool		PlaceCard(Cards* _card);
		bool		SetWinner();
		bool		SetInActive();
		
	Private:
		Cards* 	m_cards;
		bool	m_isActive;
		bool	m_isWinner;
		
		
Players:
--------
	Public:
		bool 	Play(Player* _player, Player* _target);
		bool 	IsWinner(Player* _player) const;
		bool 	IsActive(Player* _player) const;
		
	Private:
		Players*	m_players; //Player 0 can be dealer/table?
		size_t		m_numOfActivePlayers;







