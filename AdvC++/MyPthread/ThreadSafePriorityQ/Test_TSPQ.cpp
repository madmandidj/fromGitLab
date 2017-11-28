#include "TSPQ.h"
#include "../Thread/Thread.h"
#include<iostream>
//#include<math.h>
//#include<time.h>


class Product
{
public:
	Product():m_ID(++m_numOfProducts){}
	int GetID() const {return m_ID;}
	bool operator<(const Product& _rhs) const
	{
		return (GetID() < _rhs.GetID());
	}
private:
	static size_t 				m_numOfProducts;
	size_t						m_ID;
};

class Producer
{
public:
	Producer(advcpp::TSPQ<Product*>& _tspq):m_tspq(_tspq), m_ID(++m_numOfProducers){}
	int GetID() const {return m_ID;}
	void* Produce()
	{
		for (size_t index = 0 ; index < 2; ++index)
		{
			Product* product = new Product;
			m_tspq.Push(product);
			std::cout << "Producer " << m_ID << " pushed: " << product->GetID() << std::endl;	
		}
		return 0;
	}
private:
	advcpp::TSPQ<Product*>& 	m_tspq;
	size_t						m_ID;
	static size_t 				m_numOfProducers;
};

class Consumer
{
public:
	Consumer(advcpp::TSPQ<Product*>& _tspq):m_tspq(_tspq), m_ID(++m_numOfConsumers){}
	int GetID() const {return m_ID;}
	void* Consume()
	{
		for (size_t index = 0 ; index < 3; ++index)
		{
			Product* product;
			m_tspq.Pop(&product);
			std::cout << "Consumer " << m_ID << " popped: " << product->GetID() << std::endl;
			delete product;
		}
		return 0;
	}
private:
	advcpp::TSPQ<Product*>& 	m_tspq;
	size_t						m_ID;
	static size_t 				m_numOfConsumers;
};

size_t Product::m_numOfProducts = 0;
size_t Producer::m_numOfProducers = 0;
size_t Consumer::m_numOfConsumers = 0;

int main()
{
//	srand(0);
	advcpp::TSPQ<Product*> myTSPQ;
	Producer prod1(myTSPQ);
	Producer prod2(myTSPQ);
	Producer prod3(myTSPQ);
	Consumer cons1(myTSPQ);
	Consumer cons2(myTSPQ);

	advcpp::Thread<Consumer, &Consumer::Consume> consThread1(&cons1);
	sleep(1);	
	advcpp::Thread<Consumer, &Consumer::Consume> consThread2(&cons2);
	sleep(1);	
	
	advcpp::Thread<Producer, &Producer::Produce> prodThread1(&prod1);
	sleep(1);

	prodThread1.Join();
	std::cout << "prodthrad1 joined" << std::endl;
	advcpp::Thread<Producer, &Producer::Produce> prodThread2(&prod2);
	advcpp::Thread<Producer, &Producer::Produce> prodThread3(&prod3);
	consThread1.Join();
	std::cout << "consthread1 joined" << std::endl;
	consThread2.Join();
	std::cout << "consthread2 joined" << std::endl;
	prodThread2.Join();
	prodThread3.Join();
	std::cout << "prodThread2 joined" << std::endl;

	return 0;
}
