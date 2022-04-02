import java.io.*;
import java.util.Scanner;
//По набору ключей постройте бинарное поисковое дерево и выполните его прямой левый обход.
public class Main implements Runnable{
    @Override
    public void run() {
        BinaryTree tree= null;
        try {
            tree = new BinaryTree();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try (Scanner sc= new Scanner(new File("input.txt"))){
            while(sc.hasNext()){
                tree.add(sc.nextInt());
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        tree.traversePreOrder();
    }

    private static class BinaryTree {
        private BinaryTree() throws IOException {
            writer=new PrintWriter(new FileWriter("output.txt"));
        }

        private class Node {
            private int value;
            private Node left;
            private Node right;

            Node(int value) {
                this.value = value;
                right = null;
                left = null;
            }
        }

        Node root;
        PrintWriter writer;

        private Node addRecursive(Node current, int value) {
            if (current == null) {
                return new Node(value);
            }
            int compare = Integer.compare(value,current.value);
            if (compare<0) {
                current.left = addRecursive(current.left, value);
            } else if (compare>0) {
                current.right = addRecursive(current.right, value);
            }
            return current;
        }

        public void add(int value) {
            root = addRecursive(root, value);
        }

        private void traversePreOrderRecursive(Node node) {
            if (node != null) {
                writer.println(node.value);
                traversePreOrderRecursive(node.right);
                traversePreOrderRecursive(node.left);

            }
        }
        public void traversePreOrder() {
            traversePreOrderRecursive(root);
            writer.close();
        }

    }
    public static void main(String[] args) {
	// write your code here
        new Thread(null, new Main(), "", 64 * 1024 * 1024).start();
    }
}
