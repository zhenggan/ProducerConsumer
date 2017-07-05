prodconsume: main.cpp consumer.h consumer.cpp producer.h producer.cpp
	g++ main.cpp producer.cpp consumer.cpp -pthread -o prodconsume

