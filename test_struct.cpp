#include <iostream>

using namespace std;

static int index = 0;

struct Node {
    Node() {
        cout << "Node" << endl;
    }
    ~Node() {
        cout << "~Node" << endl;
    }
};

Node node11;

void test_node(Node& node) {
    node = node11;
}

int main() {
    Node node;
    test_node(node);
    return 0;
}