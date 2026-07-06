class LRUCache {
   private:
    struct Node {
        int key, val;
        Node *next, *prev;

        Node(int k, int v) {
            key = k;
            val = v;
        }
    };

    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void insert_after_head(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

   public:
    unordered_map<int, Node*> mp; 
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        remove(node);
        insert_after_head(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert_after_head(node);
            return;
        }

        if (mp.size() == cap) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            remove(lru);
            delete lru;
        }

        Node* node = new Node(key, value);
        insert_after_head(node);
        mp[key] = node;
        return;
    }
};
