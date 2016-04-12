class solution {
public:
	//Push element x to the back of queue
	void push(int x) {
		s1.push(x);//push to the first stack
	}

	//Removes the element from in front of queue
	void pop(void) {
		if(s2.empty()) {//if the second stack is empty, then move everything in s1 to s2
			while(!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		s2.pop();
	}

	//Get the front element
	int peek(void) {
		if(s2.empty()) {
			while(!s1.empty()) {
				s2.push(s2.top());
				s1.pop();
			}
		}
		return s2.top();
	}

	//Return whether the queue is empty
	bool empty(void) {
		return s1.empty() && s2.empty();//if two stacks are all empty
	}
private:
	stack<int> s1, s2;
};
