#include <Thread.h>
#include <ThreadController.h>

// ThreadController that will controll all threads
ThreadController controll = ThreadController();

//Sending Thread
Thread sendingThread = Thread();
//Power Thread
Thread powerThread = Thread();
//Result Thread
Thread resultThread = Thread();
// callback for myThread
void sendingCallback(){
	Serial.print("I'm sending data: ");
	Serial.println(10 * 60);
}

// callback for hisThread
void powerCallback(){
	Serial.print("I'm controling power: ");
	Serial.println(100 + 95904);
}

// callback for hisThread
void resultCallback() {
	Serial.print("We all works togeather: ");
	Serial.println(1203213 / 341);
}

void setup(){
	Serial.begin(9600);

	// Configure sendingThread
	sendingThread.onRun(sendingCallback);
	sendingThread.setInterval(2500);

	// Configure powerThread
	powerThread.onRun(powerCallback);
	powerThread.setInterval(2500);

	// Configure resultThread
	resultThread.onRun(resultCallback);
	resultThread.setInterval(2500);

	// AddsE threads to the controller
	controll.add(&sendingThread);// & to pass the pointer to it
	controll.add(&powerThread); // & to pass the pointer to it
	controll.add(&resultThread);
}

void loop(){
	// run ThreadController
	// this will check every thread inside ThreadController,
	// if it should run. If yes, he will run it;
	controll.run();

	Serial.print("I'm looking for sensors: ");
	Serial.println(1029203213 - 13213213);
	delay(2500);
}