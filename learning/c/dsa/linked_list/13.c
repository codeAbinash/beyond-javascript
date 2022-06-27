int main() {
    struct node *head, *temp, *lastN;
    head = temp = NULL;

    insertBeginning(10,&head);
    insertBeginning(15,&head);
    insertBeginning(20,&head);
    display(head);

    insertEnd(55,&head);
    insertEnd(58,&head);
    display(head);

    insertAtIndex(24,2,&head)    ;
    display(head);

    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteIndex(3,&head);
    display(head);


    head = reverse(head);
    display(head);
    
    printf("Total Items : %d\n",countList(head));

    return 0;
}
