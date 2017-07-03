prodconsume: main.cpp producer.h
	g++ main.cpp producer.cpp -pthread -o prodconsume

