void insert_at_any_pos(Node* &head, Node* &tail, int idx, int val) {
    
    if (idx == 0) {
        insert_at_head(head, tail, val);
        return;
    }

    
    Node* newnode = new Node(val);
    Node* tmp = head;

    
    for (int i = 1; i < idx; ++i) {
        if (tmp == NULL || tmp->next == NULL) {
            cout << "Invalid index" << endl;
            delete newnode; 
            return;
        }
        tmp = tmp->next;
    }


    if (tmp->next == NULL) {
        tail = newnode;
    }


    newnode->next = tmp->next;
    tmp->next = newnode;
}
