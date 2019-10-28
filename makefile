CC = g++ -std=c++11 
exe_file= play_game

$(exe_file): main.o hunt.o hunt_1.o private_acc.o private_acc_1.o
	$(CC) main.o hunt.o hunt_1.o private_acc.o private_acc_1.o -o $(exe_file)
main.o: main.cpp
	$(CC) main.cpp -c
hunt.o: hunt.cpp
	$(CC) hunt.cpp -c
hunt_1.o: hunt_1.cpp
	$(CC) hunt_1.cpp -c
private_acc.o: private_acc.cpp
	$(CC) private_acc.cpp -c
private_acc_1.o: private_acc_1.cpp
	$(CC) private_acc_1.cpp -c

clean:
	rm -f a.out *.o Hunt_wumpus
