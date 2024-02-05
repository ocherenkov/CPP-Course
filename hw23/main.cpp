#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <map>
#include <stack>

class Node {
public:
    int data;
    Node* next;

    Node(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    void push_front(int data)
    {
        Node* node = new Node(data);

        if (head != nullptr)
        {
            node->next = head;
        }

        head = node;
    }

    void popFront() {}

private:
    Node* head = nullptr;
};

// Node1 -> Node2 -> Node1 -> true
// Node1 -> Node2 -> Node3 -> false
bool has_cycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

unsigned int uniqueWordsCount(const std::string& line) {
    // TODO for versatility, add cast to lower/upper case
    std::set<std::string> uniqueWords;
    std::stringstream str(line);

    std::string word;
    while (str >> word) {
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}

std::string mostOccurredWord(const std::string& line) {
    // TODO for versatility, add cast to lower/upper case
    std::map<std::string, int> wordCount;
    std::stringstream str(line);

    std::string word;
    while (str >> word) {
        wordCount[word]++;
    }

    std::string occuredWord;
    int maxCount = 0;
    for (const auto& pair : wordCount) {
        if (pair.second > maxCount) {
            occuredWord = pair.first;
            maxCount = pair.second;
        }
    }

    return occuredWord;
}

bool isBalanced(const std::string& line) {
    std::stack<char> bracketsStack;

    for (char bracket : line) {
        if (bracket == '{' || bracket == '[' || bracket == '(') {
            bracketsStack.push(bracket);
        } else if (bracket == '}' || bracket == ']' || bracket == ')') {
            if (bracketsStack.empty()) {
                return false;
            }

            char top = bracketsStack.top();
            bracketsStack.pop();

            if ((bracket == '}' && top != '{') ||
                (bracket == ']' && top != '[') ||
                (bracket == ')' && top != '(')) {
                return false;
            }
        }
    }

    return bracketsStack.empty();
}

void task1() {
    std::cout << std::endl << "[TASK 1]" << std::endl;

    std::string line = "Hello Hey Hello Bye Hey";
    unsigned int uniqueWords = uniqueWordsCount(line);

    std::cout << "Words: " << line << std::endl;
    std::cout << "Count of unique words: " << uniqueWords << std::endl;

    std::cout << std::endl;
}

void task2() {
    std::cout << std::endl << "[TASK 2]" << std::endl;

    std::string line = "Can you can a can as a canner can can a can?";
    std::string occuredWord = mostOccurredWord(line);

    std::cout << "Words: " << line << std::endl;
    std::cout << "Most occurred word: " << occuredWord << std::endl;

    std::cout << std::endl;
}

void task3() {
    std::cout << std::endl << "[TASK 3]" << std::endl;

    std::string line1 = "{ [()][ ] }()";
    std::string line2 = "[{]}";

    bool isBalanced1 = isBalanced(line1);
    bool isBalanced2 = isBalanced(line2);

    std::cout << "Are brackets \"" << line1 << "\" balanced? - " << std::boolalpha << isBalanced1 << std::endl;
    std::cout << "Are brackets \"" << line2 << "\" balanced? - " << std::boolalpha << isBalanced2 << std::endl;

    std::cout << std::endl;
}

void task4() {
    std::cout << std::endl << "[TASK 4]" << std::endl;

    Node* node1 = new Node(5);
    Node* node2 = new Node(5);
    Node* node3 = new Node(5);

    node1->next = node2;
    node2->next = node3;

    bool hasCycle1 = has_cycle(node1);

    node3->next = node1; //OOPS, cycle is formed

    bool hasCycle2 = has_cycle(node1);

    std::cout << "Detected cycle - " << std::boolalpha << hasCycle1 << std::endl;
    std::cout << "Detected cycle - " << std::boolalpha << hasCycle2 << std::endl;

    std::cout << std::endl;
}

int main()
{
    // task1
    task1();
    // task2
    task2();
    // task3
    task3();
    // task4
    task4();
}