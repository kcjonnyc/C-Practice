#include <iostream>
#include "eventQueue.h"

using namespace std;

struct Node {
	// the actual data held by the node
	const Event* event;
	// the reference to the next node in linked list
	// it is initialized to NULL
	Node* next = NULL;
};

struct LinkedList {
	Node* head = NULL;
	Node* tail = NULL;
	int eventCount = 0;
};

LinkedList eventList;

bool enqueue(const Event* e) {
	if (e->time < 0) { // we cannot have negative time
		return false;
	}
	Node* temp = new Node; // create a new node
	temp->event = e; // the event is e
	if (eventList.head == NULL) {
		// head is null, this is our first event
		eventList.head = temp; // this node is head and tail
		eventList.tail = temp;
	}
	else if (e->time >= eventList.tail->event->time) {
		// this has the longest time so as a priority queue,
		// this event should be added to the end 
		// Note: we also know that the head is not null
		eventList.tail->next = temp;
		eventList.tail = temp;
	}
	else if (e->time < eventList.head->event->time) {
		// this has the shortest time so as a priority queue,
		// this event should be the new head
		// Note: we also know that the head is not null
		temp->next = eventList.head;
		eventList.head = temp;
	}
	else {
		// event needs to be inserted somewhere in the
		// middle of the list
		// loop through the entire list and find the location to insert
		Node* current = eventList.head->next;
		Node* last = eventList.head;
		while (current != NULL && current->event->time <= e->time) {
			// transverse through linked list until current is greater than current node time
			last = current;
			current = current->next;
		}
		// as current node time is now > current node time, new node needs to be inserted
		// between last node and current node
		last->next = temp;
		temp->next = current;
	}
	eventList.eventCount++;
	return true;
}

const Event* dequeue() {
	if (eventList.head == NULL) {
		return NULL;
	}
	// else we want to dequeue the head
	// remove the head from linked list and return the event pointer
	Node* temp = eventList.head;
	eventList.head = eventList.head->next;
	return temp->event;
}