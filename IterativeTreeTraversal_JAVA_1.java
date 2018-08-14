
// ? =============   USING   HASH-MAP    =============

import java.util.*;

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

    public static void traversalTrick(Node root) { // postorder

        HashMap<Node, Integer> state = new HashMap<Node, Integer>();
        Stack<Node> s = new Stack<Node>();
        s.push(root);

        while (!s.empty()) {
            Node curNode = s.peek();

            if (curNode == null) {
                s.pop();
                continue;
            }

            int curState;
            if (!state.containsKey(curNode))// if no state exits till now - give it a state 0
                state.put(curNode, 0);

            curState = state.get(curNode);

            switch (curState) {
                case 0:
                    s.push(curNode.left);
                    break;
                case 1:
                    s.push(curNode.right);
                    break;
                case 2:
                    System.out.print(curNode.val + " ");
                    break;
                default:
                    s.pop();
            }

            state.put(curNode, curState + 1); // change its current state : previous state's task done
        }
    }

}

public class IterativeTreeTraversal_JAVA_1 {

    public static void main(String... args) {
        Node tmp = new Node(7);
        Node root = tmp;

        root.left = new Node(3);
        root.right = new Node(10);
        root.left.left = new Node(2);
        root.left.right = new Node(5);
        root.left.left.left = new Node(1);
        root.right.left = new Node(8);
        root.right.right = new Node(5);

        IterativeMagic.traversalTrick(tmp);
    }
}
