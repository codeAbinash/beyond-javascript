int main() {
    struct node *head, *tail;
    int listLength = 0;
    head = tail = NULL;

    insertEnd(10, &head, &tail, &listLength);
    insertEnd(11, &head, &tail, &listLength);
    insertBeginning(100, &head, &tail, &listLength);
    insertEnd(40, &head, &tail, &listLength);
    insertEnd(19, &head, &tail, &listLength);
    insertEnd(1, &head, &tail, &listLength);
    insertAtPos(41,3,&head,&tail,&listLength);
    display(head);
    printf("Reversed : ");
    reverse(&head, &tail);
    display(head);
    deleteEnd(&head,&tail,&listLength);
    display(head);
    deleteIndex(2,&head,&tail,&listLength);
    display(head);

    return 0;
}