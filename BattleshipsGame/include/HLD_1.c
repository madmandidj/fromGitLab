GameManager
-------------
void InitGame(std::string _pathToConfig, std::string _pathToPlayer1, std::string _pathToPlayer2);
void PlayGame(GAME_MODE _gameMode); /* interactive /non-interactive */



UIManager
-------------
void PrintMenu();
void PrintPlayerStatus(Player_t _player);
void PrintGameStatus(PlayerContainer_t _playerContainer);



ConfigLoader
-------------
void LoadConfig(std::string _pathToConfig);


PlayerLoader
-------------
Player_t LoadPlayer(std::string _pathToPlayer);



Player
-------------
BTL_Error PlaceShips();
BTL_Error Attack(BoardCoordinate_t _attackCoordinate);
BoardStatus_t GetMyStatus(Board_t _board); /* protected */
***************Individual Implementation required:
/* This function is called in PlaceShips */
ShipPosition_t CalculateShipPlacement(Ship_t _ship); 
/* This function is called in Attack */
BoardCoordinate_t CalculateAttackCoordinate(BoardStatus_t _boardStatus); 


-------------
-------------
-------------

Board_t
{
	unsigned int 	m_xLength;
	unsigned int 	m_yLength;
	BoardStatus_t 	m_boardStatus; //should be in GameManager, along with board for each player
};

BoardStatus_t
{
	unsigned int					m_numOfShips;
	unsigned int					m_numOfDestroyedShips;
	std::vector<Ship_t*>			m_ShipsVec;
	std::vector<BoardCoordinate_t*> m_HitCoordinatesVec;
	std::vector<BoardCoordinate_t*> m_MissCoordinatesVec;
};


Ship_t
{
	unsigned int 	m_length;
	unsigned int 	m_hitNum;
	ShipPosition_t* m_position;
};


ShipPosition_t
{
	BoardCoordinate_t	m_coordinate;
	SHIP_ORIENTATION	m_orientation;
};


BoardCoordinate_t
{
	std::string m_row;
	unsigned int m_col;
	COORDINATE_STATUS 	m_status;
};

enum SHIP_ORIENTATION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}SHIP_ORIENTATION;


enum COORDINATE_STATUS
{
	UNINITIALIZED,
	EMPTY,
	FULL,
	MISS,
	HIT
}COORDINATE_STATUS;

enum SHIP_LENGTH
{
	DESTROYER = 2,
	SUBMARINE = 3,
	CRUISER = 3,
	BATTLESHIP = 4,
	CARRIER = 5
}SHIP_LENGTH;

