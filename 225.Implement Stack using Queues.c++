class solution {
public:
	//Push element x onto stack
	void push(int x) {//every time push a new element ,q keep the order
		queue<int> temp;
		while(!q.empty()) {//move every element in q to temp
			temp.push(q.front());
			q.pop();
		}
		q.push(x);//push x
		while(!temp.empty()) {//move every element in temp to q
			q.push(temp.front());
			temp.pop();
		}
	}

	//Removes the element on top of the stack
	void pop() {
		q.pop();
	}

	//Get the top element
	int top() {
		return q.front();
	}

	//Return whether the stack is empty
	bool empty() {
		return q.empty();
	}
private:
	queue<int> q;
};
