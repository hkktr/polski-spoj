// C++14 (gcc 8.3)
#include <array>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>

void PrintStack(std::stack<int>& stack) {
  if (stack.empty()) {
    std::cout << "empty\n";
  } else {
    std::stack<int> temp;
    while (!stack.empty()) {
      temp.push(stack.top());
      stack.pop();
    }

    while (!temp.empty()) {
      std::cout << temp.top() << " ";
      stack.push(temp.top());
      temp.pop();
    }
    std::cout << "\n";
  }
}

void PrintQueue(std::queue<int> queue) {
  if (queue.empty()) {
    std::cout << "empty\n";
  } else {
    std::stack<int> temp;
    while (!queue.empty()) {
      temp.push(queue.front());
      queue.pop();
    }

    while (!temp.empty()) {
      std::cout << temp.top() << " ";
      temp.pop();
    }
    std::cout << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::array<std::unique_ptr<std::stack<int>>, 10> stacks;
  std::array<std::unique_ptr<std::queue<int>>, 10> queues;

  std::string command;
  while (std::cin >> command) {
    if (command == "new_s") {
      std::size_t i;
      std::cin >> i;

      stacks[i] = std::make_unique<std::stack<int>>();
    } else if (command == "push") {
      std::size_t i;
      int e;
      std::cin >> i >> e;

      if (stacks[i]->size() == 10) {
        std::cout << "error: stack is full\n";
      } else {
        stacks[i]->push(e);
      }

    } else if (command == "pop") {
      std::size_t i;
      std::cin >> i;

      if (stacks[i]->empty()) {
        std::cout << "error: stack is empty\n";
      } else {
        stacks[i]->pop();
      }
    } else if (command == "stack->stack") {
      std::size_t i, j;
      std::cin >> i >> j;

      if (stacks[i]->empty() || stacks[j]->size() == 10) {
        std::cout << "error: wrong command\n";
      } else {
        stacks[j]->push(stacks[i]->top());
        stacks[i]->pop();
      }
    } else if (command == "delete_s") {
      std::size_t i;
      std::cin >> i;

      stacks[i].reset();
    } else if (command == "print_s") {
      std::size_t i;
      std::cin >> i;

      PrintStack(*stacks[i]);
    } else if (command == "new_q") {
      std::size_t i;
      std::cin >> i;

      queues[i] = std::make_unique<std::queue<int>>();
    } else if (command == "enqueue") {
      std::size_t i;
      int e;
      std::cin >> i >> e;

      if (queues[i]->size() == 10) {
        std::cout << "error: queue is full\n";
      } else {
        queues[i]->push(e);
      }
    } else if (command == "dequeue") {
      std::size_t i;
      std::cin >> i;

      if (queues[i]->empty()) {
        std::cout << "error: queue is empty\n";
      } else {
        queues[i]->pop();
      }
    } else if (command == "delete_q") {
      std::size_t i;
      std::cin >> i;

      queues[i].reset();
    } else if (command == "print_q") {
      std::size_t i;
      std::cin >> i;

      PrintQueue(*queues[i]);
    } else if (command == "stack->queue") {
      std::size_t i, j;
      std::cin >> i >> j;

      if (stacks[i]->empty() || queues[j]->size() == 10) {
        std::cout << "error: wrong command\n";
      } else {
        queues[j]->push(stacks[i]->top());
        stacks[i]->pop();
      }
    } else if (command == "queue->queue") {
      std::size_t i, j;
      std::cin >> i >> j;

      if (queues[i]->empty() || queues[j]->size() == 10) {
        std::cout << "error: wrong command\n";
      } else {
        queues[j]->push(queues[i]->front());
        queues[i]->pop();
      }
    } else if (command == "queue->stack") {
      std::size_t i, j;
      std::cin >> i >> j;

      if (queues[i]->empty() || stacks[j]->size() == 10) {
        std::cout << "error: wrong command\n";
      } else {
        stacks[j]->push(queues[i]->front());
        queues[i]->pop();
      }
    }
  }

  return 0;
}