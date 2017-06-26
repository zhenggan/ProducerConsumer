prodconsume: main.cpp queue.h producer.h
	g++ main.cpp queue.cpp producer.cpp -pthread -o prodconsume

