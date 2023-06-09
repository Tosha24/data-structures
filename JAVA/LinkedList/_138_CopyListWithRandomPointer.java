/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null){
            return head;
        }
        
        Node temp = head;
        while(temp != null){
            Node newNode = new Node(temp.val);
            newNode.next = temp.next;
            temp.next = newNode;
            temp = newNode.next;
        }

        temp = head;
        while(temp != null){
            if(temp.random != null){
                temp.next.random = temp.random.next;
            }
            else{
                temp.next.random = null;
            }
            temp = temp.next.next;
        }

        temp = head;
        Node front = temp.next.next;
        Node newHead = temp.next;
        while(front != null){
            temp.next.next = front.next;
            temp.next = front;
            temp = front;
            front = front.next.next;
        }
        temp.next.next = null;
        temp.next = null;
        return newHead;
    }
}