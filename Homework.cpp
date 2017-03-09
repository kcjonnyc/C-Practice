// Homework
// Using the idea of a linked list to store homework assignments

#include <iostream>
#include "Homework.h"

using namespace std;

// queue variable is essentially the head - we are passing pointer by reference
bool enqueue(const Assignment* assignment, HomeworkQueue* &queue) {
	// check if the assignment has a valid date (does not account for different number of days in different months)
	if (assignment->dueMonth < 1 || assignment->dueDay < 1 || assignment->dueMonth > 12 || assignment->dueDay > 31) {
		return false;
	}
	else {
		int count = 0;
		while (count < 12 && assignment->course[count] != '\0') {
			count++;
		}
		if (assignment->course[count] != '\0')
			return false;
		else if (count == 0) {
			return false;
		}
	}
	// create and initialize HomeworkQueue (linked list)
	HomeworkQueue* temp = new HomeworkQueue;
	temp->next = NULL;
	temp->assgn = assignment;
	if (queue == NULL) {
		queue = temp;
	}
	else if (assignment->dueMonth < queue->assgn->dueMonth || (assignment->dueMonth == queue->assgn->dueMonth && assignment->dueDay < queue->assgn->dueDay)) {
		// it is the earliest thing to be due
		temp->next = queue;
		queue = temp;
	}
	else {
		// we need to loop through and find the position to insert
		HomeworkQueue* current = queue->next; // need to initialize to NULL or we get a segmentation fault
											  // after an event is enqueued, it will be pointing to some random memory address and not null
		HomeworkQueue* last = queue;
		while (current != NULL && current->assgn->dueMonth < assignment->dueMonth) {
			// we want to find the first node where the months match
			last = current;
			current = current->next;
		}
		// we now have the first node with the current month
		int month = assignment->dueMonth;
		// continue through loop but only in the correct month
		while (current != NULL && (current->assgn->dueMonth == month) && (current->assgn->dueDay <= assignment->dueDay)) {
			last = current;
			current = current->next;
		}
		// when we exit, we are a. at the end, b. past the last item in the particular month or c. past the date to insert
		// insert between last and current
		last->next = temp;
		temp->next = current;
	}
	return true;
}

// dequeue function
const Assignment* dequeue(HomeworkQueue* &queue) {
	if (queue == NULL) {
		return NULL;
	}
	const Assignment* temp = queue->assgn;
	queue = queue->next;
	return temp;
}
