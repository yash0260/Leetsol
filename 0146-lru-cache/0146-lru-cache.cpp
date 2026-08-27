class LRUCache {
    
public:
class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
     Node* head;
    Node* tail;

    // key -> address of Node
    unordered_map<int, Node*> m;

    int limit;

    LRUCache(int capacity) {
        limit = capacity;

        // Dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
      void addNode(Node* newNode) {

        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }
     void deNode(Node* delNode) {

        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
          if (m.find(key) == m.end()) {
            return -1;
        }

        // Get the node
        Node* ansNode = m[key];

        int ans = ansNode->val;

        // This node is now recently used
        m.erase(key);
        deNode(ansNode);
        addNode(ansNode);

        // Update its position in map
        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
         if (m.find(key) != m.end()) {

            Node* oldNode = m[key];

            // Remove old node
            deNode(oldNode);
            m.erase(key);

            // Delete memory
            delete oldNode;
             }

        // If cache is full
        if (m.size() == limit) {

            // LRU node is just before tail
            Node* lruNode = tail->prev;

            // Remove it from map
            m.erase(lruNode->key);

            // Remove it from linked list
            deNode(lruNode);

            // Free memory
            delete lruNode;
        }
        Node* newNode = new Node(key, value);

        // Add it to front = most recently used
        addNode(newNode);

        // Store in map
        m[key] = newNode;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */