Using the SmartHome system:
---------------------------
1) In order to compile and run system: open terminal, navigate to "./Code/", enter "make clean", then "make"


2) In order to config your own system: open "Config.ini" in "./Code/INI/".


3) Guidelines for composing your own "Config.ini":
	A) Format for agent MUST be:
		/\/\/\/\/\/\/\
		[agentID]
		type = XXX
		room = XXX
		floor = XXX
		log = XXX
		config = XXX
		
		/\/\/\/\/\/\/\
		NOTE: Blankspace characters between type, =, and XXX (XXX is user defined characters)
		NOTE: Blank line between agents
	B) Do not use '=' character in user defined characters/strings.
	C) All fields must have a user defined input
	
	
4) Implementing Sensor Agent:
	A) Function "DoOnEvent" should be implemented but can be empty.
	B) Function "DoRoutine" should be implemented, and should call function "PublishEvent"!
	
	
5) Implementing Controller Agent:
	A) Function "DoOnEvent" should be implemented!
	B) Function "DoRoutine" should be implemented, and should call function "DoOnEvent"!
	  	






