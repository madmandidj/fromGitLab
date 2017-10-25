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


objects = StockAccount.o FamilyAccount.o PersonalAccount.o Observer.o Subject.o AccountFactory.o AccountImpl.o Account.o Bank.o TestBank.o

TestBank: $(objects) 
	g++ $(FLAGS) -o TestBank $(objects) 
	
	
TestBank.o: TestBank.cpp $(BANK_PATH)Bank.h
	g++ $(FLAGS) -c TestBank.cpp


Bank.o: $(BANK_PATH)Bank.cpp $(BANK_PATH)Bank.h $(SUBJECT_PATH)Subject.h $(ACNT_PATH)Account.h
	g++ $(FLAGS) -c $(BANK_PATH)Bank.cpp
	
	
Account.o: $(ACNT_PATH)Account.cpp $(ACNT_PATH)Account.h $(OBSERVER_PATH)Observer.h \
			$(SUBJECT_PATH)Subject.h $(ACNT_FACT_PATH)AccountFactory.h
	g++ $(FLAGS) -c $(ACNT_PATH)Account.cpp
	

AccountImpl.o: $(ACNT_IMPL_PATH)AccountImpl.cpp $(ACNT_IMPL_PATH)AccountImpl.h
	g++ $(FLAGS) -c $(ACNT_IMPL_PATH)AccountImpl.cpp 
	

AccountFactory.o: $(ACNT_FACT_PATH)AccountFactory.cpp $(ACNT_FACT_PATH)AccountFactory.h \
					$(ACNT_IMPL_PATH)AccountImpl.h $(PERSONAL_ACNT_PATH)PersonalAccount.h \
					$(FAMILY_ACNT_PATH)FamilyAccount.h $(STOCK_ACNT_PATH)StockAccount.h
	g++ $(FLAGS) -c $(ACNT_FACT_PATH)AccountFactory.cpp


Subject.o: $(SUBJECT_PATH)Subject.cpp $(SUBJECT_PATH)Subject.h
	g++ $(FLAGS) -c $(SUBJECT_PATH)Subject.cpp
	
	
Observer.o: $(OBSERVER_PATH)Observer.cpp $(OBSERVER_PATH)Observer.h
	g++ $(FLAGS) -c $(OBSERVER_PATH)Observer.cpp 
	

PersonalAccount.o: $(PERSONAL_ACNT_PATH)PersonalAccount.cpp $(PERSONAL_ACNT_PATH)PersonalAccount.h \
					$(ACNT_IMPL_PATH)AccountImpl.h
	g++ $(FLAGS) -c $(PERSONAL_ACNT_PATH)PersonalAccount.cpp


FamilyAccount.o: $(FAMILY_ACNT_PATH)FamilyAccount.cpp $(FAMILY_ACNT_PATH)FamilyAccount.h \
					$(ACNT_IMPL_PATH)AccountImpl.h
	g++ $(FLAGS) -c $(FAMILY_ACNT_PATH)FamilyAccount.cpp
	

StockAccount.o: $(STOCK_ACNT_PATH)StockAccount.cpp $(STOCK_ACNT_PATH)StockAccount.h \
					$(ACNT_IMPL_PATH)AccountImpl.h
	g++ $(FLAGS) -c $(STOCK_ACNT_PATH)StockAccount.cpp

	
clean:
	rm TestBank $(objects)	
 







