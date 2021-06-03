/*
	A simple but overly complex calculator of min OS schedule time
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define TASKS_SIZE 6
#define TASK_DELAY 0
#define THREADS_SIZE 26


struct thread {
	uint32_t timer;	
	uint32_t taskCount;
};

struct thread myThreads[THREADS_SIZE + 1]; // 0 is the idle thread

void threadsInit(struct thread * myThreads, int myThreadsSize, char *tasks, int tasksSize) {
	for(int i = 0; i < myThreadsSize + 1; i ++) {
		(myThreads + myThreadsSize)->timer = 0;
		(myThreads + myThreadsSize)->taskCount = 0;
	}
	for(int j = 0; j < tasksSize; j++) {
		(myThreads + (*(tasks + j) - '@'))->taskCount++;
	}
	return;
}

int startMaxThread(struct thread * myThreads, int timer) {
	int maxCount = 0;
	int maxCountIndex = 0;
	for(int i = 1; i < THREADS_SIZE + 1; i++) {
		if(myThreads[i].taskCount > maxCount && myThreads[i].timer == 0) {
			maxCount = myThreads[i].taskCount;
			maxCountIndex = i;
		}		
	}
	if(maxCountIndex > 0) {
        myThreads[maxCountIndex].taskCount--;
        myThreads[maxCountIndex].timer = timer + 1;
    }
	return maxCountIndex;
}

void decrementTimers(struct thread *myThreads, int tasksSize) {
	for(int i = 1; i < tasksSize + 1; i++) {
		if(myThreads[i].timer > 0) {
			myThreads[i].timer--;
		}
	} return;
}

void printTask(int taskNumber, int tasksSize) {
	if(tasksSize == 0) {
		printf("%c\n", '@' + taskNumber);
	} else {
		printf("%c -> ", '@' + taskNumber);
	}
}

int leastInterval(char* tasks, int tasksSize, int n){
	threadsInit(myThreads, THREADS_SIZE, tasks, tasksSize);
	int minTime = 0;
	int taskNumber = 0;
	while(tasksSize > 0) {
		taskNumber = startMaxThread(myThreads, n);
		if(taskNumber > 0) {
			tasksSize--;
        }
		decrementTimers(myThreads, THREADS_SIZE);
		minTime++;
		printTask(taskNumber, tasksSize);
	}
	return minTime;
}

int main() {
	int n = TASK_DELAY;
	char tasks[TASKS_SIZE] = { 'A', 'A', 'A', 'B', 'B', 'B'};

	printf("\nTasks are: ");
	for(int i = 0; i < TASKS_SIZE; i++) {
		printf("%c ", tasks[i]);
	}
	printf("\n");

	printf("\nSchedule is: ");
	int leastTime = leastInterval(tasks, TASKS_SIZE, n);
	printf("\nLeast time for this OS scheduler with delay %d between repeat tasks is: %d\n\n", n, leastTime);
	return 0;
}