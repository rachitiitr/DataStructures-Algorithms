
// ? =============   WITHOUT   HASH-MAP    =============

import java.util.*;
import javafx.util.Pair; //? ***

// !    NOTE :  while using this don'toverride the equals()&hashCode()method in Node Class
class Node {
    int val;
    Node left, right;

    Node(int val) {
        this.val = val;
        left = right = null;
    }
}

class IterativeMagic {

    public static void traversalTrick(Node root) { // ! inorder

        Stack<Pair<Node, Integer>> s = new Stack<Pair<Node, Integer>>();
        s.push(new Pair<>(root, 0));

        while (!s.empty()) {
            Pair<Node, Integer> p = s.pop();
            Node curNode = p.getKey();
            int state = p.getValue();

            if (curNode == null || state == 3) {
                continue;
            }

            s.push(new Pair<>(curNode, state + 1)); // new State

            switch (state) {
                case 0:
                    s.push(new Pair<>(curNode.left, 0));
                    break;
                case 1:
                    System.out.print(curNode.val + " ");
                    break;
                case 2:
                    s.push(new Pair<>(curNode.right, 0));
                    break;
            }
        }
    }
}

public class IterativeTreeTraversal_JAVA_2 {

    public static void main(String... args) {
        Node t = new Node(7);
        Node root = t;

        t.left = new Node(3);
        t.right = new Node(10);
        t.left.left = new Node(2);
        t.left.right = new Node(5);
        t.left.left.left = new Node(1);
        t.right.left = new Node(8);
        t.right.right = new Node(12);

        IterativeMagic.traversalTrick(root);
    }
}
