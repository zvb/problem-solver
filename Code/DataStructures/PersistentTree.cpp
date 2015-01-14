

struct Node {
    Node* left, right;
    int sum;
    Node(): left(0), right(0), sum(0) {}
    
};

typedef Node* pNode;

Node* get_node(Pnode & v) {
    if (!v) v = new Node();
    return v;
}