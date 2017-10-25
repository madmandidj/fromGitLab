FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32

BANK_PATH = ./Bank/
ACNT_PATH = ./Account/
ACNT_IMPL_PATH = ./AccountImpl/
ACNT_FACT_PATH = ./AccountFactory/
SUBJECT_PATH = ./Subject/
OBSERVER_PATH = ./Observer/
PERSONAL_ACNT_PATH = ./PersonalAccount/
FAMILY_ACNT_PATH = ./FamilyAccount/
STOCK_ACNT_PATH = ./StockAccount/



objects = StockAccount.o FamilyAccount.o PersonalAccount.o Observer.o Subject.o
			AccountFactory.o AccountImpl.o Account.o Bank.o TestBank.o


TestBank: $(objects) 
	g++ $(FLAGS) -o TestBank $(objects) 


Bank.o: $(BANK_PATH)Bank.cpp $(BANK_PATH)Bank.h $(SUBJECT_PATH)Subject.h $(ACNT_PATH)Account.h
	g++ $(FLAGS) -c  $(BANK_PATH)Bank.cpp
	
	
Account.o: $(ACNT_PATH)Account.cpp $(ACNT_PATH)Account.h $(OBSERVER_PATH)Observer.h 
			$(SUBJECT_PATH)Subject.h $(ACNT_FACT_PATH)AccountFactory.h
	g++ $(FLAGS) -c  $(ACNT_PATH)Account.cpp
	

AccountImpl.o: $(ACNT_IMPL_PATH)AccountImpl.cpp $(ACNT_IMPL_PATH)AccountImpl.h
	g++ $(FLAGS) -c  $(ACNT_IMPL_PATH)AccountImpl.cpp 
	

AccountFactory.o: $(ACNT_FACT_PATH)AccountFactory.cpp $(ACNT_FACT_PATH)AccountFactory.h
					$(ACNT_IMPL_PATH)AccountImpl.h $(PERSONAL_ACNT_PATH)PersonalAccount.h
					$(FAMILY_ACNT_PATH)FamilyAccount.h $(STOCK_ACNT_PATH)StockAccount.h
	g++ $(FLAGS) -c  $(ACNT_FACT_PATH)AccountFactory.cpp


	
clean:
	rm TestBank $(objects)	
 







